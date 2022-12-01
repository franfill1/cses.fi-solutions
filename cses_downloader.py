import requests
import urllib
from bs4 import BeautifulSoup
import re
from datetime import datetime
import html
import os
import getpass

s = requests.session()

cses_date_format = "%Y-%m-%d %H:%M:%S"


class Submission:
    downloaded: bool = False
    cses_id: int
    status: str | None
    task_id: int | None
    task_name: str | None
    sender: int | None
    timestamp: int | None
    language: str | None
    result: str | None
    code: str | None

    def __init__(self, cses_id: int, timestamp: int | None = None,
                 status: int | None = None):
        self.cses_id = cses_id
        self.timestamp = timestamp
        self.status = status

    def download(self):
        url = f"https://cses.fi/problemset/result/{self.cses_id}"
        soup = BeautifulSoup(s.get(url).text, "html.parser")
        table = soup.find("table", class_="summary-table")
        rows = table.find_all("tr")

        task = rows[0].contents[1]
        self.task_id = int(task.a["href"].split("/")[-2])
        self.task_name = str(task.a.string)

        self.sender = str(rows[1].contents[1].string)

        date_string = str(rows[2].contents[1].string)
        date = datetime.strptime(date_string, cses_date_format)
        self.timestamp = datetime.timestamp(date)

        self.language = str(rows[3].contents[1].string)
        status = str(rows[4].contents[1].string)

        if (status == "READY"):
            self.result = str(rows[5].contents[1].string)
        else:
            self.result = status

        code = str(soup.find("pre", class_="prettyprint").string)
        self.code = html.unescape(code)

        self.downloaded = True
        return self

    def to_string(self):
        if not self.downloaded:
            self.download()
        prefix = "/*\n"
        prefix += f"Task:              {self.task_id} {self.task_name}\n"
        prefix += f"Sender:            {self.sender}\n"
        date = datetime.fromtimestamp(self.timestamp)
        date_string = date.strftime(cses_date_format)
        prefix += f"Submission time:   {date_string}\n"
        prefix += f"Language:          {self.language}\n"
        prefix += f"Result:            {self.result}\n"
        prefix += "*/\n"
        body = prefix + self.code
        return body.replace("\r\n", "\n")


class Task:
    downloaded: bool = False
    cses_id: int | None
    status: str | None
    title: str | None
    category: str | None
    time_limit: float | None
    memory_limit: int | None
    submissions: list[Submission, int, str] | None

    def __init__(self, cses_id: str, title: str | None = None,
                 status: str | None = None):
        self.cses_id = cses_id
        self.status = status
        self.title = title

    def download(self):
        url = f"https://cses.fi/problemset/task/{self.cses_id}"
        soup = BeautifulSoup(s.get(url).text, "html.parser")

        self.title = str(soup.h1.string)

        sidebar = soup.find("div", class_="nav sidebar")
        self.category = sidebar.contents[1].string

        constraints = soup.find("ul", class_="task-constraints")\
            .find_all("li")
        self.time_limit = float(constraints[0].contents[1].split()[0])
        self.memory_limit = int(constraints[1].contents[1].split()[0])

        subs_href_regex = re.compile(r"^\/problemset\/result\/\d+\/$")
        submissions_tags = soup.find_all("a", href=subs_href_regex)

        def parse_sub(tag) -> tuple[Submission, int, str]:
            sub_id = int(tag["href"].split("/")[-2])
            date_string = str(tag.contents[0]).strip()
            date = datetime.strptime(date_string, cses_date_format)
            timestamp = datetime.timestamp(date)
            result = ""
            if "full" in tag.span["class"]:
                result = "ACCEPTED"
            elif "compile-err" in tag.span["class"]:
                result = "COMPILATION ERROR"
            elif "zero" in tag.span["class"]:
                result = "ZERO"
            return Submission(sub_id, timestamp, result)

        self.submissions = [parse_sub(tag) for tag in submissions_tags]
        self.submissions = sorted(self.submissions, key=lambda x: x.timestamp)

        self.downloaded = True
        return self

    def get_solutions(self):
        if not self.downloaded:
            self.download()
        return [sub for sub in self.submissions if sub.status == "ACCEPTED"]

    def get_last_solution(self):
        if not self.downloaded:
            self.download()
        return self.get_solutions()[-1]

    def get_first_solution(self):
        if not self.downloaded:
            self.download()
        return self.get_solutions()[0]


def login(username: str, password: str):
    r = s.get("https://cses.fi/login")
    html_doc = r.text
    soup = BeautifulSoup(html_doc, "html.parser")
    csrf_token = soup.find("input", type="hidden")["value"]
    params = urllib.parse.urlencode(
            {'csrf_token': csrf_token, 'nick': username, 'pass': password})
    headers = {"Content-Type": "application/x-www-form-urlencoded"}
    url = "https://cses.fi/login"

    r = s.post(url, headers=headers, data=params)
    if len(re.findall("Invalid username or password", r.text)) > 0:
        raise Exception("Invalid username or password")


def get_tasks() -> list[Task]:
    r = s.get("https://cses.fi/problemset/")
    html_doc = r.text
    soup = BeautifulSoup(html_doc, "html.parser")
    tasks_tags = soup.find_all("li", class_="task")

    def parse_task(tag) -> tuple[Task, str, str]:
        task_id = tag.a["href"].split("/")[-1]
        title = str(tag.a.string)
        icon = tag.find("span", class_="icon")
        status = ""
        if "full" in icon["class"]:
            status = "ACCEPTED"
        elif "zero" in icon["class"]:
            status = "ZERO"
        return Task(task_id, title, status)

    tasks = [parse_task(tag) for tag in tasks_tags]
    return tasks


if __name__ == "__main__":
    login(input("Username: "), getpass.getpass())
    solved_tasks = [task for task in get_tasks() if task.status == "ACCEPTED"]
    for task in solved_tasks:
        task.download()
        code = task.get_last_solution().download().to_string()
        filename = f"{task.category}/{task.title}/{task.title}.cpp"
        os.makedirs(os.path.split(filename)[0], exist_ok=True)
        print(f"{task.category} / {task.cses_id} - {task.title}")
        with open(filename, "w") as file:
            file.write(code)
