"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0

Description: Given an input stream of n integers the task is to insert integers to stream
and print the kth largest element in the stream at each insertion.
"""

from bisect import insort

T = int(input())

for _ in range(T):
    k, n = list(map(int, input().rstrip().split(' ')))
    x = list(map(int, input().rstrip().split(' ')))
    in_stream = []
    out_stream = []
    
    for i in range(n):
        insort(in_stream, x[i])
        out_stream.append(in_stream[-k] if len(in_stream) >= k else -1)

    print(' '.join(str(x) for x in out_stream))