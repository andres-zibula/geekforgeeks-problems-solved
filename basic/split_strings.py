"""
Author: Andres Zibula

Github: https://github.com/andres-zibula/geekforgeeks-problems-solved

Problem link: http://practice.geeksforgeeks.org/problems/split-strings/0

Description: Given a string S which consists of alphabets , numbers and special characters.
You need to write a program to split the strings in three different strings S1,
S2 and S3 such that the string S1 will contain all the alphabets present in S ,
the string S2 will contain all the numbers present in S and S3 will contain all
special characters present in S.
"""

inputs = input()

for i in range(0, int(inputs)):
    line = input()
    out = ["", "", ""]
    for s in line:
        if s.isalpha():
            out[0]+=s
        elif s.isdigit():
            out[1]+=s
        else:
            out[2]+=s
    
    print(out[0])
    print(out[1])
    print(out[2])