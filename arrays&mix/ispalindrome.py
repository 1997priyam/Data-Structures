import re
def isPalindrome(A):
    st = ''.join(ch for ch in A if ch.isalnum())
    st = st.lower()
    length = len(st)
    for i in range(int(length/2)):
        if st[i] != st[length-i-1]:
            return 0
    return 1
    

print(isPalindrome("A man, a plan, a canal: 0Panama"))