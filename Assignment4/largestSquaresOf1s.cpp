// Time Complexity: O(N * M)
// Space Complexity: O(N * M)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSquaresOf1s(vector<vector<int>> matrix){
    int r=matrix.size();
    int c=matrix[0].size();
    int dp[r][c];
    for(int i=0; i<r; i++){
        for(int x=0; x<c; x++){
            if(i==r-1 || x==c-1)
                dp[i][x]=matrix[i][x];
            else
                dp[i][x]=0;
        }
    }
    int ans = 0;
    for(int i=r-2; i>=0; i--){
        for(int x=c-2; x>=0; x--){
            if(matrix[i][x])
                dp[i][x] = 1+min(dp[i][x+1], min(dp[i+1][x], dp[i+1][x+1]));
            else
                dp[i][x] = 0;
            ans = max(ans, dp[i][x]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix1={{0, 1, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}, {0, 0, 1, 1}};
    cout<<largestSquaresOf1s(matrix1)<<endl;
    vector<vector<int>> matrix2={{0, 1, 0, 1, 1}, {0, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 1, 0, 0}};
    cout<<largestSquaresOf1s(matrix2)<<endl;
    return 0;
}