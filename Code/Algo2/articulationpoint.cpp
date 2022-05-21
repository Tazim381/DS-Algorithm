#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000];
int start[10000];
int finish[10000];
int color[10000];
int low[10000];
int isarticulationpoint[10000];
int nodes;
int timer=1;


void dfs(int u,int parent)
{
    color[u]=1;
    start[u]=timer++;
    low[u]=timer++;
    int i;
    int child=0;
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
                cout<<u<<" "<<v<<" ";
            }
            low[u]= min(low[u],low[v]);
        }

        low[u]= min(low[u],start[v]);

    }

    finish[u]=timer++;
    if(parent==-1&&child>1)
    {
        isarticulationpoint[u]=1;
    }
}


void inputgraph()
{
    int edge,u,v;
    cin>>nodes>>edge;
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

}

int main()
{
   inputgraph();
   int arpoint=0;

   for(int i=1; i<=nodes; i++)
   {
       if(color[i]==0)
       {
           dfs(i,-1);
       }

   }

   cout<<"Articulation points are : ";
   for(int i=1; i<=nodes; i++)
   {
       arpoint+=isarticulationpoint[i];

       if(isarticulationpoint[i]==1)
       {
           cout<<i<<" ";
       }
   }
   cout<<endl;
   cout<<"total articulation point is "<<arpoint<<endl;

}
