/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int arrLen = digits.size();
        bool flag = false;
        for (int i=arrLen-1; i>=0; i--) {
            if(digits[i] == 9){
                digits[i] = 0;
                if(i == 0) flag = true;
            } else {
                digits[i] += 1;
                break;
            }
        }
        if(flag) digits.insert(digits.begin(), 1);
        return digits;
    }
};