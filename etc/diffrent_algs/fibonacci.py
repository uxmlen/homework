# -*- coding: utf-8 -*-
# vim: ts=4 sw=4 tw=88 et ai si

"""
"""

def fib_rec(n: int) -> int:
    if n in {0, 1}:
        return n
    return fib_rec(n - 1) + fib_rec(n - 2)

def fib_iter(n: int) -> int:
    if n in {0, 1}:
        return n
    first, second = 0, 1
    for _ in range(2, n + 1):
        first, second = first, first + second
    return second
