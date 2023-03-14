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
//Time taken to solve: Around 12 mins
int two_sum(vector<int> nums, int k){
    assert(nums.size()>0);
    int c=0;
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        if(mp.find(k-nums[i])!=mp.end()){
            c=c+mp[k-nums[i]];
            mp[k-nums[i]]--;
        }
    }
    return c;
}

int main(){
    cout<<two_sum({1, 10, 8, 3, 2, 5, 7, 2, -2, -1}, 10)<<endl;
    cout<<two_sum({1, 10, 8, 3, 2, 5, 7, 2, -2, -1}, 9)<<endl;
    cout<<two_sum({4, 3, 3, 5, 7, 0, 2, 3, 8, 6}, 6)<<endl;
    cout<<two_sum({4, 3, 3, 5, 7, 0, 2, 3, 8, 6}, 1)<<endl;
}