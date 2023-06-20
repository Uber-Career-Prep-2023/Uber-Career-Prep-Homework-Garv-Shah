#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity: O(N*logK)
// Space Complexity: O(N+K)
// Time taken to complete: Around 15 mins

vector<int> merge_arrays(int k, vector<vector<int>> &input);

int main() {
    vector<int> v1 = {1, 4, 7, 9};
    vector<int> v2 = {2, 6, 7, 10, 11, 13, 15};
    vector<int> v3 = {3, 8, 12, 13, 16};
    vector<vector<int>> input;
    input.push_back(v1);
    input.push_back(v2);
    input.push_back(v3);
    int k = 3;
    vector<int> ans = merge_arrays(k, input);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}

vector<int> merge_arrays(int k, vector<vector<int>> &input) {
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // min-heap
    while(k > 0){ // push first element of each vector along with the vector number into the heap
        q.push({input[k-1][0], k-1});
        input[k-1].erase(input[k-1].cbegin());
        k--;
    }
    while(!q.empty()){
        int min = q.top().first;
        ans.push_back(min);

        // if that vector is not empty, push it's next element into the heap
        if(!input[q.top().second].empty()){
            q.push({input[q.top().second][0], q.top().second});
            input[q.top().second].erase(input[q.top().second].cbegin());
        }

        q.pop();
    }
    return ans;
}
