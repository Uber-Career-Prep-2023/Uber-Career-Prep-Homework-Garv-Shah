// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void generateCatalanNumbers(int n){
    if(n==0){
        cout<<1<<endl;
        return;
    }
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        for(int x=0; x<i; x++){
            dp[i] = dp[i] + dp[x]*dp[i-x-1];
        }
    }

    for(int i=0; i<=n; i++){
        cout<<dp[i]<<endl;
    }

}

void testCase1(){
    cout<<"testCase 1"<< endl;
    generateCatalanNumbers(1);
    // 1, 1
}

void testCase2(){
    cout<<"testCase 2"<< endl;
    generateCatalanNumbers(5);
    // 1, 1, 2, 5, 14, 42
}

int main() {
    testCase1();
    testCase2();
    return 0;
}


