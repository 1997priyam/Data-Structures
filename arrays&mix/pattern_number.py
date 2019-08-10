#! /usr/bin/python3
num = int(input("Enter a number: "))
arr = []
for i in range(num):
    arr_new = []
    for j in range(i+1):
        if j==0 or j==i:
            arr_new.append(1)
        else:
            temp = arr[j] + arr[j-1]
            arr_new.append(temp)
    print(arr_new)
    arr = arr_new[:]