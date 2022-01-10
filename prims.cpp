#include <bits/stdc++.h>

using namespace std;
void prims(vector<vector<pair<int, int>>>& adj, vector<int>& key, vector<bool>& mst, vector<int>& par, int src){
    for(int i=0; i<adj.size()-1; i++){
        int minkey=INT_MAX, pos=-1;
        for(int j=0; j<adj.size(); j++){
            if(!mst[j] && key[j]<minkey){
                minkey=key[j];
                pos=j;
            }
        }
        mst[pos]=true;
        for(int j=0; j<adj[pos].size(); j++){
            int k=adj[pos][j].first, wt=adj[pos][j].second;
            if(!mst[k] && wt<key[k]){
                key[k]=wt;
                par[k]=pos;
            }
        }
    }
}
int main()
{
    vector<vector<pair<int, int>>> adj{
        {{3,6},{1,2}},
        {{0,2},{2,3},{3,8},{4,5}},
        {{1,3},{4,7}},
        {{0,6},{1,8}},
        {{1,5},{2,7}}
    };
    vector<int> key(5, INT_MAX);
    key[0]=0;
    vector<bool> mst(5, false);
    vector<int> par(5, -1);
    prims(adj, key, mst, par, 0);
    for(int i=0; i<par.size(); i++){
        int it=par[i];
        cout<<it<<" ";
    }
    return 0;
}
