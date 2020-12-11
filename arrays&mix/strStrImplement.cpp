/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/

#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int needleLength = needle.length();
        int haystackLength = haystack.length();
        if (needleLength == 0) return 0;
        
        for(int i=0; i<(haystackLength - needleLength) + 1; i++) {
            if(haystack[i] == needle[0]) {
                bool flag = false;
                for(int j=0, k=i; j<needleLength; j++, k++) {
                    if (needle[j] != haystack[k]) break;
                    if (needle[j] == haystack[k] && j == needleLength-1) flag = true;
                }
                if (flag) return i;
            }
        }
        
        
        return index;
    }
};