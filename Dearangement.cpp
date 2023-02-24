#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll  mod = 1e9+7;
/// number of permutations with p_i != i
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll dp[n+2];
    dp[0]=dp[1]=0,dp[2] = 1;
    for(ll i = 3; i<=n; i++){
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2]) % m)%m;
    }
    for(ll i = 1; i<=n; i++){
       cout<<dp[i]<<' ';
    }
    //cout<<dp[n]<<'\n';
}
