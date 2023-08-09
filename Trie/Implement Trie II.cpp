#include <bits/stdc++.h> 

struct Node {
    Node * links[26];
    int wordCount = 0;
    int substrCount = 0;
};

class Trie{

    public:
    Node * root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) {
                node->links[x-'a'] = new Node();
            }
            node = node->links[x-'a'];
            node->substrCount++;
        }
        node->wordCount++;
    }

    int countWordsEqualTo(string &word){
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) return 0;
            node = node->links[x-'a'];
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string &word){
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) return 0;
            node = node->links[x-'a'];
        }
        return node->substrCount;
    }

    void erase(string &word){
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) return;
            node = node->links[x-'a'];
            node->substrCount--;
        }
        node->wordCount--;
    }
};
