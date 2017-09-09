"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Description: Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
"""

T = int(input())

for _ in range(T):
    n = int(input())
    x = list(map(int, input().rstrip().split(' ')))
    
    max1 = max2 = x[0]
    for i in range(1, n):
        max1 = max(x[i], x[i] + max1)
        max2 = max(max1, max2)
    
    print(max2)