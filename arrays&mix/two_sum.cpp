#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
/*Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> d;
        
        for (int i=0; i<nums.size(); i++){
            d[nums[i]] = i;
        }
        
        for(int j=0; j<nums.size(); j++){
            auto it = d.find(target - nums[j]);
            if ( it == d.end() ) {
              continue;
            } 
            else if(it->second != j){
                ans.push_back(j);
                ans.push_back(it->second);
                return ans;
                }
            else{
                continue;
            }
            
        }
        
        return ans;
    }
};