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
//Technique: Simply traverses array once and checks for missing element
//Time taken to solve: Around 8 mins
int missing_integer(int n, vector<int> nums){
    assert(n-1==nums.size());
    if(n==2)
        return 2;
    else if(n>2){
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] != 1)
                return nums[i + 1] - 1;
        }
    }
    return 0;
}

int main() {
    cout<<missing_integer(7, {1, 2, 3, 4, 6, 7})<<endl;
    cout<<missing_integer(2, {1})<<endl;
    cout<<missing_integer(12, {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12})<<endl;
}