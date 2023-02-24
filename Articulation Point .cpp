#include<bits/stdc++.h>
using namespace std;
#define ll long  long
const ll N = 1e5+7;
const ll inf = 1e9+7;
vector<ll>g[N];
bool vis[N];
ll in[N];
ll low[N];
ll point[N];
ll n,m;
ll timer=0,ans=0;
ll dfs(ll u,ll p=-1)
{
    timer++;
    vis[u]=true;
    in[u]=timer;
    low[u]=in[u];
    ll child=0;
    for(auto v : g[u] )
    {
        if(p==v)continue;
        if(!vis[v])
        {
            dfs(v,u);

            low[u]=min(low[u],low[v]);

            if(low[v]>=in[u]&&p!=-1&&!point[u])
            {
                point[u]=true;
                ans++;
            }
            child++;
        }
        else
            low[u]=min(low[u],in[v]);
    }
    if(p==-1&&child>1)// if u is a root node
        ans++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll ts=0;
    while(t--)
    {
        cin>>n>>m;
        ll a,x,y;
        timer=0;
        ans=0;
        for(ll i=0; i<m; i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);

        }
        ll com=0;
        for(ll i=1; i<=n; i++)
        {
            if(!vis[i])
                dfs(i,-1);
        }
        for(ll i=0; i<=n; i++)//All clear here
        {
            point[i]=false;
            low[i]=0;
            in[i] = 0;
            vis[i]=0;
            g[i].clear();
        }
    }
}

