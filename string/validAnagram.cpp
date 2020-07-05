#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> map;
        for(int i=0; i<s.length(); i++){
            if(isKeyPresent(map, s[i])) map[s[i]]++;
            else map[s[i]] = 1;
        }
        
        for(int i=0; i<t.length(); i++) {
            if(isKeyPresent(map, t[i])){
                if(map[t[i]] == 0) return false;
                else map[t[i]]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    bool isKeyPresent(unordered_map<char, int> map, const char ch) {
        if (map.find(ch) == map.end()) return 0;
        return 1;
    }
};