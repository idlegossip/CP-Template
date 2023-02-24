#include<bits/stdc++.h>
using namespace std;
#define ll long long

int  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll u,v;
    vector<ll>indeg(n+1,0),ans,adj[n+1],visit(n+1,0);
    vector<ll>have(n+1,0);
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        have[u]=1;
        have[v]=1;
        indeg[v]++;
        adj[u].push_back(v);
    }
    ll hv=0;
    priority_queue<ll>pq;
    for(ll i=1; i<=n; i++)
    {
        if(indeg[i]==0 and have[i]==1) pq.push(-i);
        if(have[i]==0) hv++;
    }
    //cout<<pq.size()<<" ";
    hv = n-hv;
    while(ans.size()<hv)
    {
        if(pq.empty())
        {
            //cout<<pq.size()<<" ";
            cout<<"Sandro fails."<<endl;
            return 0;
        }
        u = llabs(pq.top());
        // cout<<u<<" ";
        ans.push_back(u);
        pq.pop();
        for(ll x : adj[u])
        {
            indeg[x]--;
            if(visit[x]==0 and indeg[x]==0)
            {
                visit[x]=1;
                pq.push(-x);
            }
        }
    }
    ll k = 1;
    for(ll i=0; i<hv; i++)
    {
        for( ; k<ans[i]; k++)
        {
            if(have[k]==0)
            {
                cout<<k<<" ";
            }
        }
        cout<<ans[i]<<" ";
    }
    for( ; k<=n; k++)
        if(have[k]==0)
            cout<<k<<" ";
}

