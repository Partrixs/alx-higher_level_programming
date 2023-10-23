#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    num = 0
    try:
        while num is not x:
            print(my_list[num], end="")
            num += 1
    except IndexError:
        None
    print()
    return num
