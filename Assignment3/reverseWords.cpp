#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Time Complexity: O(N)
// Space Complexity: O(N)
// Time spent: Around 15 mins

string reverse(string s);

int main() {
    cout << reverse(string("Uber Career Prep") + string(" ")) << endl; // add a space to the end of the string
    return 0;
}

string reverse(string s){
    string temp;
    stack<string> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] != ' ')
            temp = temp + s[i]; // keep adding characters until a space is reached
        else{
            st.push(temp); // once a space is reached, push the word into the stack
            temp = "";
        }
    }

    string ans = "";
    while(st.size() > 0){
        ans = ans + st.top() + " ";
        st.pop();
    }
    return ans;
}
