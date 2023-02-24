#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5+7;
ll dp[N+1];

ll t[4*N];

void upd(ll n,ll l,ll r,ll pos,ll val)
{
    if(l>pos or r<pos) return ;
    if(l==r and l==pos)
    {
        t[n] = val;
        return ;
    }
    ll n1 = n<<1;
    ll mid = (l+r)>>1;

    upd(n1,l,mid,pos,val);

    upd(n1|1,mid+1,r,pos,val);
    t[n] = max(t[n1],t[n1|1]);
}
ll query(ll n,ll l,ll r,ll i,ll j)
{
   // cout<<"gds"<<endl;
    if(i>j) return 0;
    if(l>j or r<i) return 0;
    if(l>=i and r<=j) return t[n];
    ll n1 = n<<1LL;
    ll mid = (l+r)>>1LL;
    ll a= query(n1,l,mid,i,j);
    ll b= query(n1|1,mid+1,r,i,j);
    return max(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(t,0,sizeof t);

    ll n;
    cin>>n;

    set<ll>st;
    map<ll,ll>mp;

    ll ar[n+1];
    ll id=1,a;

    for(ll i=0;i<n;i++)cin>>ar[i],st.insert(ar[i]);

    for(auto a : st)
        mp[a] = id++;

    for(ll i=0;i<n;i++)
    {
        ar[i] = mp[ar[i]];
    }

    for(ll i=0;i<n;i++)
    {
        a = ar[i];
        ll mx=0;
        if(a!=1)
        mx = query(1,1,id,1,a-1);

        mx++;
        dp[i]=mx;
        upd(1,1,id,a,mx);
    }
    ll ans=0;
    for(ll i=0;i<=n;i++)
    {
        ans = max(ans,dp[i]);
    }
    cout<<ans<<'\n';


}



