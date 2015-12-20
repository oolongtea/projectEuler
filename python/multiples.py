#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
If we list all the natural numbers below 10 that are multiples of
3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""


def generate_multiples(targets, upperbound):
    """Returns numbers that are multiples of any of the targets and
    bound by upperbound."""
    i = 1
    while i < upperbound:
        if not all([i % target for target in targets]):
            yield i
        i += 1


def main():
    target_multiples = set([3, 5])
    upperbound = 1000

    results = sum(generate_multiples(target_multiples, upperbound))

    print("Sum of all the multiples of {0} below {1}:"
          "".format(target_multiples, upperbound))
    print(results)


if __name__ == '__main__':
    main()
