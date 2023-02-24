#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 9;
vector<ll>g[N] ;
bool vis[N];
ll col[N];
bool ok;

void dfs(ll u)
{
    vis[u] =true;
    for(auto v : g[u])
    {
        if(!vis[u])
        {
           col[v] = col[u]^1;
           dfs(v) ;
        }
        else if(u!=v)
        {
            if(col[u]==col[v])
            {
                ok = false;
            }
        }
    }

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
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    if(ok)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


}
