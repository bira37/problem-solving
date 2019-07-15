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

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  int qtd = n/3;
  map<char, int> cnt;
  string s;
  cin >> s;
  for(char c : s) cnt[c]++;
  for(char & c : s){
    if(cnt['0'] < qtd && c != '0' &&  cnt[c] > qtd){
      cnt[c]--;
      c = '0';
      cnt[c]++;
    }
  }
  int contazerocu = 0;
  for(char & c : s){
    if(cnt['1'] < qtd && c != '1' &&  cnt[c] > qtd && (c != '0' || contazerocu >= qtd)){
      cnt[c]--;
      c = '1';
      cnt[c]++;
    }
    if(c == '0') contazerocu++;
  }
  contazerocu = 0;
  int contaumcu = 0;
  for(char & c : s){
    if(cnt['2'] < qtd && c != '2' &&  cnt[c] > qtd && (c == '0' && contazerocu >= qtd)){
      cnt[c]--;
      c = '2';
      cnt[c]++;
    }
    else if(cnt['2'] < qtd && c != '2' &&  cnt[c] > qtd && (c == '1' && contaumcu >= qtd)){
      cnt[c]--;
      c = '2';
      cnt[c]++;
    }
    if(c == '0') contazerocu++;
    if(c == '1') contaumcu++;
  }
  cout << s << endl;
}

