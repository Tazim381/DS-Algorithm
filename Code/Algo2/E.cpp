#include<bits/stdc++.h>
using namespace std;
#define NODES 10100
vector<int>g[NODES];
int start[NODES];
int finish[NODES];
int low[NODES];
int color[NODES];
vector<pair<int,int>>pr;
int node;
int isArticulationPoint[NODES];

int timer;
void init()
{
    int timer=0;
    pr.clear();
    for(int i=0; i<NODES; i++)
    {
        g[i].clear();
        isArticulationPoint[i] = start[i] = finish[i]=color[i]=0;

    }
}
void dfs(int u, int parent)
{
    start[u] = low[u] = timer++;
    color[u] = 1;

    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
           if(v!=parent){
            if(color[v]==0)
            {
                dfs(v, u);
                low[u]=min(low[u],low[v]);
                if(start[u]<low[v])
                {

                    pr.push_back(make_pair(min(u,v),max(u,v)));
                }
            }
               else low[u] = min(low[u], start[v]);
           }

    }

    finish[u] = timer++;

}



int main()
{

    int u,v,a,b,c,d,n;
      while (1) {
            cin>>a>>b;
            if(a==0&&b==0)
                break;
        init();
        for (int i = 0; i < b; i++) {

            cin>>c>>d;

                g[c].push_back(d);
                g[d].push_back(c);

        }

    /*    for(int i=0;i<n;i++)
           {
               cout<<i<<" : ";

            for(int j=0;j<g[i].size();j++)
            {
               cout<<g[i][j] <<" ";
            }
            cout<<endl;
           }*/
        for(int i=0; i<b; i++)
        {
           // cout<<"called1"<<endl;
            if(color[i] == 0)
            { //  cout<<"called"<<endl;
                dfs(i, -1);
            }
        }
        int criticalPoints = 0;
       /* for(int i=0; i<=n; i++)
        {
            criticalPoints+=isArticulationPoint[i];
        }*/
        cout<<pr.size();

        sort(pr.begin(),pr.end());
         for(int t=0;t<pr.size();t++)
            cout<<" "<<pr[t].first<<" "<<pr[t].second;
            cout<<endl;

    }


    return 0;

}
