"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/k-th-distinct-element/0

Description: Given an array of N integers, write a program to print K-th distinct
element in the array. The given array may contain duplicates and the
output should print K-th element among all unique elements. If K is
more than number of distinct elements, print -1.
"""

T = int(input())

for _ in range(T):
	n, k = list(map(int, input().rstrip().split(' ')))
	l = list(map(int, input().rstrip().split(' ')))
	blacklist = []
	
	n = 0
	for i in range(len(l)):
		if l[i] in blacklist:
			continue
		if l[i] in (l[:i]+l[i+1:]):
			blacklist.append(l[i])
			continue
		if n == k-1:
			print(l[i])
			break
		n += 1

	if n < k-1:
		print(-1)