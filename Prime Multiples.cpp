#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    vector<ll>v;
    cin>>n>>k;
    ll a;
    for(int i = 0; i < k; i++){
        cin>>a;
        v.push_back(a);
    }
    ll n1 = (1LL<<k);
    ll ans = 0;
    for(int i = 1; i < n1; i++)
    {
        ll cnt = __builtin_popcountl(i);
        __int128 mul = 1;
        for(int j = 0; j < k; j++){
            if((i & (1LL<<j))){
                mul *= v[j];
            }
            if(mul > n)
                break;
        }
        if(mul > n)
            continue;
        ll m = mul;
        if(cnt % 2){
            ans += (n/m);
        }
        else{
            ans -= (n/m);
        }

    }
    cout<<ans<<'\n';

}
