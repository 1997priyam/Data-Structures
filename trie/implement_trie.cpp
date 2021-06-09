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

class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = this->root;
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if(!curr->child[index]) curr->child[index] = new Node();
            curr = curr->child[index];
        }
        curr->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = this->root;
        for(int i=0; i<word.length(); i++) {
            int index = word[i] - 'a';
            if(!curr->child[index]) return false;
            curr = curr->child[index];
        }
        if(curr->end) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = this->root;
        for(int i=0; i<prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if(!curr->child[index]) return false;
            curr = curr->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */