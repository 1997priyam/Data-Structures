def simplifyPath(A):
    l = A.split("/")
    ans = []
    print(l)
    for var in l:
        if var=="..":
            if ans:
                ans.pop()
        elif var=="." or var=="":
            pass
        else:
            ans.append(var)
    if ans:
        k = "/"
        for i in ans:
            k = k+i+"/"
        return k[:-1]
    else: 
        return "/"
t = simplifyPath("/home//foo/")
print("ans:", t)

