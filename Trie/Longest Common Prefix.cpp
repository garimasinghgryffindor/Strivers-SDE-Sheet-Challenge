// USING TRIE
struct Node {
    Node * links[26];
    bool flag = false;
    int charChildren = 0;
};

class Trie {
    public:
    Node * root;
    Trie() { root = new Node(); }
    void insert(string word) {
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) {
                node->links[x-'a'] = new Node();
                node->charChildren++;
            }
            node = node->links[x-'a'];
        }
        node->flag = true;
    }

    int searchLCP(string anyWord) {
        Node * node = root;
        int idx = 0;
        while(node) {
            if(node->charChildren == 1) {
                node = node->links[anyWord[idx]-'a'];
                idx++;
            } else {
                break;
            }
        }

        return idx;
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie trie;
    for(auto x: arr) {
        trie.insert(x);
    }

    int LCPLength = trie.searchLCP(arr[0]);

    return arr[0].substr(0, LCPLength);
}


