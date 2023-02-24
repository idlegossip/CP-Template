#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6+7;
const ll p1 = 137, p2 = 277, mod1 = 1e9+7,mod2= 1e9+9;
pair<ll,ll>pw[N],ipw[N],pref[N];

ll power(ll n,ll k,ll mod )
{
    ll ans = 1 % mod;
    while(k)
    {
        if(k&1) ans = n * ans % mod;
        n = n * n % mod;
        k>>=1;
    }
    return ans;
}

void prec()
{
    pw[0] = {1,1};
    ipw[0] = {1,1};

    ll ip1 = power(p1,mod1-2,mod1);
    ll ip2 = power(p2,mod2-2,mod2);

    for(ll i=1;i<N;i++)
    {
       pw[i].first   = pw[i-1].first * p1 % mod1;
       pw[i].second  = pw[i-1].second * p2 % mod2;

       ipw[i].first  =  ipw[i-1].first * ip1 % mod1;
       ipw[i].second = ipw[i-1].second * ip2 % mod2;
    }
}
pair<ll,ll> string_hash(string s)
{
    ll n = s.size();
    pair<ll,ll>hs({0,0});

    for(ll i =0;i<n;i++)
    {
        hs.first += s[i] * pw[i].first % mod1;
        hs.first%=mod1;

        hs.second+= s[i] * pw[i].second % mod2;
        hs.second%=mod2;
    }
    return hs;
}
void build(string s)
{
    ll n = s.size();

    for(ll i =0;i<n;i++)
    {
        pref[i].first = s[i] * pw[i].first % mod1;
        pref[i].second= s[i] * pw[i].second % mod2;
        if(i)
        {
           pref[i].first = ( pref[i].first + pref[i-1].first)%mod1;
           pref[i].second = ( pref[i].second + pref[i-1].second)%mod2;
        }
    }
}

pair<ll,ll> get_hash(ll i,ll j)
{
    assert(i<=j);
    pair<ll,ll>hs({0,0});
    hs.first = pref[j].first;
    hs.second = pref[j].second;
    if(i)
    {
        hs.first = (hs.first - pref[i-1].first + mod1)% mod1;
        hs.first = hs.first * ipw[i].first %  mod1;

        hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
        hs.second = hs.second * ipw[i].second % mod2;
    }
    return hs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    string str;
    cin>>str;
    build(str);
    string p;
    cin>>p;
    ll n = str.size();
    ll len = p.size();
    pair<ll,ll> val = string_hash(p);
    ll ans=0;
    for(ll i = 0;i+len<=n;i++)
    {
        if(val==get_hash(i,i+len-1))
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
}
