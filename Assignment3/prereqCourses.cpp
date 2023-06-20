#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// Time spent: Around 30 mins

unordered_map<string, vector<string>> make_graph(vector<string> &courses, unordered_map<string, vector<string>> &reqs, unordered_map<string, int> &indeg);
vector<string> topologicalSort(unordered_map<string, vector<string>> &graph, unordered_map<string, int> &indeg);

int main() {

    vector<string> courses = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};
    unordered_map<string, vector<string>> reqs;
    reqs["Contemporary Literature"] = {"Intro to Writing"};
    reqs["Ancient Literature"] = {"Intro to Writing"};
    reqs["Comparative Literature"] = {"Ancient Literature", "Contemporary Literature"};
    reqs["Plays & Screenplays"] = {"Intro to Writing"};

    unordered_map<string, int> indeg; // stores the in-degree of each node
    for (auto &i : courses){
        indeg[i] = 0;
    }
    unordered_map<string, vector<string>> graph = make_graph(courses, reqs, indeg);

    vector<string> ans = topologicalSort(graph, indeg);
    for(auto &i : ans){
        cout << i << endl;
    }
    return 0;
}

unordered_map<string, vector<string>> make_graph(vector<string> &courses, unordered_map<string, vector<string>> &reqs, unordered_map<string, int> &indeg){
    unordered_map<string, vector<string>> graph;
    for(auto &i : courses){
        graph[i] = {""};
    }
    for(auto &i : reqs){
        indeg[i.first] = i.second.size();
        for(auto &j : i.second){
            graph[j].push_back(i.first);
        }
    }
    return graph;
}

vector<string> topologicalSort(unordered_map<string, vector<string>> &graph, unordered_map<string, int> &indeg){
    queue<string> q;
    vector<string> ans;
    for(auto &i : indeg){
        if(i.second == 0)
            q.push(i.first); // pushes the course with no pre-reqs into the queue first
    }
    while(!q.empty()){
        string top = q.front();
        q.pop();
        ans.push_back(top);
        for(auto &i : graph[top]){ // iterates over the children (i.e. connected courses)
            indeg[i]--; // reduces their in-degree as the parent course has been processed
            if(indeg[i] == 0)
                q.push(i);
        }
    }
    return ans;
}