#include <bits/stdc++.h>

using namespace std;
void dijkstras(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int src){
    priority_queue<pair<int, int>> pq;//dist, node
    dist[src]=0;
    pq.push({0, src});
    while(!pq.empty()){
        int node=pq.top().second;
        int distance=pq.top().first;
        pq.pop();
        if(dist[node]!=INT_MAX){
            for(int i=0; i<adj[node].size(); i++){
                if(distance+adj[node][i].second<dist[adj[node][i].first]){
                    dist[adj[node][i].first]=distance+adj[node][i].second;
                    pq.push({dist[adj[node][i].first], adj[node][i].first});
                }
            }
        }
    }
}
int main()
{
	//node, dist
    vector<vector<pair<int, int>>> adj{
        {{0,0}},
        {{2,2},{4,1}},
        {{1,2},{5,5},{3,4}},
        {{2,4},{4,3},{5,1}},
        {{1,1},{3,3}},
        {{2,5},{3,1}}
    };
    vector<int> dist(6, INT_MAX);
    dijkstras(adj, dist, 1);
    for(int i=1; i<dist.size(); i++){
        int it=dist[i];
        cout<<it<<" ";
    }
    return 0;
}
