#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector<int>g[100000];
int isarticulationpoint[100000];
int start[10000];
int finish[100000];
int low[100000];
int timer=1;
int color[100000];
typedef pair<int,int>p;
vector<p>bridge;

void dfs(int u, int parent)
{

    start[u]= timer++;
    low[u]= timer++;
    int child=0;
    color[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v =g[u][i];

        if(v!=parent)
        {

        if(color[v]==0)
        {
            dfs(v,u);
            child++;
            if(start[u]< low[v])
            {
                isarticulationpoint[u]=1;
                bridge.push_back(make_pair(u,v));
            }
            low[u]= min(low[u], low[v]);
        }
        low[u]= min(low[u],start[v]);
        }
    }


}
void buildgraph()
{
    cin>>node>>edge;
    int u,v;
    for(int i=1; i<=edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int main()
{
    int i,j,m,n;
    buildgraph();
    for(i=1; i<=node; i++)
    {
        if(color[i]==0)
        {
            dfs(i,-1);

        }


    }

    cout<<bridge.size();
    for(int i=0; i<bridge.size(); i++)
   {
       cout<<" "<<bridge[i].first<<" "<<bridge[i].second;
   }
   cout<<endl;


}
