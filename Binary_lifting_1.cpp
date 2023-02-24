#include<bits/stdc++.h>
using namespace std;
#define ll int

const ll N = 2e5+7;
vector<ll>g[N];
ll n;
ll par[21][N];
void dfs(ll u,ll p)
{
    par[0][u]=p;
    for(auto v : g[u])
    {
        if(v==p) continue;

        dfs(v,u);
    }
}


int main()
{
    memset(par,-1,sizeof(par));
    ll q;
    cin>>n>>q;
    ll a;
    for(ll i=2; i<=n; i++)
    {
        cin>>a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    dfs(1,-1);
    for(ll i=1; i<=20; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(par[i-1][j]!=-1 and par[i-1][par[i-1][j]]!=-1)
                par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    ll x,k;
    while(q--)
    {
        cin>>x>>k;
        for(ll i=20; i>=0; i--)
        {
            if((1<<i)<=k and par[i][x]!=-1)
            {
                k=k-(1<<i);
                x=par[i][x];
            }
        }
        ll ans=-1;
        if(k==0)
            ans=x;
        cout<<ans<<endl;
    }
}
