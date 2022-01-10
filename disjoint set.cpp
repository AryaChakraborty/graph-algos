//disjoint set

#include <bits/stdc++.h>
using namespace std;
vector<int> par{0,1,2,3,4,5,6,7};
vector<int> ranking(8);

int findPar(int node){
    if(par[node]==node){
        return node;
    }
    par[node]=findPar(node);//path compression
    return par[node];
    //OR, return par[node]=findPar(node);
}

void uni(int node1, int node2){
    node1=findPar(node1);
    node2=findPar(node2);
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
    uni(1,2);
    uni(2,3);
    uni(4,5);
    uni(6,7);
    uni(5,6);
    uni(3,7);
    cout<<findPar(2);
    return 0;
}
