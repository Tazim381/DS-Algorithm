#include<bits/stdc++.h>
using namespace std;
int start[100000];
int finish[100000];
int low[100000];
int timer=1;
vector<int>g[10000];
int visited[100000];
int isarticulationpoint[100000];

void dfs(int u,int parent)
{
    start[u]=timer++;
    low[u]=timer++;
    visited[u]=1;
    int child=0;


    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(visited[v]==0)
        {
            dfs(v,u);
            child++;
            if(start[u]<= low[v] && parent!=-1)
            {
                isarticulationpoint[u]=1;
            }
            low[u]= min(low[u], low[v]);
        }
       low[u]= min(low[u], start[v]);

    }

    finish[u]= timer++;
    if(parent==-1 && child>1)
    {
        isarticulationpoint[u]=1;
    }
}
int main()
{
    int i,j,m,n,a,b,v,u;
    int node,edge;
    cin>>node>>edge;
    for(i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(i=1; i<=node; i++)
    {
        if(visited[i]==0)
        {
            dfs(i,-1);
        }
    }

    for(i=1; i<=node; i++)
    {
        if(isarticulationpoint[i]==1)
        {
            cout<<i<<" ";
        }
    }


}
