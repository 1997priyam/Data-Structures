#include <iostream>
#include <vector>
#include <string>
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if(!curr->child[index]) curr->child[index] = new Node();
            curr = curr->child[index];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        return searchUtil(word, root);
    }
    
    bool searchUtil(string word, Node* root) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++) {
            if(word[i] != '.') {
                int index = word[i] - 'a';
                if(!curr->child[index]) return false;
                curr = curr->child[index];
            } else {
                for(auto node: curr->child) {
                    if(node && searchUtil(word.substr(i+1), node)) return true;
                }
                return false;
            }
        }
        return curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */