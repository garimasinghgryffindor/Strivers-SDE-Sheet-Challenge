struct Node {
    Node *links[26];
    bool flag = false;
};

class Trie {

public:
    Node * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) {
                node->links[x-'a'] = new Node();
            }
            node = node->links[x-'a'];
        }
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) return false;
            node = node->links[x-'a'];
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node = root;
        for(char x: prefix) {
            if(!node->links[x-'a']) return false;
            node = node->links[x-'a'];
        }
        return true;
    }
};



// using TRIE and DFS
struct Node {
    Node * links [26];  
    bool flag = false;
};
class Solution {
public:
    Node * root;
    
    void insert(string word) {
        int n = word.length();
        Node * node = root;
        for(int i = 0; i < n; i++) {
            if(!node->links[word[i]-'a']) {
                node->links[word[i]-'a'] = new Node();
            }
            node = node->links[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool dfs(string word,Node * node, int index, int count) {
        if(index >= word.length()) { return count > 1; }
        
        int n = word.length();
        Node * curr = node;
        
        for(int i = index; i < n; i++) {
            if(!curr->links[word[i] - 'a']) { return false; }
            curr = curr->links[word[i]-'a'];
            if(curr->flag) {
                if(dfs(word,node,i+1,count+1)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        // using Trie
        root = new Node();
        
        for(auto s: words) {
            insert(s);
        }
        
        for(int i = 0; i < words.size(); i++) {
            bool ans = dfs(words[i], root, 0, 0);
            if(ans) res.push_back(words[i]);
        }
        
        return res;
    }
};



