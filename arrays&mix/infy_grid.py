class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def coverPoints(self, A, B):
        count = 0
        for i in range(A[0]-1):
            x1 = A[i+1]
            y1 = B[i+1]
            diff_x = A[i+1] - A[i+2]
            diff_y = B[i+1] - B[i+2]
            if diff_x < 0:
                diff_x = diff_x*(-1)
            if diff_y < 0:
                diff_y = diff_y*(-1)
            if diff_x > diff_y:
                count += diff_x
            else:
                count += diff_y
        return count

obj = Solution()
A = [2,-7,-13]
B = [2,1,-5]
p = obj.coverPoints(A, B)
print(p)