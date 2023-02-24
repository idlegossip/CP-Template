#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+7;
const ll inf = 1e16+7;
vector<ll>g[N],cost[N];
bool vis[N][2];
ll dis[N][2];
ll n,m;
priority_queue<pair<ll,pair<ll,ll> > >pq;

void dijstra()
{
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        ll u=p.second.first;
        ll b=p.second.second;
        if(vis[u][b])
            continue;
        vis[u][b]=1;
        for(ll i=0; i<g[u].size(); i++)
        {
            ll v=g[u][i];
            ll c=cost[u][i];
            if(b==1&&!vis[v][1])
            {
                if(dis[v][1]>(dis[u][1]+c))
                {

                    dis[v][1]=dis[u][1]+c;
                    pq.push({-dis[v][1],{v,1}});
                }
                continue;

            }

            if(dis[v][0]>(dis[u][0]+c))
            {
                dis[v][0]=dis[u][0]+c;
                pq.push({-dis[v][0],{v,0}});

            }
            if(dis[v][1]>(dis[u][0]+(c/2)))
            {
                dis[v][1]=dis[u][0]+(c/2);
                pq.push({-dis[v][1],{v,1}});
            }


        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dis,inf,sizeof(dis));

    cin>>n>>m;
    ll u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        g[u].push_back(v);
        //g[v].push_back(u);
        cost[u].push_back(w);
        //cost[v].push_back(w);
    }
    dis[1][0]=0;
    dis[1][1]=0;
    pq.push({0,{1,0}});
    dijstra();
    cout<<dis[n][1]<<endl;



}
