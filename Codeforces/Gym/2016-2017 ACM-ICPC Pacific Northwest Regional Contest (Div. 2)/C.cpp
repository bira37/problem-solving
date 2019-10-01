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
struct node{
    int i,j,k;
};
int n,m;
int x,y;
int ex,ey;
char tab[55][55];
int dist[55][55][55];
bool ok(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m && tab[i][j] == '.');
}
main(){
    fastio;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tab[i][j];
            if(tab[i][j]=='R'){
                tab[i][j] = '.';
                x = i; y = j;
            }
            if(tab[i][j]=='E'){
                tab[i][j] = '.';
                ex = i;
                ey = j;
            }
            for(int k=0;k<55;k++) dist[i][j][k] = -1;
        }
    }
    string c;
    cin >> c;
 
    queue<node> q;
    q.push({x,y,0});
    dist[x][y][0] = 0;
    string s = "RLDU";
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!q.empty()){
        node at = q.front();
        q.pop();
        for(int i=0;i<4 && at.k < c.size();i++){
            int nx = at.i + dx[i], ny = at.j + dy[i];
            if(!ok(nx,ny)) nx=at.i,ny = at.j;
            if(s[i]==c[at.k] && dist[nx][ny][at.k+1]==-1){
                dist[nx][ny][at.k+1] = dist[at.i][at.j][at.k];
                q.push({nx,ny,at.k+1});
            }
        }
        for(int i=0;i<4;i++){
            int nx = at.i + dx[i], ny = at.j + dy[i];
            if(ok(nx,ny) && dist[nx][ny][at.k]==-1){
                dist[nx][ny][at.k] = dist[at.i][at.j][at.k]+1;
                q.push({nx,ny,at.k});
            }
        }
    }
    int k = 1e9;
    for(int i=0;i<55;i++){
        if(dist[ex][ey][i]!=-1){
            k = min(k,dist[ex][ey][i]);
        }
    }
    cout << k << endl;
}
