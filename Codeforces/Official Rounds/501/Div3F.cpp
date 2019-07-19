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
 
string s;
int n;
 
struct KMP{
  vector<int> pi;
  
  vector<int> matches;
  
  string t;
  
  KMP() {}
 
  void calculate(string t) {
  	this->t = t;
    int n = t.size();
    pi.resize(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++) {
      pi[i] = pi[i-1];
      while(pi[i] > 0 && t[i] != t[pi[i]]) pi[i] = pi[pi[i]-1];
      if(t[i] == t[pi[i]]) pi[i]++;
    }
  }
 
  void matching(string s){
    int j = 0;
    int n = s.size();
    for(int i=0; i<n; i++){
      while(j > 0 && s[i] != t[j]) j = pi[j-1];
      if(s[i] == t[j]) j++;
      if(j == t.size()){
        matches.push_back(i-t.size()+1);
        j = pi[j-1];
      }
    }
  }
  
};
 
KMP kmp;
 
int dp[205][205][205][2];
 
int solve(int i, int j, int k, bool used){
	//base case
	if(i == 0){
		if(k == 0 && used) return 1;
		else return 0;
	}
	if(dp[i][j][k][used] != -1) return dp[i][j][k][used];
	dp[i][j][k][used] = 0;
	if(k > 0){
		int j2 = j;
		bool used2 = used;
		while(j2 > 0 && ')' != s[j2]) j2 = kmp.pi[j2-1];
		if(')' == s[j2]) j2++;
		if(j2 == s.size()){
			used2 = true;
			j2 = kmp.pi[j2-1];
		}
		dp[i][j][k][used] = mod(dp[i][j][k][used] + solve(i-1, j2, k-1, used2), M);
	}
	int j2 = j;
	bool used2 = used;
	while(j2 > 0 && '(' != s[j2]) j2 = kmp.pi[j2-1];
	if('(' == s[j2]) j2++;
	if(j2 == s.size()){
		used2 = true;
		j2 = kmp.pi[j2-1];
	}
	dp[i][j][k][used] = mod(dp[i][j][k][used] + solve(i-1, j2, k+1, used2), M);
	return dp[i][j][k][used];
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	cin >> s;
	kmp.calculate(s);
	cout << solve(2*n, 0, 0, false) << endl;
}
