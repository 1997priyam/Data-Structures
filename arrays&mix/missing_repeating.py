class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        l = [0]*len(A)
        missing=None
        repeating = None
        ans = []
        for i in range(len(A)):
            l[A[i]-1] = l[A[i]-1] + 1
        for i in range(len(A)):
            if l[i] == 0:
                missing = i+1
            elif l[i] == 2:
                repeating = i+1
            else:
                pass
        ans.append(repeating)
        ans.append(missing)
        
        return ans
A = (3,1,4,5,3)
obj = Solution()
print("Answer is :", obj.repeatedNumber(A))
