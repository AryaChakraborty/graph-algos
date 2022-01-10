#include <bits/stdc++.h>

using namespace std;
void dfs(int node, int parent, vector<int>& visi, vector<int>& low, vector<int>& tin, int& timer,
vector<vector<int>>& adj, vector<int>& isArticulation){
    visi[node]=1;
    low[node]=tin[node]=timer++;
    int childCount=0;
    for(auto itr : adj[node]){
        //very very important step
        if(parent==itr) continue;//ignore
        
        if(visi[itr]==0){
            dfs(itr, node, visi, low, tin, timer, adj, isArticulation);
            low[node]=min(low[itr], low[node]);
            if(low[itr]>=tin[node] && parent!=-1){
                isArticulation[node]=1;
            }
            childCount++;
        }
        else{
            low[node]=min(low[itr], low[node]);
        }
    }
    
    if(parent==-1 && childCount>1){
        isArticulation[node]=1;
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, low, tin, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}
