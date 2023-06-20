#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
// Time spent: Around 25 mins

unordered_map<string, vector<string>> make_graph(vector<string> towns, vector<pair<string, string>> roads);
bool dfs(unordered_map<string, vector<string>> &graph, unordered_map<string, bool> &visited, string town);

int main() {
//    vector<string> towns = {"Anchorage", "Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy"};
//    vector<pair<string, string>> roads = {{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}};
    vector<string> towns = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"};
    vector<pair<string, string>> roads = {{"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"}};

    unordered_map<string, vector<string>> graph = make_graph(towns, roads);
    unordered_map<string, bool> visited;
    for(auto &i : towns){
        visited[i] = false; // initially set the visited of all towns to false
    }
    int count = 0;
    for(auto &i : towns){
        if(dfs(graph, visited, i))
            count++;
    }
    cout << count << endl;
    return 0;
}

// this function essentially counts the number of connected components
bool dfs(unordered_map<string, vector<string>> &graph, unordered_map<string, bool> &visited, string town){
    if(visited[town] || graph[town].size() == 0) // if town has been visited or doesn't have any connections, return false
        return false;

    visited[town] = true; // set the visited of the town to true

    for(auto &i : graph[town]){
        if(!visited[i])
            dfs(graph, visited, i); // call dfs on all the connections of the town that haven't been visited
    }

    return true;
}

unordered_map<string, vector<string>> make_graph(vector<string> towns, vector<pair<string, string>> roads){
    unordered_map<string, vector<string>> mp;
    for(auto &i : towns){
        mp[i] = {};
    }
    for(auto &i : roads){
        // undirected graph
        mp[i.first].push_back(i.second);
        mp[i.second].push_back(i.first);
    }
    return mp;
}