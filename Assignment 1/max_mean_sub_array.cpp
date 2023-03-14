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
//Technique: Sliding window with fixed size
//Time taken to solve: Around 20 mins
double max_mean_sub_array(vector<int> nums, double k){
    assert(nums.size()>0 && k>0);
    int curr_sum=0;
    int max_sum=0;
    int start=0;
    for(int i=0; i<nums.size(); i++){
        curr_sum=curr_sum+nums[i];
        if(i-start==k-1) {
            max_sum = max(curr_sum, max_sum);
            curr_sum = curr_sum - nums[start];
            start++;
        }
    }
    return max_sum/k;
}

int main() {
    cout<<max_mean_sub_array({1, 1, 1, 1, -1, -1, 2, -1, -1, 6}, 5)<<endl;
    cout<<max_mean_sub_array({1, 1, 1, 1, -1, -1, 2, -1, -1}, 3)<<endl;
    cout<<max_mean_sub_array({4, 5, -3, 2, 6, 1}, 2)<<endl;
    cout<<max_mean_sub_array({4, 5, -3, 2, 6, 1}, 3)<<endl;
}