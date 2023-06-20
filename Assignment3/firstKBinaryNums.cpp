#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)
// Time taken to complete: Around 20 mins

vector<string> generateBinary(int k);

int main() {
    cout << "enter value for k" << endl;
    int k;
    cin >> k;
    vector<string> ans = generateBinary(k);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

vector<string> generateBinary(int k) {
    vector<string> ans;
    if(k == 0)
        return {};

    ans.push_back("0");
    k--;

    queue<string> q;
    q.push("1");

    while(k > 0){
        string top = q.front();
        q.pop();
        ans.push_back(top);
        k--;

        // keep adding 0 and 1 to the previous binary numbers
        q.push(top+"0");
        q.push(top+"1");
    }

    return ans;
}
