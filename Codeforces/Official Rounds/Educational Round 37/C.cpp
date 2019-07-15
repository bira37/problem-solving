#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  int v[n];
  for(int i=0; i<n; i++) cin >> v[i];
  vector< pair<int,int> > to_sort;
  int l = -1;
  for(int i=0; i<n-1; i++){
    char c;
    cin >> c;
    if(c == '1'){
      if(l == -1) l = i;
    }
    else {
      if(l != -1) sort(v+l, v+i+1);
      l = -1;
    }
  }
  if(l!=-1 && l < n) sort(v+l, v+n);
  //cout << "alameda" << endl;
  bool ordered = true;
  for(int i=1; i<n; i++) if(v[i-1] > v[i]) ordered = false;
  if(ordered) cout << "YES" << endl;
  else cout << "NO" << endl;
}