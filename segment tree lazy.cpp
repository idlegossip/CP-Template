#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+7;

ll ar[N];
struct st
{
#define ln (n<<1)
#define rn ((n<<1)+1)
    ll t[4*N],lazy[4*N];
    st()
    {
        memset(t,0,sizeof(t));
        memset(lazy,0,sizeof(lazy));

    }
    inline void push(ll n,ll l,ll r)
    {
        if(lazy[n]==0)
            return;
        t[n] = t[n] + lazy[n]*(r-l+1);
        if(l!=r)
        {
            lazy[ln] = lazy[ln] + lazy[n];
            lazy[rn] = lazy[rn] + lazy[n];
        }
        lazy[n]=0;
    }
    inline ll combine(ll a,ll b)
    {
        return a+b;
    }
    inline void  pull(ll n)
    {
        t[n] = t[ln] + t[rn];
    }
    void build(ll n,ll l,ll r)
    {
        if(l==r)
        {
            t[n] = ar[l];
            lazy[n] =0;
            return ;
        }
        ll mid = (l+r)>>1;
        build(ln,l,mid);
        build(rn,mid+1,r);
        pull(n);
    }
    void update(ll n,ll l,ll r,ll lin,ll rin,ll val)
    {
        push(n,l,r);
        if(l>rin||r<lin)
            return;
        if(l>=lin&&r<=rin)
        {
            lazy[n] = val;
            push(n,l,r);
            return ;

        }
        ll mid = (l+r)>>1;
        update(ln,l,mid,lin,rin,val);
        update(rn,mid+1,r,lin,rin,val);
        pull(n);
    }
    ll query(ll n,ll l,ll r,ll lin,ll rin)
    {
         push(n,l,r);
        if(l>rin||r<lin)
            return 0;
        if(l>=lin&&r<=rin)
        {
            return t[n] ;
        }
        ll mid = (l+r)>>1;
        return combine(query(ln,l,mid,lin,rin),query(rn,mid+1,r,lin,rin));
    }
}t;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tst;
   // cin>>tst;
    ll ts=0;
    while(tst)
    {
        ts++;
        ll n,q;
        cin>>n>>q;
        for(ll i=0;i<n;i++)
            cin>>ar[i];
        ll f,a,b,c;
        t.build(1,0,n-1);
        while(q--)
        {
            cin>>f;
            if(f==1)
            {
              cin>>a>>b>>c;
              t.update(1,0,n-1,a,b-1,c);
            }
            else
            {
                cin>>a;
             cout<< t.query(1,0,n-1,a-1,a-1)<<endl;

            }
        }

    }
}
