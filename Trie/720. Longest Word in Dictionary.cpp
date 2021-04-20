// Template for Trie questions
// Source: Leetcode Solution

/*
Usage:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
    
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

class Solution {
public:
    string ans = "";
    void dfs(string& temp, Trie* trie){
        for(int i = 0;i<26;i++){
            if(trie->children[i]!=nullptr && trie->children[i]->isEnd){
                temp.push_back(i+'a'); 
                if(temp.size()>ans.size() || (temp.size()==ans.size() && temp.compare(ans)<0)) ans = temp;   
                dfs(temp,trie->children[i]);
                temp.pop_back();
            }    
        }
    }
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto w : words){
            trie.insert(w);    
        }
        string temp = "";
        dfs(temp,&trie);
        return ans;
    }
};
