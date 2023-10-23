#!/usr/bin/python3
def safe_print_list_integers(my_list=[], x=0):
    it, ct = 0, 0
    while it < x:
        try:
            print("{:d}".format(my_list[it), end="")
            ct += 1
        except (ValueError, TypeError):
            pass
        it += 1
    print()
    Return ct
