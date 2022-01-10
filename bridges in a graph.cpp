#include <iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> answer;
    void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<int>& visi, int timer){
        visi[node]=1;
        tin[node]=low[node]=timer++;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i]==par) continue;//ignore
            if(visi[adj[node][i]]==0){
                dfs(adj[node][i], node, adj, tin, low, visi, timer);
                low[node]=min(low[node], low[adj[node][i]]);
                if(low[adj[node][i]] > tin[node]){
                    answer.push_back({adj[node][i], node});
                }
            }
            else{
                low[node]=min(low[node], low[adj[node][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> tin(n);
        vector<int> visi(n, 0);
        vector<int> low(n);
        int timer=0;
        for(int i=0; i<n; i++){
            if(visi[i]==0){
                dfs(i, -1, adj, tin, low, visi, timer);
                //-1 is the parent here, and timer is the time counter
            }
        }
        return answer;
    }
};
int main()
{
    Solution obj;
    return 0;
}
