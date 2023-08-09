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
