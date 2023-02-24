#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 9;
ll spf[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i=2; i<N; i++)
        spf[i] = i;
    for( ll i = 2 ; i<N; i++ )
    {
        for(ll j=i; j<N; j+=i )
        {
            spf[j] = min(spf[j],i);
        }
    }
    ll q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector<ll>ans;
        while(n>1)
        {
            ans.push_back(spf[n]);
            n/=spf[n];
        }
    }

    return 0;

}
