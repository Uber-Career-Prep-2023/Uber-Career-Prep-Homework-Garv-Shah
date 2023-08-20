#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode{
    vector<TrieNode*> children;
    bool valid;

    TrieNode(){
        children.resize(26, nullptr);
        valid = false;
    }
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(auto &i : word){
            if(!node -> children[i-'a']){
                node -> children[i-'a'] = new TrieNode();
            }
            node = node -> children[i-'a'];
        }
        node -> valid = true;
    }

    bool isValid(string word){
        TrieNode* node = root;
        for(auto &i : word){
            if(!node -> children[i-'a']){
                return false;
            }
            node = node -> children[i-'a'];
        }
        return node -> valid;
    }

    void remove(string word){
        removeHelper(root, word, 0);
    }

private:
    bool removeHelper(TrieNode* node, const string &word, int idx){
        if(idx == word.length()){
            if(!node -> valid){
                return false;
            }
            node -> valid = false;
            return node -> children.empty();
        }

        if(!node -> children[word[idx]-'a']){
            return false;
        }

        bool deletable = removeHelper(node -> children[word[idx]-'a'], word, idx+1);

        if(deletable){
            delete node -> children[word[idx]-'a'];
            node -> children[word[idx]-'a'] = nullptr;
            return node -> valid == false && node -> children.empty();
        }

        return false;
    }
};
