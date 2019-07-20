#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
string ans, ansr;
string s;
 
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> s;
  if(s.size() == 3){
    cout << s[0] << endl;
    return 0;
  }
  for(int l =0, r = (int)(s.size())-1; l <= r;){
    if(l == r-1 or l == r){
      ans += s[l];
      break;
    }
    if(l != r and s[l] == s[r]){
      ans += s[l];
      ansr += s[r];
      l++, r--;
    }
    else if(l+1 != r and s[l+1] == s[r]){
      ans += s[l+1];
      ansr += s[r];
      l += 2, r--;
    }
    else if(l != r-1 and s[l] == s[r-1]){
      ans += s[l];
      ansr += s[r-1];
      l++, r-=2;
    }
    else if(l +1 != r-1 and s[l+1] == s[r-1]){
      ans += s[l+1];
      ansr += s[r-1];
      l+=2, r-=2;
    }
    else l++;
  }
  reverse(ansr.begin(), ansr.end());
  cout << ans + ansr << endl;
}
 
