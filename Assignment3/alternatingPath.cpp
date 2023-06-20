#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// Time spent: Around 35 mins

unordered_map<string, vector<pair<string, int>>> make_graph(vector<vector<string>> edges);
int bfs(unordered_map<string, vector<pair<string, int>>> &graph, string origin, string destination);

int main() {
    vector<vector<string>> edges {{"A", "B", "blue"}, {"A", "C", "red"}, {"B", "D", "blue"}, {"B", "E", "blue"}, {"C", "B", "red"},
                                  {"D", "C", "blue"}, {"A", "D", "red"}, {"D", "E", "red"}, {"E", "C", "red"}};
    unordered_map<string, vector<pair<string, int>>> graph = make_graph(edges);
    string origin = "E";
    string destination = "D";
    cout << bfs(graph, origin, destination) << endl;
    return 0;
}

unordered_map<string, vector<pair<string, int>>> make_graph(vector<vector<string>> edges){
    unordered_map<string, vector<pair<string, int>>> graph;
    for(auto &i : edges){
        if(i[2] == "red")
            graph[i[0]].push_back({i[1], 0}); // storing red as 0
        else if(i[2] == "blue")
            graph[i[0]].push_back({i[1], 1}); // storing blue as 1
    }
    return graph;
}

struct prop{
    string node;
    int steps;
    int col;
};

int bfs(unordered_map<string, vector<pair<string, int>>> &graph, string origin, string destination){
    set<pair<string, int>> visited;
    queue<prop> q;
    unordered_map<string, int> dist;
    dist[origin] = 0;
    q.push({origin, 0, -1}); // push origin into queue with 0 steps and no color

    // add origin to the visited set with both colors
    visited.insert({origin, 0});
    visited.insert({origin, 1});

    while(!q.empty()){
        string node = q.front().node;
        int col = q.front().col;
        int steps = q.front().steps;
        q.pop();

        for(auto &i : graph[node]){
            if(i.second != col && !visited.count({i.first, i.second})) {
                q.push({i.first, steps + 1, i.second}); // add the child node to the queue if its color is different and has not been visited
                visited.insert({i.first, i.second}); // add the child node to the visited set
                if(!dist.count(i.first))
                    dist[i.first] = steps + 1; // update distance to node
            }
        }

    }
    if(dist.count(destination))
        return dist[destination];
    else
        return -1; // return -1 is there was no path to the destinations
}