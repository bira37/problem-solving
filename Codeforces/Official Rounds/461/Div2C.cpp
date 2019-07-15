#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n,k;
  cin >> n >> k;
  set<long long> s;
  for(long long i =1; i<=min(k, 1000LL); i++){
    if(s.count(n%i)){
      cout << "No" << endl;
      return 0;
    }
    s.insert(n%i);
  }
  cout << "Yes" << endl;
}