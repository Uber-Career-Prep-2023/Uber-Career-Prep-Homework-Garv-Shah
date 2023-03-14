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
//Technique: Hashing
//Time taken to solve: Around 15 mins
int zero_sum_sub_arrays(vector<int> nums){
    assert(nums.size()>0);
    unordered_map<int, int>mp;
    int sum=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        mp[sum]++;
    }
    for(auto &i:mp){
        if(i.first==0)
            ans++;
        if(i.second>1)
            ans=ans+i.second-1;
    }
    return ans;
}

int main() {
    cout<<zero_sum_sub_arrays({8, -5, 0, -2, 3, -4})<<endl;
    cout<<zero_sum_sub_arrays({4, 5, 2, -1, -3, -3, 4, 6, -7})<<endl;
    cout<<zero_sum_sub_arrays({1, 8, 7, 3, 11, 9})<<endl;
}