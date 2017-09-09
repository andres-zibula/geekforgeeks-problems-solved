"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/check-arithmetic-progression/0

Description: Given an array of N integers. Write a program to check whether an arithmetic
progression can be formed using all the given elements. If possible print “YES”, else print “NO”.
"""

def isProgression(x):
	if len(x) > 1:
		n = x[1] - x[0]

	for i in range(len(x)-1):
		if x[i] + n != x[i+1]:
			return False

	return True

T = int(input())

for _ in range(T):
	n = int(input())
	x = list(map(int, input().rstrip().split(' ')))
	x = sorted(x)

	if isProgression(x):
		print("YES")
	else:
		print("NO")