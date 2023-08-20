#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
};

class BoggleSolver {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& dictionary) {
        Trie trie;
        for (string word : dictionary) {
            trie.insert(word);
        }

        int rows = board.size();
        int cols = board[0].size();
        vector<string> validWords;
        string path;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, path, trie.root, validWords);
            }
        }

        return validWords;
    }

private:
    void dfs(vector<vector<char>>& board, int row, int col, string& path, TrieNode* node, vector<string>& validWords) {
        if (node->isEndOfWord) {
            validWords.push_back(path);
            node->isEndOfWord = false; // Mark word as found to avoid duplicates
        }

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == ' ' || !node->children.count(board[row][col])) {
            return;
        }

        char curChar = board[row][col];
        path.push_back(curChar);
        board[row][col] = ' ';

        int dr[] = {-1, -1, 0, 1, 1, 1,  0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for(int i = 0; i < 8; i++){
            dfs(board, row + dr[i], col + dc[i], path, node->children[curChar], validWords);
        }

        board[row][col] = curChar;
        path.pop_back();
    }
};

int main() {
    vector<vector<char>> board = {
            {'a', 'd', 'e'},
            {'r', 'c', 'p'},
            {'l', 'a', 'y'}
    };
    vector<string> dictionary = {"ace",
            "ape",
            "cape",
            "clap",
            "clay",
            "gape",
            "grape",
            "lace",
            "lap",
            "lay",
            "mace",
            "map",
            "may",
            "pace",
            "pay",
            "rap",
            "ray",
            "tap",
            "tape",
            "trace",
            "trap",
            "tray",
            "yap",
            "race"
    };

    BoggleSolver solver;
    vector<string> validWords = solver.findWords(board, dictionary);

    for (const string& word : validWords) {
        cout << word << " ";
    }

    return 0;
}
