// Time Complexity: O(N log k)
// Space Complexity: O(N)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, string>, vector<pair<int, string>>> cats;
priority_queue<pair<int, string>, vector<pair<int, string>>> dogs;

void solve(){
    string adopt;
    cout<<"Are you adopting a pet?"<<endl;
    cin>>adopt;
    if(adopt=="yes"){
        string name;
        cout<<"Enter your name"<<endl;
        cin>>name;
        string preferance;
        cout<<"What is your preferance?"<<endl;
        cin>>preferance;
        if(preferance=="cat"){
            if(cats.size()>0){
                string pet=cats.top().second;
                cats.pop();
                cout<<name<<", "<<preferance<<", "<<pet<<endl;
            }
            else if(dogs.size()>0){
                string pet=dogs.top().second;
                dogs.pop();
                cout<<name<<", "<<"dog"<<", "<<pet<<endl;
            }
            else
                cout<<"Sorry, no more pets"<<endl;
        }
        else{
            if(dogs.size()>0){
                string pet=dogs.top().second;
                dogs.pop();
                cout<<name<<", "<<preferance<<", "<<pet<<endl;
            }
            else if(cats.size()>0){
                string pet=cats.top().second;
                cats.pop();
                cout<<name<<", "<<"cat"<<", "<<pet<<endl;
            }
            else
                cout<<"Sorry, no more pets"<<endl;
        }
    }
    else{
        string breed;
        cout<<"Enter breed of pet"<<endl;
        cin>>breed;
        string name;
        cout<<"Enter name of pet"<<endl;
        cin>>name;
        if(breed=="cat")
            cats.push({1, name});
        else
            dogs.push({1, name});
    }
}

int main() {
    dogs.push({4, "Sadie"});
    cats.push({7, "Woof"});
    dogs.push({2, "Chirpy"});
    dogs.push({1, "Lola"});
    while(cats.size()>0 && dogs.size()>0)
        solve();
    return 0;
}
