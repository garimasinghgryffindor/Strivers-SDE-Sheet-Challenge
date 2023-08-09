
struct Node {
    Node * links[26];
    bool flag = false;
};

class Trie {
    public:
    Node * root;
    Trie() { root = new Node(); }
    void insert(string&word) {
        Node * node = root;
        for(char x: word) {
            if(!node->links[x-'a']) {
                node->links[x-'a'] = new Node();
            }
            node = node->links[x-'a'];
        }
        node->flag = true;
    }

    bool search(string&word) {
        Node * node = root;
        for(char x: word) {
            node = node->links[x-'a'];
            if(!node->flag) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    string mx;
    Trie trie;
    for(auto x: a) {
        trie.insert(x);
    }

    for(auto x: a) {
        if(trie.search(x)) {
            if(mx.length() < x.length())
                mx = x;
            else if(mx.length() == x.length()) {
                if(x < mx) {
                    mx = x;
                }
            }
        }
    }

    if(mx == "") return "None";

    return mx;
}


