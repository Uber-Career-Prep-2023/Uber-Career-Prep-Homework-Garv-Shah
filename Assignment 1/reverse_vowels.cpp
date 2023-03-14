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
bool is_vowel(char &i);

//Time Complexity: O(n)
//Space Complexity: O(1)
//Technique: Forward-Backward Two-Pointer
//Time taken to solve: Around 15 mins
string reverse_vowels(string s){
    assert(s.length()>0);
    int start=0;
    int end=s.size()-1;
    while(start<end){
        if(!is_vowel(s[start]))
            start++;
        if(!is_vowel(s[end]))
            end--;
        if(is_vowel(s[start]) && is_vowel(s[end])){
            char a=s[start];
            s[start]=s[end];
            s[end]=a;
            start++;
            end--;
        }
    }
    return s;
}

bool is_vowel(char &a){
    if(a=='a' || a=='e' || a=='i' || a=='u' || a=='o'
    || a=='A' || a=='E' || a=='I' || a=='U' || a=='O')
        return true;
    else
        return false;
}

int main() {
    cout<<reverse_vowels("Uber Career Prep")<<endl;
    cout<<reverse_vowels("xyz")<<endl;
    cout<<reverse_vowels("flamingo")<<endl;
}