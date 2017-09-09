"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/adam-number/0

Description: Given a number N, write a program to check whether given number is Adam Number or not.
Adam number is a number when reversed, the square of the number and the square of the
reversed number should be numbers which are reverse of each other. Adam numbers upto 1000
are: 0, 1, 2, 3, 11, 12, 13, 21, 22, 31, 101, 102, 103, 111, 112 , 113, 121, 122, 201,
202, 211, 212, 221, 301, 311.
"""

def isAdam(n):
	reverse = int(str(n)[::-1])
	if(n**2 == int(str(reverse**2)[::-1])):
		return True
	else:
		return False

T = int(input())

for _ in range(T):
    n = int(input())
    if isAdam(n):
    	print("YES")
    else:
    	print("NO")