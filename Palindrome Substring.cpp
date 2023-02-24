#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p1 = 137, p2 = 277, mod1 = 1e9+7,mod2 = 1e9+9;
//const ll mod1 = 127657753, mod2 = 987654319;
const ll N = 1e5+7;

ll pw[N],ipw[N],pref[N],rpref[N];

ll power(ll n,ll k,ll mod)
{
    ll ans = 1%mod;
    n%=mod;
    if(n<0)n+=mod;
    while(k)
    {
        if(k&1) ans = ans * n % mod;
        n = n* n % mod;
        k>>=1;
    }
    return ans;
}

void prec()
{
    pw[0] =1;
    ll ip1 = power(p1,mod1-2,mod1);
    ll ip2 = power(p2,mod2-2,mod2);
    ipw[0] = 1;
    for(ll i=1; i<N; i++)
    {
        pw[i] = pw[i-1] * p1 %mod1;
        ipw[i] = ipw[i-1] *ip1%mod1;
    }


}
void build(string str)
{
    ll n = str.size();
    string s = str;
    reverse(s.begin(),s.end());

    for(ll i=0; i<n; i++)
    {
        pref[i] = (1LL * str[i] * pw[i]) % mod1 ;
        rpref[i]= 1LL * s[i] * pw[i] % mod1 ;
        if(i)
        {
            pref[i]= (pref[i]+ pref[i-1]) % mod1 ;
            rpref[i] = (rpref[i]+ rpref[i-1]) % mod1;
        }
    }
}

bool get_hash(ll i,ll j,ll n)
{
    assert(0 <= i && i <= j && j < n);
    ll hs=0,rhs=0;
    hs= pref[j] ;
    if(i)
        hs= (hs - pref[i-1] + mod1) % mod1;
    hs = 1LL * hs* ipw[i]% mod1;

    ll temp = n-i-1;
    i = n - j -1 ;
    j = temp ;

    rhs = rpref[j];
    if(i)
        rhs= (rhs- rpref[i-1]+ mod1) % mod1;
    rhs = 1LL * rhs* ipw[i] % mod1;
    return hs==rhs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    prec();
//        memset(pref,0,sizeof pref);
//        memset(rpref,0,sizeof rpref);
    build(str);
    ll n = str.size();
    ll ans=0;
    for(ll len=1; len<=n; len++)
    {
        // cout<<"Len  =  "<<len<<'\n';

        for(ll i=0; i+len<=n; i++)
        {
            ll f = get_hash(i,i+len-1,n);
            if(f)
                ans++;
        }
    }

    cout<<ans<<'\n';

}

