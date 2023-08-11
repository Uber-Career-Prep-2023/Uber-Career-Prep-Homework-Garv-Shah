// Time Complexity: O(N log k)
// Space Complexity: O(N)


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

double median(vector<int> &nums, priority_queue<int, vector<int>> &max, priority_queue<int, vector<int>, greater<int>> &min);

double median(vector<int> &nums, priority_queue<int, vector<int>> &max, priority_queue<int, vector<int>, greater<int>> &min){
    int new_num=nums[nums.size()-1];
    if(max.size()==0){
        max.push(new_num);
        return new_num;
    }
    if(min.size()==0){
        if(new_num>=max.top()){
            min.push(new_num);
        }
        else{
            int max_top=max.top();
            max.pop();
            max.push(new_num);
            min.push(max_top);
        }
        return (max.top()+min.top())/2.0;
    }
    if(max.size()==min.size()){
        if(new_num<=min.top()){
            max.push(new_num);
        }
        else{
            int min_top=min.top();
            min.pop();
            min.push(new_num);
            max.push(min_top);
        }
        return max.top();
    }
    else{
        if(new_num>=min.top() || new_num>=max.top()){
            min.push(new_num);
        }
        else{
            int max_top=max.top();
            max.pop();
            max.push(new_num);
            min.push(max_top);
        }
        return (max.top()+min.top())/2.0;
    }
}

int main() {
    priority_queue<int, vector<int>> max;
    priority_queue<int, vector<int>, greater<int>> min;
    vector<int> nums;
    cout<<"Start entering numbers, enter -1 to stop"<<endl;
    for(int i=0; i>=0; i++){
        int num;
        cin>>num;
        if(num==-1)
            break;
        nums.push_back(num);
        cout<<median(nums, max, min)<<endl;
    }
    return 0;
}
