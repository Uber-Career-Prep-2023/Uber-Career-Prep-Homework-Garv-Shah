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
//Technique: Simply traverses array once and keeps deleting elements the already exist
//Time taken to solve: Around 10 mins
vector<int> dedup_array(vector<int> nums){
    assert(nums.size()>0);
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            nums.erase(nums.begin()+i+1, nums.begin()+i+2);
            i--;
        }
    }
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return nums;
}

int main(){
    dedup_array({1, 2, 2, 3, 3, 3, 4, 4, 4, 4});
    cout<<endl;
    dedup_array({0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15});
    cout<<endl;
    dedup_array({1, 3, 4, 8, 10, 12});
}