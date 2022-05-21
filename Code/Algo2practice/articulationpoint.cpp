#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector<int>g[100000];
int start[100000];
int low[100000];
int finish[100000];
int color[100000];
int isarticulationpoint[100000];
int timer =1;


/*
void dfs(int u, int parent)
{
    color[u]=1;
    int child=0;
    start[u]=timer++;
    low[u]= timer++;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][v];
        if(color[v]==0)
        {
            dfs(v,u);
            child++;
            if(start[u]<=low[v] && parent!= -1)
            {
                isarticulationpoint[u]=1;
            }

            low[u] = min(low[u], low[v]);
        }
        low[u]= min(low[u], start[v]);
    }
    finish[u]= timer++;
    if(parent==-1&& child>1)
    {
        isarticulationpoint[u]=1;
    }

}
*/
void dfs(int u,int parent)
{
    color[u]=1;
    int child=0;
    start[u]=timer++;
    low[u]= timer++;
    int i;

    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(color[v]==0)
        {
            dfs(v,u);
            child++;
            if(start[u]<=low[v] && parent!= -1)
            {
                isarticulationpoint[u]=1;
            }

            low[u] = min(low[u], low[v]);
        }
        low[u]= min(low[u], start[v]);
    }

    finish[u]=timer++;
    if(parent==-1&&child>1)
    {
        isarticulationpoint[u]=1;
    }
}

void inputgraph()
{
    cin>>node>>edge;
    int u,v;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


}
int main()
{
    int i,j,m,n;
    inputgraph();
    for(i=1; i<=node; i++)
    {
        if(color[i]==0)
        {
            dfs(i,-1);
        }
    }
    for(i=1; i<=node; i++)
    {
        if(isarticulationpoint[i]==1)
        {
            cout<<i <<" ";
        }
    }


}
