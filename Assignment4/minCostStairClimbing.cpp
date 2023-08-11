// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int minCost(vector<int> cost){
    if(cost.size()==1)
        return cost[0];
    if(cost.size()==2)
        return min(cost[0], cost[1]);

    int dp[cost.size()];
    memset(dp, 0, sizeof(dp));
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2; i<cost.size(); i++){
        dp[i]=min((cost[i]+dp[i-1]), (cost[i]+dp[i-2]));
    }
    return min(dp[cost.size()-1], dp[cost.size()-2]);

}

void testCase1(){
    cout<<"testCase 1"<< endl;
    cout<<minCost({4, 1, 6, 3, 5, 8})<<endl;
}

void testCase2(){
    cout<<"testCase 2"<< endl;
    cout<<minCost({11, 8, 3, 4, 9, 13, 10})<<endl;
}

int main() {
    testCase1();
    testCase2();
    return 0;
}
