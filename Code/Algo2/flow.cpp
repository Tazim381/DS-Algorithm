#include<bits/stdc++.h>
using namespace std;
int node, edge;
int capacity[10000][10000];

void init(int node)
{

    for(int i=0; i<=node; i++)
    {
        for(int j=0; j<=node; j++)
        {
            capacity[i][j]=0;
        }
    }
}
void inputgraph()
{
    int u,v,cap;
    cin>>node>>edge;
    init(node);
    for(int i=0; i<edge; i++)
    {
       cin>>u>>v>>cap;
       capacity[u][v]=cap;

    }

}
void dfs(int source, int sink)
{


}

void maxflow(int source, int sink)
{

    while(dfs(source,sink))
    {

    }
}
int main()
{
    inputgraph();
    int source, sink;
    cin>>source>>sink;
    maxflow(source,sink);
}
