/*
Given an array nums, write a function to move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroCounter = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                nums[nonZeroCounter] = nums[i];
                nonZeroCounter++;
            }
        }
        
        for(int i=nonZeroCounter; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};