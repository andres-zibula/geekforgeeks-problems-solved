"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/twisted-prime-number/0

Description: A number is said to be twisted prime if it is a prime number and reverse of the number is also a prime number.
"""

import math

def isPrime(n):
	return all(n % i != 0 for i in range(2, math.floor(math.sqrt(n))+1))

T = int(input())

for _ in range(T):
    n = int(input())

    if isPrime(n) and isPrime(int(str(n)[::-1])):
    	print("Yes")
    else:
    	print("No")