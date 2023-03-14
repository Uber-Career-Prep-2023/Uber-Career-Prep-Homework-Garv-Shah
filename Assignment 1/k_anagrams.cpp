#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//Time Complexity: O(n)
//Space Complexity: O(n)
//Technique: Hashing elements
//Time taken to solve: Around 15 mins
bool k_anagrams(string s1, string s2, int k){
    assert(s1.length()>0 && s2.length()>0);
    if(s1.length()!=s2.length())
        return false;
    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;
    for(int i=0;i<s1.length();i++){
        mp1[s1[i]]++;
        mp2[s2[i]]++;
    }
    int c=0;
    for(auto &i:mp1){
        if(mp2.find(i.first)!=mp2.end()){
            c=c+abs(mp2[i.second]-mp1[i.second]);
            mp2.erase(i.first);
        }
    }
    if(!mp2.empty()){
        for(auto &i:mp2){
            c=c+i.second;
        }
    }
    if(c<=k)
        return true;
    else
        return false;
}

int main() {
    cout<<k_anagrams("apple", "peach", 1)<<endl;
    cout<<k_anagrams("apple", "peach", 2)<<endl;
    cout<<k_anagrams("cat", "dog", 3)<<endl;
    cout<<k_anagrams("debit curd", "bad credit", 1)<<endl;
    cout<<k_anagrams("baseball", "basketball", 2)<<endl;
}