#!/usr/bin/python3
num = int(input("Enter a number: "))
for i in range(num,-1,-1):
    for j in range(i):
        print("", end=" ")
    for k in range(num-i+1):
        print(k, end="")
    for l in range(num-i-1,-1,-1):
        print(l, end="")
    print("")