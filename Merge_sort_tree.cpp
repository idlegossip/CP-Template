/// https://codeforces.com/contest/1899/problem/G

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const ll N = 1e5+7;
vector<ll> tree[5*N+2];
vector<ll> g[N+1];
ll a[N+1];
int tin[N+1], tout[N+1];
int timer;

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].push_back(a[l]);
        return;
    }
    int m = (l + r)/2;
    build(2 * node + 1, l, m);
    build(2 * node+ 2, m+1, r);
    merge(all(tree[2 * node + 1]), all(tree[2 * node + 2]), back_inserter(tree[node]));
}
int query(int node,int l,int r, int l1,int r1,int mn,int mx)
{
    if (r < l1 || r1 < l) return 0;
    if (l1 <= l && r <= r1) return lower_bound(all(tree[node]),mx) - lower_bound(all(tree[node]), mn);
    int mid = (l + r)/2;
    int a = query(2 * node + 1,l,mid,l1, r1,mn,mx);
    int b = query(2 * node + 2, mid+1,r,l1, r1,mn,mx);
    return a + b;
}
void dfs(int v, int p)
{
    tin[v] = timer++;
    for (auto u : g[v])
    {
        if (u != p)
        {
            dfs(u, v);
        }
    }
    tout[v] = timer;
}
void clr(ll n)
{
    for(int  i = 0; i <= n; i++){
        g[i].clear();
        tin[i] = 0;
        tout[i] = 0;
        a[i] = 0;
    }
    for(int i = 0; i <= 5*n;i++) tree[i].clear();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        timer = 0;
        dfs(1, -1);
        ll x;
        for (int i = 0; i < n; i++) cin>>x,a[i] = tin[x];
       // cout<<"here\n";
        build(1,0,n-1);

        for (int i = 0; i < q; i++)
        {
            int l, r, x;
            cin >> l >> r >> x;
           // l--;
            if (query(1,0,n-1,l-1,r-1,tin[x], tout[x]))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
       clr(n);
       cout<<'\n';
    }
    return 0;
}
