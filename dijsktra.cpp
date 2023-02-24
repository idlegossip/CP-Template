#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+9;
const ll inf = 1e9+10;
vector<pair<ll,ll> >g[N];
priority_queue<pair<ll,ll> >pq;
bool vis[N];
ll dis[N];
ll n,m;
void dijstra(ll s)
{
    pq.push({0,s});
    dis[s]=0;
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        ll u=p.second;
        if(vis[u])continue;
        vis[u]=true;
        for(auto e : g[u])
        {
            ll v=e.first;
            ll cost = e.second;
            if(dis[u]+cost<dis[v])
            {
                dis[v] = dis[u]+cost;
                pq.push({-dis[v],v});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    memset(dis,inf,sizeof dis);
    ll a,b,c;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijstra(1);
    cout<<dis[n]<<endl;
}
