/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans(2, -1);
        for(int i=0; i<nums.size(); i++) {
            if(isKeyPresent(umap, target - nums[i])){
                    ans[0] = umap[target - nums[i]];
                    ans[1] = i;
                } else{
                    umap[nums[i]] = i;
            }
        }
        return ans;
    }
    
    bool isKeyPresent(unordered_map<int, int> &umap, int key){
        if(umap.find(key) == umap.end()) return false;
        return true;
    }
};