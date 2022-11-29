################################################################################
# Script Name   : cses_downloader
# Description   : download accepted solutions of cses.fi
# Author        : Lorenzo Ferrari
# Github        : https://github.com/lorenzo-ferrari/
################################################################################

import requests
import urllib
import getpass
import html
import os
import sys

def findInBetween(text, before, after):
    l = text.index(before) + len(before)
    r = text.index(after, l)
    return text[l:r]

def main(nick, password):
    """
    LOGIN
    """
    r = requests.get('https://cses.fi/login')
    PHPSESSID = r.headers['Set-Cookie'][:-8]

    csrf_token = findInBetween(r.text, '<input type="hidden" name="csrf_token" value="', '"')
    _params = urllib.parse.urlencode({ 'csrf_token' : csrf_token, 'nick' : nick, 'pass' : password})
    _headers = { 'Content-Type' : 'application/x-www-form-urlencoded' , 'Cookie' : PHPSESSID }

    login_failed = "Invalid username or password"
    r = requests.post('https://cses.fi/login', headers=_headers, data=_params)
    if r.text.find(login_failed) != -1:
        print("Invalid username or password")
        quit()

    """
    DOWNLOAD
    """
    r = requests.post('https://cses.fi/problemset', headers=_headers, data=_params)

    fullscore_icon = '<span class="task-score icon full">'
    task_prefix = '<li class="task"><a href="/problemset/task/'
    task_suffix = '</a>'
    solved = []
    tasks = r.text.split(task_prefix)[1:]
    for task in tasks:
        if task.find(fullscore_icon) != -1:
            prob_id = task[:4]
            prob_name = task[6:task.find(task_suffix)]
            solved.append((prob_id, prob_name))

    for (prob_id, prob_name) in solved:
        print(prob_id, "-", prob_name, ": downloading")
        r = requests.post('https://cses.fi/problemset/task/'+prob_id, headers=_headers, data=_params)
        category_prefix = '<div class="nav sidebar">\n<h4>'
        category_suffix = "</h4>"
        category = findInBetween(r.text, category_prefix, category_suffix)
        all_subs = r.text.split('\n')[-3].split('href="/problemset/result/')[1:]
        successful_subs = [sub[ : sub.find('/"')] for sub in all_subs if sub.find(fullscore_icon) != -1]
        if len(successful_subs) == 0:
            print('Something went wrong: can\'t find any fullscore submissions')
            quit()
        r = requests.post('https://cses.fi/problemset/result/'+successful_subs[0], headers=_headers, data=_params)
        code_prefix = '<pre class="prettyprint linenums resize-horizontal" style="">'
        code_suffix = '</pre></div></div><a href="/paste/'
        code = findInBetween(r.text, code_prefix, code_suffix) + '\n'
        code = html.unescape(code)
        filename = f'{category}/{prob_name}/{prob_name}.cpp'
        os.makedirs(os.path.split(filename)[0], exist_ok = True)
        with open(filename, 'w') as f:
            f.write(code)
        print(prob_id, "-", prob_name, ": download completed")

if __name__ == '__main__':
    main(input('Username: '), getpass.getpass())
