/*
Given a sorted array nums, remove the duplicates in-place such that 
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying 
the input array in-place with O(1) extra memory.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0, size = nums.size();
        while(i<size-1){
            if(nums[i]==nums[i+1]) nums.erase(nums.begin()+i), size--;
            else i++;
        }
            
        return nums.size();
    }
};