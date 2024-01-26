#!/usr/bin/python3
"""
Python script that sends a request to the URL and
   displays the value of a variable in the response header
"""


if __name__ == '__main__':
    from requests import get
    from sys import argv

    repo = argv[1]
    owner = argv[2]
    a = 0

    URL = "https://api.github.com/repos/{}/{}/commits".format(owner, repo)

    response = get(URL)
    json = response.json()

    for element in json:
        if a > 9:
            break
        sha = element.get('sha')
        author = element.get('commit').get('author').get('name')
        print("{}: {}".format(sha, author))
        a += 1
