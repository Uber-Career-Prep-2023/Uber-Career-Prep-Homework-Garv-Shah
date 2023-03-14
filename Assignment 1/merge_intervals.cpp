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

//Time Complexity: O(nlogn)
//Space Complexity: O(1)
//Technique: Traverses the sorted array of intervals and keeps modifying the endpoints
//Time taken to solve: Around 25 mins
vector<vector<int>> merge_intervals(vector<vector<int>> intervals){
    assert(intervals.size()>0);
    sort(intervals.begin(), intervals.end());
    for(int i=0;i<intervals.size()-1;i++){

        if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i][1]=max(intervals[i][1], intervals[i+1][1]);
            intervals.erase(intervals.begin()+(i+1), intervals.begin()+(i+2));
            i--;
            }
        else
            continue;
    }
    for(int i=0; i<intervals.size(); i++){
        cout<<intervals[i][0]<<" ";
        cout<<intervals[i][1]<<endl;
    }
    return intervals;
}

int main(){
    merge_intervals({{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}});
    merge_intervals({{5, 8}, {6, 10}, {2, 4}, {3, 6}});
    merge_intervals({{10, 12}, {5, 6}, {7, 9}, {1, 3}});
}