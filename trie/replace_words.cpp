// n English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"


#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    bool end;
    Node* child[26];
    
    Node() {
        end = false;
        for(int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
    Node* root;
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new Node();
        for(int i=0; i<dict.size(); i++) {
            insert(root, dict[i]);
        }
        vector<string> sentArr = splitBySpace(sentence);
        
        for(int i=0; i<sentArr.size(); i++) {
            string sub = search(root, sentArr[i]);
            if(sub.length() > 0) sentArr[i] = sub;
        }
        
        return joinBySpace(sentArr);
        
    }
    
    void insert(Node* root, string key) {
        Node* curr = root;
        for(int i=0; i<key.length(); i++) {
            int index = key[i] - 'a';
            if(!curr->child[index]) curr->child[index] = new Node();
            curr = curr->child[index];
        }
        curr->end = true;
    }
    
    vector<string> splitBySpace(string sentence) {
        int start = 0, i;
        vector<string> ans;
        for(i=0; i<sentence.length(); i++) {
            if(sentence[i] == ' ') {
                ans.push_back(sentence.substr(start, i-start));
                start = i+1;
            }
        }
        ans.push_back(sentence.substr(start, i-start));
        return ans;
    }
    
    string search(Node* root, string key) {
        Node* curr = root;
        string ans = "";
        for(int i=0; i<key.length(); i++) {
            int index = key[i] - 'a';
            if(!curr->child[index]) break;
            if(curr->child[index]->end == true) {
                ans = key.substr(0, i+1);
                break;
            }
            curr = curr->child[index];
        }
        return ans;
    }
    
    string joinBySpace(vector<string> arr) {
        string ans = "";
        for(string word: arr) {
            ans = ans + word + " ";
        }
        return ans.substr(0, ans.length()-1);
    }
};