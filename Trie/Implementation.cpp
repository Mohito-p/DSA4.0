#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
  
    // Array for child nodes of each node
    TrieNode* child[26];

    // for end of word
    bool wordEnd;

    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

// Method to insert a key into the Trie
void insertKey(TrieNode* root, const string& key) {
  
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr) {
          
            // If node for current character does 
            // not exist then make a new node
            TrieNode* newNode = new TrieNode();
          
            // Keep the reference for the newly
            // created node
            curr->child[c - 'a'] = newNode;
        }
      
        // Move the curr pointer to the
        // newly created node
        curr = curr->child[c - 'a'];
    }

    // Mark the end of the word
    curr->wordEnd = true;
}

// Method to search a key in the Trie
bool searchKey(TrieNode* root, const string& key) {
  
    // Initialize the curr pointer with the root node
    TrieNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->child[c - 'a'] == nullptr) 
            return false;
        
        // Move the curr pointer to the 
        // already existing node for the 
        // current character
        curr = curr->child[c - 'a'];
    }

    // Return true if the word exists 
    // and is marked as ending
    return curr->wordEnd;
}

int main() {
  
    // Create am example Trie
    TrieNode* root = new TrieNode();
    vector<string> arr = 
      {"and", "ant", "do", "geek", "dad", "ball"};
    for (const string& s : arr) {
        insertKey(root, s);
    }

    // One by one search strings
    vector<string> searchKeys = {"do", "gee", "bat"};
    for (string& s : searchKeys) {
        cout << "Key : " << s << "\n";
        if (searchKey(root, s)) 
            cout << "Present\n";
        else 
            cout << "Not Present\n";        
    }
  
    return 0;
}
//leetcode Code example

struct Node {
    Node *links[26];
    bool flag = false;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() { // No need to return anything here
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd(); // Check if the node is marked as the end of a word
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
