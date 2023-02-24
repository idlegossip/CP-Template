#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6+7;
const ll mod = 1e9+7;
ll fact[N];
ll invers[N];
ll bigMod(ll n,ll p)
{
    ll ans = 1%mod ; n %= mod; if(n<0) n+=mod;
    while(p)
    {
        if(p&1) ans = ans * n % mod;
        n = n * n % mod;
        p = p>>1;
    }
    return ans;
}

ll npr(ll n ,ll r )
{
    if(n<r || n<0 ) return 0;
    return fact[n] * invers[n-r] % mod;
}

ll ncr(ll n,ll r)
{
    if(n<r or n<0) return 0;
    return (fact[n] * invers[r] % mod )* invers[n-r] % mod ;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for(ll i=1;i<=N-1;i++)
    {
        fact[i]=i*fact[i-1]%mod;
    }

    invers [ N-1 ] = bigMod( fact[N-1] , mod-2);
    for(ll i=N-2;i>=0;i--)
    {
        invers [i] = invers[i+1] * (i+1) % mod;
    }
    cout<<ncr(10 , 1)<<'\n';

}
