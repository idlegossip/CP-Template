#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+7;
vector<ll>g[N];
ll mx = 0;
ll dis[N];
ll node;
void dfs(ll u,ll p)
{
    for(auto v  : g[u])
    {
        if(v==p) continue;
        dis[v] = dis[u] + 1;
        if(dis[v]>mx)
        {
            mx = dis[v];
            node = v;
        }
        dfs(v,u);
    }
}
void dfs1(ll u,ll p)
{
    for(auto v  : g[u])
    {
        if(v==p) continue;
        dis[v] = dis[u] + 1;
        if(dis[v]>mx)
        {
            mx = dis[v];
        }
        dfs(v,u);
    }
}
int main()
{
    ll n;
    cin>>n;
    ll a,b;
    for(ll i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mx=0;
    node=0;
    dfs(1,-1);
    mx=0;
    for(ll i=1;i<=n;i++)dis[i]=0;
    dfs(node,-1);
    cout<<mx<<endl;
}

