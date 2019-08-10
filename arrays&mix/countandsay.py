"""
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
"""
def countAndSay(A):
    num = "1"
    for i in range(A-1):
        count = 0
        prev = num[0]
        new_num = ""
        for j in range(len(num)):
            if num[j] == prev:
                count+=1
            else:
                new_num = new_num + str(count) + prev
                prev = num[j]
                count = 1
            if j == len(num)-1:
                new_num = new_num + str(count) + prev
        num = new_num
    return num

a = int(input("Enter a number: "))
print(countAndSay(a))
