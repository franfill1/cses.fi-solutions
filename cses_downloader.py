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
    cses_id: int | None = None
    task_id: int | None = None
    task_name: str | None = None
    sender: int | None = None
    timestamp: int | None = None
    language: str | None = None
    result: str | None = None
    code: str | None = None

    def __init__(self, cses_id: int):
        self.cses_id = cses_id

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

        return self

    def to_string(self):
        prefix = "/*\n"
        prefix += f"Task:              {self.task_id} {self.task_name}\n"
        prefix += f"Sender:            {self.sender}\n"
        date = datetime.fromtimestamp(self.timestamp)
        date_string = date.strftime(cses_date_format)
        prefix += f"Submission time:   {date_string}\n"
        prefix += f"Language:          {self.language}\n"
        prefix += f"Result:            {self.result}\n"
        prefix += "/*\n"
        body = prefix + self.code
        return body.replace("\r\n", "\n")


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


def get_user_id() -> int:
    r = s.get("https://cses.fi/")
    html_doc = r.text
    soup = BeautifulSoup(html_doc, "html.parser")
    user_link = soup.find("a", class_="account")["href"]
    return int(user_link.split("/")[-1])


def save_last_sol(task_id: int):
    url = f"https://cses.fi/problemset/task/{task_id}"
    r = s.get(url)
    html_doc = r.text
    soup = BeautifulSoup(html_doc, "html.parser")

    title = soup.h1.string
    category = soup.find("div", class_="nav sidebar").contents[1].string

    subs_href_regex = re.compile(r"^\/problemset\/result\/\d+\/$")
    subs = soup.find_all("a", href=subs_href_regex)
    sols = [sub for sub in subs if "full" in sub.span["class"]]
    last_sol = sols[0]
    last_sol_id = int(last_sol["href"].split("/")[-2])
    code = Submission(last_sol_id).download().to_string()

    filename = f"{category}/{title}/{title}.cpp"
    os.makedirs(os.path.split(filename)[0], exist_ok=True)
    print(f"{category} / {task_id} - {title}")
    with open(filename, "w") as file:
        file.write(code)


def get_solved_tasks():
    r = s.get("https://cses.fi/problemset/")
    html_doc = r.text
    soup = BeautifulSoup(html_doc, "html.parser")
    tasks = soup.find_all("li", class_="task")
    solved_tasks = [task for task in tasks
                    if "full" in task.find("span", class_="icon")["class"]]
    tasks_ids = [int(task.a["href"].split("/")[-1]) for task in solved_tasks]
    return tasks_ids


if __name__ == "__main__":
    login(input("Username: "), getpass.getpass())
    for id in get_solved_tasks():
        save_last_sol(id)
