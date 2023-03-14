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
//Technique: Two-pointer catch-up
//Time taken to solve: Around 40 mins
//Comments: Really struggled with this in the start but was able to work through it
int shortest_substring(string s1, string s2){
    if(s2.length()>s1.length())
        return 0;
    unordered_map<char, int> mp1;
    int len = s2.size(), min = INT64_MAX, start = 0, end = 0;

    for(int i=0; i<len; i++)
        mp1[s2[i]]++;

    while(end<=s1.size() && start<s1.size()){
        if(len>0){
            if(end==s1.size())
                break;
            mp1[s1[end]]--;
            if(mp1[s1[end++]] >=0)
                len--;
        }
        else{
            if(end-start<min)
                min = end-start;

            mp1[s1[start]]++;
            if(mp1[s1[start++]]>0)
                len++;
        }
    }
    return min;
}

int main() {
    cout<<shortest_substring("dog", "god")<<endl;
    cout<<shortest_substring("abracadabra", "abc")<<endl;
    cout<<shortest_substring("zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx")<<endl;
}