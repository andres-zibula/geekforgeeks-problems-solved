"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0

Description: Given an even number ( greater than 2 ), return two prime numbers whose sum will
be equal to given number. There are several combinations possible. Print only first such pair. 

NOTE: A solution will always exist, read Goldbach’s conjecture.
"""

inputs = input()
primes = [n for n in range(2,10001) if all(n % i != 0 for i in range(2, n))]

def print_sum_prime(n):
    for x in primes:
        for y in primes:
            if x + y == n:
                print(str(x) + ' ' + str(y))
                return

for i in range(0, int(inputs)):
    number = int(input())
    print_sum_prime(number)
    #too slow
    #out = [[x,y] for x in primes for y in primes if x+y== number][0]
    #print(' '.join([str(out[0]), str(out[1])]))
