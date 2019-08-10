class Solution:
    # @param A : string
    # @return a list of integers
    def flip(self, A):
        flag = False
        total = 0
        ans = []
        for i in A:
            if i=="0":
                flag = True
                break
        if not flag:
            return ans
        for i in range(len(A)):
            for j in range(len(A)):
                tl = [i+1, j+1]
                temp = self.zto(tl, A)
                if temp>total:
                    ans = tl
                    total = temp
        return ans
    def zto(self, l, A):
        B = list(A)
        for i in range(l[0]-1, l[1]):
            if B[i] == "0":
                B[i] = "1"
            else:
                B[i] = "0"
        count = 0
        for i in B:
            if i == "1":
                count += 1
            else:
                pass
        return count
obj = Solution()
A= "000000001110"
print(obj.flip(A))