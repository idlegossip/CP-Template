#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 7;
vector<ll>g[N];
ll col[N];
bool cycle;

void dfs(ll u)
{
    col[u] = 1;
    for(auto v : g[u])
    {
        if(col[v]==0)
            dfs(v);
        else if(col[v]==1)
            cycle = true;
    }
    col[u]=2;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll u,v;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    cycle = false;
    for(ll i=1; i<=n; i++)
    {
        if(!col[i])
            dfs(i);
    }
    if(cycle)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
