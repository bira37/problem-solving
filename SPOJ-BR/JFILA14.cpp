#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  list<int> l;
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    l.push_back(x);
  }
  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    int k;
    cin >> k;
    list<int>::iterator it = find(l.begin(), l.end(), k);
    if(it != l.end()) l.erase(it);
  }
  for(list<int>::iterator it = l.begin(); it != l.end(); it++){
    if(it != l.begin()) cout << " ";
    cout << *it;
  }
  cout << endl;
}
