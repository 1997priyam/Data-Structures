/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int index = 0;
        bool flag = false;
        if(strs.size() == 0) return ans;
        while(1) {
            char current;
            
            for(int i=0; i<strs.size(); i++) {
                int maxSize = strs[i].length();
                if(index+1 > maxSize) {
                    flag = true;
                    break;
                }
                if(i==0) {
                    current = strs[i][index];
                } else {
                    if(strs[i][index] != current) {
                        flag = true;
                        break;
                    }
                }
                if(i == strs.size() - 1) {
                    ans += current;
                }
            }
            if (flag) break;
            index++;
        }
        return ans;
    }
};