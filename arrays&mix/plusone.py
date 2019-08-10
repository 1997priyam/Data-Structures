class Solution:
    # @param A : list of integers
    # @return a list of integers
    
    def plusOne(self, A):
        num = ""
        for i in range(len(A)):
            num+=str(A[i])
        num = int(num) + 1
        num = str(num)
        B=[]
        for j in range(len(num)):
            B.append(int(num[j]))
        return B

        
obj = Solution()
obj.plusOne([3,1,2])