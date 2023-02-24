#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 3e5+7;
const ll p1 = 1949313259, mod1 = 2117566807;
ll ip1;
ll pw[N],ipw[N],pref[N];
string str;
ll power(ll n,ll k,ll mod)
{
    ll ans = 1;
    while(k)
    {
        if(k&1) ans = (1LL*n * ans) % mod ;
        n = (1LL* n * n) % mod;
        k>>=1;
    }
    return ans;
}

void prec()
{
    pw[0] = 1;
    ipw[0] = 1;
    ip1=power(p1,mod1-2,mod1);
    // cout<<ip1<<endl;
    // cout<<ip2<<endl;

    for(ll i = 1; i<N; i++)
    {
        pw[i] = (1LL* pw[i-1] * p1) % mod1;
        ipw[i] = (1LL*ipw[i-1]* ip1) % mod1;
    }
}

void build(string s)
{
    ll n = s.size();

    for(ll i = 0 ; i<n; i++)
    {
        pref[i] = (1LL*s[i] * pw[i]) % mod1;
        if(i)
            pref[i]= (1LL*(pref[i]+ pref[i-1]))% mod1;
    }
}

ll get_hash(ll i,ll j)
{
    ll hs=0;
    hs = pref[j];

    if(i)
    {
        hs = (1LL*hs - pref[i-1] + mod1) % mod1;
        hs= (1LL*hs * ipw[i])%mod1;
    }
    return hs;
}

ll lcp(ll i,ll j,ll x,ll y)
{
    ll l = 1, r = min(j-i+1,y-x+1);
    ll ans = 0;

    while(l<=r)
    {
        ll mid = (l+r)>>1;
        if(get_hash(i,i+mid-1)==get_hash(x,x+mid-1))
        {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}


ll cmp(ll i,ll j,ll x,ll y)
{
    assert(i<=j and x<=y);
    ll len = lcp(i,j,x,y) ;
    if((y-x+1)==(j-i+1) and len== (y-x+1)) return 0;
    if((y-x+1)==len) return -1;
    if((j-i+1)==len) return 1;
    if(str[i+len]>str[x+len]) return -1;
    else return 1;
}

bool cp(pair<ll,ll>a,pair<ll,ll>b)
{
    ll i = a.first;
    ll j = a.second;

    ll x = b.first;
    ll y = b.second;

    // cout<<i<<' '<<j<<"  dfds "<<x<<' '<<y<<endl;

    ll val = cmp(i,j,x,y);
    //cout<<"val = "<<val<<endl;
    if(val>0)
        return 1;
    else if(val<0)
        return 0;
    else
    {
        if(i<x) return 1;
        else return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    cin>>str;

    ll n = str.size();
    str+=str;

    build(str);

    ll ans=0;

    vector<pair<ll,ll> > vp;
    for(ll i = 0; i<n; i++)
    {
        vp.push_back({i,n+i-1});
    }
    sort(vp.begin(),vp.end(),cp);
    pair<ll,ll>p = {0,n-1};
    for(ll i = 0; i<n; i++)
    {
        if(p==vp[i])
        {
            ans=i+1;
            break;
        }
    }
    cout<<ans<<'\n';
    for(ll i = 0; i<n; i++)
    {
        // cout<<vp[i].first<<' '<<vp[i].second<<'\n';
        cout<<str[vp[i].second];
    }
}



