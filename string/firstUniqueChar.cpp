#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            if(isKeyPresent(map, s[i])){
                map[s[i]] += 1;
            } else {
                map[s[i]] = 1;
            }
        }
        
        for(int i=0; i<s.length(); i++) {
            if(map[s[i]] == 1) return i;
        }
        return -1;
    }
    
    bool isKeyPresent(const unordered_map<char,int> &map, const char ch){
        if(map.find(ch) == map.end()) return 0;
        return 1;
    }
};