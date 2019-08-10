#!/usr/bin/python3
num = int(input("Enter a number: "))
count = 0
for i in range(num):
    for j in range(num):
        count += 1
        print(count, end=" ")
    print("")