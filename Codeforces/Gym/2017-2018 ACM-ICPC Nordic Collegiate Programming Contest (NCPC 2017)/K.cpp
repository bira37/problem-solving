#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
int b,n,c;
int vb,vn,vc;
int s = 0;
int v[112345];
 
bool check(int k){
  tuple<int,int,int> ans;
  int bb = b, nn = n, cc = c;
  for(int i=0; i<s; i++){
    int bst = INF;
    //check b,b
    if(bb >= 2 && v[i]*(vb+vb) >= k && v[i]*(vb+vb) < bst){
      bst = v[i]*(vb+vb);
      ans = make_tuple(-2, 0, 0);      
    }
    //check b,n
    if(bb >= 1 && nn >= 1 && v[i]*(vb + vn) >= k && v[i]*(vb + vn) < bst){
      bst = v[i]*(vb + vn);
      ans = make_tuple(-1, -1, 0);
    }
    //check b,c
    if(bb >= 1 && cc >= 1 && v[i]*(vb + vc) >= k && v[i]*(vb + vc) < bst){
      bst = v[i]*(vb + vc);
      ans = make_tuple(-1, 0, -1);
    }
    //check n,n
    if(nn >= 2 && v[i]*(vn+vn) >= k && v[i]*(vn+vn) < bst){
      bst = v[i]*(vn+vn);
      ans = make_tuple(0, -2, 0);
    }
    //check n,c
    if(nn >= 1 && cc >= 1 && v[i]*(vn + vc) >= k && v[i]*(vn + vc) < bst){
      bst = v[i]*(vn + vc);
      ans = make_tuple(0, -1, -1);
    }
    //check c,c
    if(cc >= 2 && v[i]*(vc+vc) >= k && v[i]*(vc+vc) < bst){
      bst = v[i]*(vc+vc);
      ans = make_tuple(0, 0, -2);
    }
    if(bst == INF) return false;
    bb += get<0>(ans);
    nn += get<1>(ans);
    cc += get<2>(ans);
  }
  return true;
}
 
int32_t main(){
  DESYNC;
  cin >> b >> n >> c;
  s = (b+n+c)/2;
  cin >> vb >> vn >> vc;
  for(int i=0; i<s; i++) cin >> v[i];
  sort(v, v+s);
  int l = 0, r = (int)1e9;
  int ans = -1;
  while(l < r){
    int m = (l+r+1)/2;
    if(check(m)==0){
      r = m-1;
    }
    else l = m;
  }
  cout << l << endl;
}
 
