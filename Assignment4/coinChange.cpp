// Time Complexity: O(M * N)
// Space Complexity: O(M * N)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int coinChange(vector<int> coins, int sum){

    int dp[coins.size()+1][sum+1];
    for(int i=0; i<coins.size()+1; i++){
        for(int j=0; j<sum+1; j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=coins.size();i++){
        dp[i][0]=1;
    }
    for(int i=1; i<coins.size()+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coins[i-1]<=j)
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[coins.size()][sum];
}

void testCase1(){
    cout<<"testCase 1"<< endl;
    vector<int> coins={2, 5, 10};
    cout<<coinChange(coins, 20)<<endl; // 6
}

void testCase2(){
    cout<<"testCase 2"<< endl;
    vector<int> coins={2, 5, 10};
    cout<<coinChange(coins, 15)<<endl; // 3
}

int main() {
    testCase1();
    testCase2();
    return 0;
}
