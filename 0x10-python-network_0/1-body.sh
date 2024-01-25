#!/bin/bash
# A Bash script that takes in a URL, sends a GET request and displays only the  body of a status code response(200)
curl -Ls "$1"
