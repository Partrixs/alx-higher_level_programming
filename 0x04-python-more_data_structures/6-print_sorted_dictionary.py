#!/usr/bin/python3
def print_sorted_dictionary(a_dictionary):
    x = sorted(a_dictionary)
    for a in x:
        print("{}: {}".format(a, a_dictionary[a]))
