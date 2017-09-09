"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/bitonic-generator-sort/0

Description: Given an array of n distinct numbers, the task is to sort all even-placed numbers
in increasing and odd-place numbers in decreasing order. The modified array should
contain all sorted even-placed numbers followed by reverse sorted odd-placed numbers.
Note that the first element is considered as even because of its index 0.
"""

T = int(input())

for _ in range(T):
    n = int(input())
    x = list(map(int, input().rstrip().split(' ')))
    asc = sorted(x[::2])
    desc = sorted(x[1::2], reverse=True)
    print(" ".join(map(str, asc + desc)))