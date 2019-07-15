#include <bits/stdc++.h>
#define int long long
using namespace std;

int d[1123456] = {0};
int n,q;
int st[4*312345] = {0};
int ok[4*312345] = {0};

void build(int curr = 1, int l= 0 , int r = n -1 ){
  if(l == r){
    int x;
    scanf("%lld", &x);
    st[curr] = x;
    ok[curr] = (st[curr] <= 2);
    return;
  }
  int m = (l+r)>>1;
  build(2*curr, l, m);
  build(2*curr+1, m+1, r);
  st[curr] = st[2*curr] + st[2*curr+1];
  ok[curr] = ok[2*curr] + ok[2*curr+1];
}

void replace(int a, int b, int curr = 1, int l = 0, int r = n-1){
  if(ok[curr] == (r-l)+1) return;
  if(l == r){
    st[curr] = d[st[curr]];
    ok[curr] = (st[curr] <= 2);
    return;
  }
  int m = (l+r)>>1;
  if(b <= m) replace(a, b, 2*curr, l, m);
  else if(m < a) replace(a, b, 2*curr+1, m+1, r);
  else {
    replace(a, m, 2*curr, l, m);
    replace(m+1, b, 2*curr+1, m+1 , r);
  }
  st[curr] = st[2*curr] + st[2*curr+1];
  ok[curr] = ok[2*curr] + ok[2*curr+1];
}

int query(int a, int b, int curr = 1, int l = 0, int r = n-1){
  if(l == a && r == b) return st[curr];
  int m = (l+r)>>1;
  if(b <= m) return query(a, b, 2*curr, l, m);
  else if(m < a) return query(a, b, 2*curr+1, m+1, r);
  else return query(a, m, 2*curr, l, m) + query(m +1, b, 2*curr+1, m+1, r);
}

int32_t main(){
  d[0] = 0;
  for(int i=1; i<=1123456; i++){
    for(int j=i; j<=1123456; j+=i) d[j]++;
  }
  scanf("%lld%lld", &n, &q);
  build();
  while(q--){
    int op, a, b;
    scanf("%lld%lld%lld", &op, &a, &b);
    a--,b--;
    if(op == 1) replace(a, b);
    else printf("%lld\n", query(a,b));
  }
  
}