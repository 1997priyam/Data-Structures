stri = input ("Enter a string: ")
li = stri.split(" ")
length = len(li)
count = int(length/2)
for i in range(count):
    temp = li[length-1-i]
    li[length-1-i] = li[i]
    li[i] = temp
stri = " ".join(li)
print(stri)

# Reversing a string by swapping indexes
