
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int color[100000];
int isarticulationpoint[100000];
int start[1000000];
int finish[1000000];
int low[1000000];
int timer=1;


void dfs(int u, int parent)
{
    color[u]=1;
    start[u]= timer++;
    low[u]= timer++;
    int child=0,i;

   for(i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(color[v]==0)
        {
            dfs(v,u);
            child++;
            if(start[u]<=low[v]&&parent!=-1)
            {
                isarticulationpoint[u]=1;
                //cout<<u<<" "<<v<<" ";
            }
            low[u]= min(low[u],low[v]);
        }

        low[u]= min(low[u],start[v]);

    }

    finish[u]= timer++;


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
        g[v].push_back(u);
    }
    for(i=1; i<= node; i++)
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
            cout<<i<<" ";
        }
    }
}

