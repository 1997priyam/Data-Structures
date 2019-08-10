#! /usr/bin/python3

num = int(input("Enter a number: "))
def arrow_pattern(start=0, num=5):
    if start == int(num/2)+1:
        return 
    for k in range(start):
        print("", end="  ")
    for j in range(start+1):
        print("*", end=" ")
    print("")
    arrow_pattern(start+1, num)
    for k in range(start-1):
        print("", end="  ")
    for j in range(start):
        print("*", end=" ")
    print("")
arrow_pattern(start=0, num=num)