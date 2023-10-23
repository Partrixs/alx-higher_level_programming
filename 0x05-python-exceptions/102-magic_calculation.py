#!/usr/bin/python3
def magic_calculation(a, b):
    result = 0
    for it in range(1, 3):
        try:
            if it > a:
                raise Exception('Too far')
            result += a ** b / it
        except Exception:
            result += b + a
            break
    return result
