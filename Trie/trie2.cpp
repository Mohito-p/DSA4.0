#include <bits/stdc++.h> 
using namespace std;

struct Node {
    Node *links[26];
    int cw = 0; // Count of words ending at this node
    int cp = 0; // Count of prefixes passing through this node

    bool containkey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cw++;
    }

    void increasePrefix() {
        cp++;
    }

    void deleteEnd() {
        cw--;
    }

    void reducePrefix() {
        cp--;
    }

    int getEnd() {
        return cw;
    }

    int getPrefix() {
        return cp;
    }
};

class Trie {
private: 
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containkey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containkey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEnd(); // Return the count of words ending here
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containkey(word[i])) {
                node = node->get(word[i]); // Update node pointer
            } else {
                return 0;
            }
        }
        return node->getPrefix(); // Return the count of prefixes passing here
    }

    void erase(string &word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containkey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            } else {
                return; // Word doesn't exist in the Trie
            }
        }
        node->deleteEnd();
    }
};
