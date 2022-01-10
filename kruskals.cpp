//disjoint set

#include <bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int a, int b, int weight){
        u=a;
        v=b;
        wt=weight;
    }
};

bool compare(node a, node b){
    return a.wt<b.wt;
}

int findPar(int node, vector<int>& par){
    if(par[node]==node){
        return node;
    }
    par[node]=findPar(node, par);//path compression
    return par[node];
    //OR, return par[node]=findPar(node);
}

void uni(int node1, int node2, vector<int>& par, vector<int>& ranking){
    node1=findPar(node1, par);
    node2=findPar(node2, par);
    if(ranking[node1]<ranking[node2]){
        par[node1]=node2;
    }
    else if(ranking[node1]>ranking[node2]){
        par[node2]=node1;
    }
    else{
        par[node2]=node1;//OR, par[node1]=node2;
        ranking[node1]++;
    }
}

int main()
{
    int n, ed; cin>>n>>ed;
    vector<node> edges;
    for(int i=0; i<ed; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(), edges.end(), compare);
    vector<int> par(n);
    for(int i=0; i<n; i++){
        par[i]=i;
    }
    vector<int> ranking(n, 0);
    
    int cost=0;//optional
    vector<pair<int, int>> mst;
    for(int i=0; i<edges.size(); i++){
        if(findPar(edges[i].v, par)!=findPar(edges[i].u, par)){
            mst.push_back({edges[i].v,edges[i].u});
            cost+=edges[i].wt;
            uni(edges[i].u, edges[i].v, par, ranking);
        }
    }
    cout<<cost<<endl;
    for(int i=0; i<mst.size(); i++){
        cout<<mst[i].first<<"-"<<mst[i].second<<endl;
    }
    return 0;
}
