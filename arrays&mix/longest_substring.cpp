#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lookup;
        int max = 0;
        int size = s.length();
        for(int i=0; i<size; i++){
            if(size-i<=max) break;
            for(int j=i; j<size; j++){
                if(keyExists(s[j], lookup)){
                    break;
                }
                else{
                    lookup[s[j]] = 1;
                }
                
            }
            
            int len = lookup.size();
            if(len>max) max = len;
            lookup.clear();     //empty lookup
        }
        
        return max;
    }
    
    bool keyExists(char &key, unordered_map<char, int> &lookup){
        if(lookup.find(key) == lookup.end()) return false;
        else return true;
    }
};