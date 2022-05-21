
#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000009];
vector<int>rg[1000009];
int st[1000009];
int ed[1000009];
int t=1;
stack<int>stk;
int vis[1000009];
int vis2[1000009];
int node,edge;
void clear()
{

   for(int i=1; i<=node+10; i++)
   {
       vis[i]=0;
       vis2[i]=0;
       g[i].clear();
       rg[i].clear();
   }
}

void dfs(int u)
{

    st[u]=t;
    t++;
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
    ed[u] = t;
    t++;
    stk.push(u);
}

void dfs2(int u)
{

    vis2[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis2[v]==0)
        {
           dfs2(v);
        }
    }
}



int main()
{
    int i,j,m,n,a,b,v,u,p=1,t;
    cin>>t;
    while(t--)
    {

    cin>>node>>edge;
    clear();
    if(node==0&&edge==0) break;
    for(i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);

    }
    for(i=1; i<=node; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }

    }

    int scc=0;
    while(!stk.empty())
    {

        if(vis2[stk.top()]==0)
        {
            dfs2(stk.top());
            scc++;
        }
        stk.pop();
    }

    cout<<scc<<endl;



    }

}
