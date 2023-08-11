// Time Complexity: O(N)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

bool wordBreak(vector<string> dict, string input){
    unordered_set<string> dictionary;
    for(auto &i:dict){
        dictionary.insert(i);
    }
    if(dictionary.find(input)!=dictionary.end())
        return true;

    bool dp[input.size()+1];
    memset(dp, false, sizeof(dp));
    dp[input.size()]=true;
    string temp="";
    for(int i=input.size()-1; i>=0; i--){
        for(int j=i; j<input.size();j++){
            temp=temp+input[j];
            if(dictionary.find(temp)!=dictionary.end() && dp[j+1])
                dp[i]=true;
        }
        temp="";
    }
    return dp[0];

}

void testCase1(){
    cout<<"testCase 1"<< endl;
    vector<string> dict={"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};
    cout<<wordBreak(dict, "mangolf")<<endl; // 1
}

void testCase2(){
    cout<<"testCase 2"<< endl;
    vector<string> dict={"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};
    cout<<wordBreak(dict, "manateenotelf")<<endl; // 1
}

void testCase3(){
    cout<<"testCase 3"<< endl;
    vector<string> dict={"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};
    cout<<wordBreak(dict, "quipig")<<endl; // 0
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    return 0;
}
