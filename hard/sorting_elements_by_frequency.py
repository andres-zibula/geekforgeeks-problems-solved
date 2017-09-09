"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

Description: Given an array of integers, sort the array according to frequency of elements.
For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify
the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. 

If frequencies of two elements are same, print them in increasing order.
"""

T = int(input())

for _ in range(T):
    n = int(input())
    d = {}
    x = list(map(int, input().rstrip().split(' ')))

    for i in range(n):
        if x[i] in d: d[x[i]] += 1
        else: d[x[i]] = 1
    
    d2 = {}
    for k,v in d.items():
        if v in d2: d2[v] += [k]
        else: d2[v] = [k]
    
    keys = list(d2.keys())
    keys.sort(reverse=True)
    
    s = ""
    for i in keys:
        l = sorted(d2[i])
        for j in l:
            for k in range(i):
                s += str(j) + ' '
    s = s[:-1]
    print(s)
    