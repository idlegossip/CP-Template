#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5010][5010];
/// faltu approach
ll n,n1;
string s,s1;
ll go(ll i,ll j)
{
    if( i>=n) return (n1-j);

    if( j>=n1) return (n-i);
    if( dp[i][j] != -1 ) return dp[i][j];
    ll ans =LONG_MAX;
    if(s[i]==s1[j])
      return dp[i][j]=go(i+1,j+1);
    else
    {
      return dp[i][j]= 1+min({go(i+1,j),go(i,j+1),go(i+1,j+1)});
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>s>>s1;
    n = s.size();
    n1 = s1.size();
    ll x = go(0,0);
    cout<<x<<endl;
}

