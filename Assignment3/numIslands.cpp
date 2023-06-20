#include <iostream>
#include <vector>

using namespace std;

// Time Complexity: O(R*C)
// Space Complexity: O(1)
// Time taken to complete: Around 20 mins

int MAX_ROWS;
int MAX_COLS;

bool dfs(vector<vector<int>> &graph, int r , int c);

int main() {
    cout << "enter number of rows" << endl;
    cin >> MAX_ROWS;
    cout << "enter number of columns" << endl;
    cin >> MAX_COLS;
    cout << "enter data as 0s ans 1s" << endl;
    vector<vector<int>> graph(MAX_ROWS, vector<int>(MAX_COLS));
    for(int i=0; i<MAX_ROWS; i++){
        for(int j=0; j<MAX_COLS; j++){
            int val;
            cin >> val; // input of matrix
            graph[i][j] = val;
        }
    }

    int num = 0;

    for(int i=0; i<MAX_ROWS; i++){
        for(int j=0; j<MAX_COLS; j++){
            if(dfs(graph, i, j))
                num++;
        }
    }

    cout << "number of islands = " << num;
    return 0;
}

bool dfs(vector<vector<int>> &graph, int r, int c){
    if(r<0 || c<0 || r>=MAX_ROWS || c>=MAX_COLS) // check if r and c are in bounds
        return false;

    if(graph[r][c] == 0 || graph[r][c]==2) // if node is 0 or has been visited return false
        return false;

    graph[r][c] = 2; // set the visited nodes to 2

    // call dfs on the 4 adjacent nodes
    dfs(graph, r - 1, c);
    dfs(graph, r + 1, c);
    dfs(graph, r, c - 1);
    dfs(graph, r, c + 1);

    return true;
}