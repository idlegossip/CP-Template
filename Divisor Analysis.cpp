#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll bigmod(ll b,ll p)
{
    ll ans = 1;
    while(p){
        if(p&1)
            ans = ans * b % mod;
        p>>=1;
        b *= b;
        b%= mod;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll sum = 1;
    ll div = 1;
    ll p,y;
    ll pwe = 1;
    ll pd = 1;
    ll sqpd = 1;
    ll nod = 1;

    for(ll i = 0; i < n; i++){
        cin>>p>>y;
        div *= (y+1);
        div %= mod;
        sum= sum * (bigmod(p,y+1)-1) % mod * (bigmod(p-1,mod - 2)) % mod;
        sum %= mod;

        sqpd *= bigmod(p,y/2);
        sqpd %= mod;

        pd *= bigmod(p,y);
        pd %= mod;

        if(pwe and (y%2)){
            y=(y+1)/2;
            pwe=0;
           nod *= y;
        }
        else{
            nod *= (y+1);
        }
        nod%= (mod-1);
    }
    ll ans = 0;
    //cout<<pwe<<'\n';
    if(!pwe){
        ans  = bigmod(pd,nod);
    }
    else{
        ans = bigmod(sqpd,nod);
    }
    cout<<div<<' '<<sum<<' '<<ans<<'\n';

}
