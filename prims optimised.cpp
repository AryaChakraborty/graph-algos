#include <bits/stdc++.h>

using namespace std;
void prims(vector<vector<pair<int, int>>>& adj, vector<int>& key, vector<bool>& mst, vector<int>& par, int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[src]=0;
    pq.push({key[src], src});
    for(int i=0; i<adj.size()-1; i++){
        int pos=pq.top().second;
        pq.pop();
        mst[pos]=true;
        for(int j=0; j<adj[pos].size(); j++){
            int k=adj[pos][j].first, wt=adj[pos][j].second;
            if(!mst[k] && wt<key[k]){
                key[k]=wt;
                par[k]=pos;
                pq.push({key[k], k});
            }
        }
    }
}
int main()
{
    vector<vector<pair<int, int>>> adj{
        {{3,1},{1,2},{4,4}},
        {{0,2},{3,3},{2,3},{5,7}},
        {{3,5},{1,3},{5,8}},
        {{4,9},{0,1},{1,3},{2,5}},
        {{3,9},{0,4}},
        {{2,8},{1,7}}
    };
    vector<int> key(6, INT_MAX);
    key[0]=0;
    vector<bool> mst(6, false);
    vector<int> par(6, -1);
    prims(adj, key, mst, par, 0);
    for(int i=0; i<par.size(); i++){
        int it=par[i];
        cout<<it<<" ";
    }
    return 0;
}
