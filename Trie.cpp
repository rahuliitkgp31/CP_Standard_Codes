class Node {
public:
    char c;
    unordered_map<char, Node*> children;
    bool isTerminal;
    Node(char x) {
        c = x;
        isTerminal = false;
    }
};

class Trie {
public:
    Node* root;
    int size;
    Trie() {
        root = new Node('\0');
        size = 0;
    }
    void insert(string s) {
        Node* temp = root;
        for (int i = 0; i < s.size(); i++) {
            if (temp->children.find(s[i]) != temp->children.end()) {
                temp = temp->children[s[i]];
            }
            else {
                Node* newNode = new Node(s[i]);
                temp->children[s[i]] = newNode;
                temp = newNode;
            }
        }
        temp->isTerminal = true;
        size++;
    }
    bool find(string s) {
        Node* temp = root;
        for (int i = 0; i < s.size(); i++) {
            if (temp->children.find(s[i]) == temp->children.end()) {
                return false;
            }
            else {
                temp = temp->children[s[i]];
            }
        }
        return temp->isTerminal;
    }
};
