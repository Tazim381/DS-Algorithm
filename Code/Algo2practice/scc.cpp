#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int start[10000];
int finish[100000];
int visited[1000000];
int visited2[1000000];
int timer=1;
stack<int>stk;

void dfs(int u)
{

    start[u]=timer++;

    visited[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
    }
    finish[u] = timer++;

    stk.push(u);
}


void dfs2(int u)
{
    visited2[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(visited2[v]==0)
        {
            dfs2(v);
        }
    }
}
int main()
{
    int i,j,m,n;
    int node,edge,u,v;
    cin>>node>>edge;
    for(i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(i=1; i<=node; i++)
    {
        if(visited[i]==0)
            {
                dfs(i);
            }
    }
    int scc=0;

   while(!stk.empty()){
        if(visited2[stk.top()]==0)
        {
            dfs2(stk.top());
            scc++;
        }
        stk.pop();
    }

    cout<<scc<<endl;
}
