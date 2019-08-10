#! /usr/bin/python3

num = int(input("Enter a number: "))

for i in range(int(num/2)):
    for k in range(i):
        print("", end="  ")
    for j in range(i+1):
        print("*", end=" ")
    print("")

for i in range(int(num/2),-1,-1):
    for k in range(i):
        print("", end="  ")
    for j in range(i+1):
        print("*", end=" ")
    print("")