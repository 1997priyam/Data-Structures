/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numRotation = k % nums.size();
        if (numRotation > 0) {
            vector<int> temp;
            int arrSize = nums.size();
            for (int i=0; i<arrSize; i++) {
                if (i+numRotation <= arrSize) temp.push_back(nums[(i+numRotation)%arrSize]);
                if (i>=numRotation){
                    nums[(i+numRotation)%arrSize] = temp[i-numRotation];
                } else {
                    nums[(i+numRotation)%arrSize] = nums[i];
                }
            }
        }
    }
};