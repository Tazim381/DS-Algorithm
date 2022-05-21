#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int start[100000];
int finish[100000];
int visited[100000];
int visited2[100000];
int timer=1;
stack<int>stk;

void dfs(int u)
{
    start[u]=timer++;
    visited[u]= timer++;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
    }
    finish[u]= timer++;
    stk.push(u);

}

void dfs2(int u)
{
    start[u]=timer++;
    visited2[u]= timer++;
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
    int i,j,m,n,a,b,u,v;
    int node, edge;
    cin>>node>>edge;
    for(i=0; i<edge ; i++)
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

    int count=0;
    while(!stk.empty())
    {
        if(visited2[stk.top()]==0)
        {
            dfs2(stk.top());
            count++;
        }
        stk.pop();
    }
   cout<<count<<endl;

}