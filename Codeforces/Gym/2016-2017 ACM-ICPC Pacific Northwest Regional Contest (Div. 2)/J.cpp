#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
int solve(vector<pii> &v,int k){
    int ans = 0;
    int n = v.size();
    int r = 0;
    for(int i=0;i<n;i++){
        int x = v[i].ff, c = max(0LL,v[i].ss - r);
        r-= min(r,v[i].ss);
        int q = (c + k - 1) / k; // quantidade de vezes que precisa ir pra completar
        r += q * k - c; // quantidade que sobra na ultima ida
        ans += x * q * 2;
    }
    return ans;
}
main(){
    fastio;
    vector<pii> pos,neg;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a < 0){
            neg.pb({-a,b});
        }
        else pos.pb({a,b});
    }
    sort(td(pos),greater<pii>());
    sort(td(neg),greater<pii>());
    int t = solve(pos,k);
    t += solve(neg,k);
    cout << t << endl;
}
