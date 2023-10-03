#!/usr/bin/python3
def uppercase(str):
    for q in str:
        if ord("a") <= ord(q) <= ord("z"):
            q = chr(ord(q) - 32)
        print("{:s}".format(q), end="")
    print()
