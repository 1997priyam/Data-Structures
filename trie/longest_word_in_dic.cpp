class trie {
  public:
    bool isEndOfWord;
    trie* children[26];
    
    trie() {
        isEndOfWord = false;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
    string ans = "";
public:
    string longestWord(vector<string>& words) {
        trie* root = new trie();
        for(string key: words) {
            insert(root, key);
        }
        for(string key: words) {
            if(dfs(root, key)) {
                if(key.length() > ans.length()) ans = key;
                else if(key.length() == ans.length()) {
                    if(key.compare(ans) < 0) ans = key;
                }
                else {}
            }
        }
        return ans;
        
    }
    
    bool dfs(trie* root, string key) {
        trie* curr = root;
        for(int i=0; i<key.length(); i++) {
            int index = key[i] - 'a';
            if(!curr->children[index]) return false;
            if(!curr->children[index]->isEndOfWord) return false;
            curr = curr->children[index];
        }
        return true;
    }
    
    void insert(trie* root, string key) {
        trie* curr = root;
        for(int i=0; i<key.length(); i++) {
            int index = key[i] - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new trie();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
};