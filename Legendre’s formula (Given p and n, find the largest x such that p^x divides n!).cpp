#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll legend(ll n,ll p)
{
    ll cnt=0;
    while(n>1)
    {
        n/=p;
        cnt+=n;
    }
    return cnt;
}
vector<pair<ll,ll> >primefact(ll b)
{
   vector<pair<ll,ll> >fact;
   for(ll i=2;b!=1;i++)
   {
       if(b%i==0)
       {
           ll cnt=0;
           while(b%i==0)
           {
               cnt++;
               b/=i;
           }
           fact.push_back({i,cnt});
       }
   }
   return fact;

}
ll lpox(ll n,ll b)
{
    vector<pair<ll,ll> >bf=primefact(b);
    ll ans =  INT_MAX;
    for(ll i=0;i<bf.size();i++)
    {
        ll a = bf[i].first;
        ll b = bf[i].second;
        ans=min(ans,legend(n,a)/b);
    }
    return ans;
}
int main()
{
    ll n,p;
    cin>>n>>p;
    cout<<(lpox(n,p))<<endl;

}
