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
//Space Complexity: O(1)
//Technique: Traverses each string once, deleting every #
//Time taken to solve: Around 12 mins
bool backspace_string_compare(string s1, string s2){
    int start1=0;
    int start2=0;
    while(start1<s1.length()-1){
        if(s1[start1+1]=='#'){
            s1.erase(s1.begin()+start1+1, s1.begin()+start1+2);
            s1.erase(s1.begin()+start1, s1.begin()+start1+1);
            if(start1>0)
                start1--;
        }
        else
            start1++;

        if(start1>=s1.length())
            break;
    }
    while(start2<s2.length()-1){
        if(s2[start2+1]=='#'){
            s2.erase(s2.begin()+start2+1, s2.begin()+start2+2);
            s2.erase(s2.begin()+start2, s2.begin()+start2+1);
            if(start2>0)
                start2--;
        }
        else
            start2++;

        if(start2>=s2.length())
            break;
    }

    if(s1.compare(s2)==0)
        return true;
    else
        return false;
}

int main() {
    cout<<backspace_string_compare("abcde", "abcde")<<endl;
    cout<<backspace_string_compare("Uber Career Prep", "u#Uber Careee#r Prep")<<endl;
    cout<<backspace_string_compare("abcdef###xyz", "abcw#xyz")<<endl;
    cout<<backspace_string_compare("abcdef###xyz", "abcdefxyz###")<<endl;
}