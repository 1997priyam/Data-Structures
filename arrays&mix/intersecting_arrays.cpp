/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *shortArr, *longArr;
        if(nums1.size() < nums2.size()) {
            shortArr = &nums1;
            longArr = &nums2;
        } else {
            shortArr = &nums2;
            longArr = &nums1;
        }
        
        unordered_map<int, int> dict;
        for (int num : *longArr) {
            if (isKeyPresent(dict, num)) {
                dict[num] += 1;
            } else {
                dict[num] = 1;
            }
        }
        
        vector<int> result;
        
        for(int num : *shortArr) {
            if(isKeyPresent(dict, num)) {
                if(dict[num] > 0){
                    dict[num] -= 1;
                    result.push_back(num);
                }
            }
        }
        return result;
    }
    
    bool isKeyPresent(unordered_map<int, int> &dict, int key) {
        if (dict.find(key) == dict.end()) return false;
        else return true;
    }
};