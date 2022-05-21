
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100000];
int start[100000];
int finish[100000];
int color[100000];
int low[100000];
int isarticulationpoint[100000];
int nodes;
int timer=1;
typedef pair<int,int>p;
vector<p>bridge;


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

        if(v!=parent)
        {

        if(color[v]==0)
        {
            dfs(v,u);

            if(start[u]<low[v])
            {
                isarticulationpoint[u]=1;
                bridge.push_back(make_pair(min(u,v),max(u,v)));

            }
            low[u]= min(low[u],low[v]);
        }

         low[u]= min(low[u],start[v]);

        }


    }

}
void init()
{

    bridge.clear();
    timer=0;
    for(int i=0; i<10000; i++)
    {
        low[i]= 0;
        start[i]=0;
        color[i]=0;
        g[i].clear();
        isarticulationpoint[i]=0;

    }

}


int main()
{
   while(1)
   {


    int edge,u,v;
    cin>>nodes>>edge;
    if(nodes==0&&edge==0)
    {
        break;
    }
     init();
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }


   for(int i=1; i<=nodes; i++)
   {
       if(color[i]==0)
       {
           dfs(i,-1);
       }

   }

   cout<<bridge.size();
   sort(bridge.begin(), bridge.end());

   for(int i=0; i<bridge.size(); i++)
   {
       cout<<" "<<bridge[i].first<<" "<<bridge[i].second;
   }
   cout<<endl;



   }
}
