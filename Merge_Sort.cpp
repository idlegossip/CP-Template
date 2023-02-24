#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 9;
ll a[N];

void merge_sort(ll l,ll r)
{
    if(l>=r)
        return ;

    ll mid = (l+r)/2;

    merge_sort(l,mid);
    merge_sort(mid+1,r);
    vector<ll>L,R;

    for(ll i = l; i<=mid; i++)
        L.push_back(ar[i]);

    for(ll i = mid+1; i<=r; i++)
        R.push_back(ar[i]);

    ll lid=0,rid=0,i=l;

    while(lid<(int)L.size()||rid < (int)R.size())
    {
        if(lid == (int)L.size())
        {
            a[i] = R[rid];
            rid++;
        }
        else if(rid == (int)R.size()|| L[id]<R[id])
        {
            a[i] = L[lid];
            lid++;
        }
        else
        {
            a[i] = R[rid];
            rid++;
        }
        i++;
    }
}



int main()
{

}
