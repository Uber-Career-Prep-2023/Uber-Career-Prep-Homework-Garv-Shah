#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> indeg(4, 0); // store the in-degree of each node

map<int, set<int>> adjacencySet(vector <pair<int, int>> edges);
bool bfs(int target, map<int, set<int>> graph);
bool dfs(int target, map<int, set<int>> graph);
bool dfsHelper(int current, int target, map<int, set<int>> graph, vector <bool> &visited);
vector<int> topologicalSort(map<int, set<int>> graph);

map<int, set<int>> adjacencySet(vector<pair<int, int>> edges){
    map<int, set<int>> g;
    for (auto &i : edges){
        g[i.first].insert(i.second); // creates a directed graph
        indeg[i.second]++;
    }
    return g;
}

bool bfs(int target, map<int, set<int>> graph){
    vector<bool> visited(graph.size(), false); // keeps track of nodes visited
    queue<int> q;
    q.push(graph.begin()->first);
    while (!q.empty()){
        int node = q.front();
        q.pop();

        if (node == target)
            return true;

        visited[node] = true;
        for (auto &i : graph[node]){ // iterating over nodes connected to the parent (i.e. the child nodes)
            if(!visited[i])
                q.push(i);
        }
    }
    return false;
}

bool dfs(int target, map<int, set<int>> graph){
    vector<bool> visited(graph.size(), false);
    return dfsHelper(graph.begin()->first, target, graph, visited);
}

bool dfsHelper(int current, int target, map<int, set<int>> graph, vector <bool> &visited){
    if (current == target)
        return true;

    visited[current] = true;

    for (auto &i : graph[current]){ // iterating over nodes connected to the parent (i.e. the child nodes)
        if(!visited[i]){
            if(dfsHelper(i, target, graph, visited))
                return true;
        } else
            continue;
    }

    return false;
}

vector<int> topologicalSort(map<int, set<int>> graph){
    queue<int> q;
    vector<int> ans;
    for(int i=0; i<graph.size(); i++){
        if(indeg[i] == 0){
            q.push(i); // adding node with 0 in-degree first
        }
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        cout << top << " ";
        for(auto &i : graph[top]){ // iterating over nodes connected to the parent (i.e. the child nodes)
            indeg[i]--; // reducing their in-degree by 1 because their parent was processed
            if(indeg[i] == 0)
                q.push(i);
        }
    }
    return ans;
}

int main() {
    vector<pair<int, int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({1, 3});
    edges.push_back({3, 2});
    edges.push_back({2, 0});
    map<int, set<int>> graph = adjacencySet(edges);
    for(int i=0;i<indeg.size();i++){
        cout<<indeg[i]<<" ";
    }
    cout<<endl;
    cout << bfs(3, graph) << endl;
    cout << bfs(4, graph) << endl;
    cout << dfs(3, graph) << endl;
    cout << dfs(4, graph) << endl;
    topologicalSort(graph);
    return 0;
}
