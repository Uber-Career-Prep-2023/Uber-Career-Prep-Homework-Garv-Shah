#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

// Time Complexity: O(V+E*logV)
// Space Complexity: O(V+E)
// Time spent: Around 40 mins

struct node{
    string start;
    string end;
    double dist;
};

unordered_map<string, vector<pair<string, double>>> make_graph(vector<node> &data);
int count_destinations(unordered_map<string, vector<pair<string, double>>> &graph, int k, string origin);

int main() {
    cout << "enter k value" << endl;
    int k;
    cin >> k;
    vector<node> data = {{"Boston", "New York", 4}, {"New York", "Philadelphia", 2}, {"Boston", "Newport", 1.5}, {"Washington, D.C.", "Harper's Ferry", 1}, {"Boston", "Portland", 2.5}, {"Philadelphia", "Washington, D.C.", 2.5}};
    unordered_map<string, vector<pair<string, double>>> graph = make_graph(data);
    int destinations = count_destinations(graph, k, "New York");
    cout << destinations << endl;
    return 0;
}

unordered_map<string, vector<pair<string, double>>> make_graph(vector<node> &data){
    unordered_map<string, vector<pair<string, double>>> graph;
    for(auto &i : data){
        graph[i.start].push_back({i.end, i.dist});
        graph[i.end].push_back({i.start, i.dist});
    }
    return graph;
}

// essentially uses a modified version of djikstra's algorithm
int count_destinations(unordered_map<string, vector<pair<string, double>>> &graph, int k, string origin){
    set<pair<double, string>> shortest;
    unordered_map<string, bool> visited;
    unordered_map<string, double> dist;

    // initially set the distance of each destination to max
    for(auto &i : graph){
        visited[i.first] = false;
        dist[i.first] = INT16_MAX;
        for(auto &x : i.second){
            visited[x.first] = false;
            dist[x.first]= INT16_MAX;
        }
    }

    int count = -1;
    shortest.insert({0, origin}); // insert origin into the set with 0 distance
    dist[origin] = 0; // set the origin's destination to 0

    while(!shortest.empty()){
        auto data = *shortest.begin();
        string dest = data.second;
        double wt = data.first;
        shortest.erase(shortest.begin());

        if(visited[dest])
            continue;

        visited[dest] = true;

        for(auto &i : graph[dest]){
            if(dest == origin){
                if(wt + i.second < dist[i.first]){ // try to minimize distance
                    dist[i.first] = wt + i.second;
                    shortest.insert({dist[i.first], i.first});
                }
            }
            // for every destination that is not the origin, we add 1 hour of stopover time
            else{
                if(wt + i.second + 1 < dist[i.first]){ // try to minimize distance
                    dist[i.first] = wt + i.second + 1;
                    shortest.insert({dist[i.first], i.first});
                }
            }
        }
    }

    for(auto &i : dist){
        if(i.second <= k)
            count++; // add the number of destinations that are within k hours from the origin
                     // this also includes the origin, which is why I set count to -1 initially
    }

    return count;

}