#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e3+3;
ll table[11][N+1][11][N+1];
ll pre[N+1][N+1];
ll mat[N+1][N+1];
///https://www.codechef.com/problems/CHSQARR
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    ll a;
    cin>>n>>m;
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin>>a;
            mat[i][j] = a;
            pre[i][j] = a;
            pre[i][j] += pre[i-1][j];
            pre[i][j] += pre[i][j-1];
            pre[i][j] -= pre[i-1][j-1];
        }
    }
    for(int r = 1; r <= n; r++)
    {
        for(int c = 1; c <= m; c++) table[0][r][0][c] = mat[r][c];
        for(int lenc = 1; lenc <= log2(m); lenc++)
        {
            for(int c = 1; c + (1<<(lenc-1))-1 <= m; c++)
            {
                table[0][r][lenc][c] = max(table[0][r][lenc-1][c],table[0][r][lenc-1][c+(1<<(lenc-1))]);
            }
        }
    }
    for(int lenr = 1; lenr <= log2(n); lenr++)
    {
        for(int r = 1; r + (1<<(lenr-1))<= n; r++)
        {
            for(int lenc = 0; lenc <= log2(m); lenc++)
            {
                for(int c = 1; c <= m; c++)
                {
                    table[lenr][r][lenc][c] = max(table[lenr-1][r][lenc][c],table[lenr-1][r+(1<<(lenr-1))][lenc][c]);
                }
            }
        }
    }
    ll q;
    cin>>q;
    ll b;
    while(q--)
    {
        cin>>a>>b;
        ll x,y,x1,y1;
        ll ans= LONG_LONG_MAX;
        for(int r = 1; r+a-1<= n; r++)
        {
            for(int c = 1; c+b-1 <= m; c++)
            {
                ll sum = pre[r+a-1][c+b-1];
                sum -= pre[r+a-1][c-1];
                sum -= pre[r-1][c+b-1];
                sum += pre[r-1][c-1];
                x = r;
                y = c;
                x1 = r+a-1;
                y1 = c+b-1;
                ll kx = log2(a);
                ll ky = log2(b);
                ll mx1 = max(table[kx][x][ky][y],table[kx][x][ky][y1+1-(1<<ky)]);
                ll mx2 = max(table[kx][x1+1-(1<<kx)][ky][y],table[kx][x1+1-(1<<kx)][ky][y1+1-(1<<ky)]);
                mx1 = max(mx1,mx2);
                //cout<<mx1<<'\n';
                sum = (a*b* mx1)-sum;
                ans = min(ans,sum);
            }
        }
        cout<<ans<<'\n';
    }
}

