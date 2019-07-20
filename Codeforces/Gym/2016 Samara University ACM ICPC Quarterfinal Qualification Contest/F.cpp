#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
tuple<int,int,int,int> v[212345];
 
bool cmp(const tuple<int,int,int,int> & x, const tuple<int,int,int,int> & y){
  int xa,xb,xc,xid,ya,yb,yc,yid;
  tie(xa,xb,xc,xid) = x;
  tie(ya,yb,yc,yid) = y;
  
  int cnt = 0;
  cnt += xa > ya;
  cnt += xb > yb;
  cnt += xc > yc;
  
  return cnt < 2;
}
 
int main(){
  int n;
  cin >> n;
  tuple<int,int,int,int> v[n];
  for(int i=0; i<n; i++){
    int a,b,c;
    cin >> a >> b >> c;
    v[i] = make_tuple(a,b,c,i+1);
  }
  sort(v, v+n, cmp);
  
  bool flag = true;
  for(int i=1; i<n; i++){
    if(cmp(v[i], v[0])) flag = false;
  }
  if(!flag) cout << 0 << endl;
  else cout << 1 << endl << get<3>(v[0]) << endl;
}
