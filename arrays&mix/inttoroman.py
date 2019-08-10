def romanToInt(A):
    ans = ""
    rem = int(A/1000)
    for i in range(rem):
        ans += "M"
    A = A%1000

    rem = int(A/100)
    if rem == 9:
        ans+="CM"
    elif rem >= 5:
        ans+="D"
        for i in range(rem-5):
            ans+="C"
    elif rem == 4:
        ans+="CD"
    else:
        for i in range(rem):
            ans+="C"

    A = A%100
    rem = int(A/10)
    if rem == 9:
        ans+="XC"
    elif rem >= 5:
        ans+="L"
        for i in range(rem-5):
            ans+="X"
    elif rem == 4:
        ans+="XL"
    else:
        for i in range(rem):
            ans+="X"

    A = A%10
    rem = int(A/1)
    if rem == 9:
        ans+="IX"
    elif rem >= 5:
        ans+="V"
        for i in range(rem-5):
            ans+="I"
    elif rem == 4:
        ans+="IV"
    else:
        for i in range(rem):
            ans+="I"

    return ans
n = int(input("Enter a number: "))
print(romanToInt(n))