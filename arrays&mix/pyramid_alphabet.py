#!/usr/bin/python3
num = int(input("Enter a number: "))
for i in range(num, -1, -1):
    for k in range(num-i):
        print("", end=" ")
    for j in range(i):
        print(chr(65+j), end="")
    for l in range(i-1, -1, -1):
        print(chr(65+l), end="")
    print("")