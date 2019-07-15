#include <bits/stdc++.h>

#define int long long
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

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int32_t main(){
	DESYNC;
	int n, m;
	cin >> n;
	vector<int> v(n);
	map<int,int> has,cnt;
	for(int i=0; i<n; i++){
	  cin >> v[i];
	}
	cin >> m;
	for(int i=0; i<m; i++){
	  int x;
	  cin >> x;
	  has[v[x-1]]++;
	}
	int sz = has.size();
	while(v.size() < n+5*m){ 
	  for(int i = n-2; i>=0; i--) v.pb(v[i]);
	  for(int i=1; i<n; i++) v.pb(v[i]);
	}
	set<int> possible;
	int cur = 0;
	int match = 0;
	for(int i=0; i<m; i++){
	  if(cnt[v[i]] == has[v[i]] && cnt[v[i]] > 0) match--;
	  cnt[v[i]]++;
	  if(cnt[v[i]] == has[v[i]] && cnt[v[i]] > 0) match++;
	  cur += abs(v[i] - (i-1 >= 0 ? v[i-1] : 0));
	  if(i == 0) cur -= v[i];
	  if(match == sz) possible.insert(cur);
	}
	for(int i=m; i<n+5*m; i++){
	  if(cnt[v[i-m]] == has[v[i-m]] && cnt[v[i-m]] > 0) match--;
	  cnt[v[i-m]]--;
	  if(cnt[v[i-m]] == has[v[i-m]] && cnt[v[i-m]] > 0) match++;
	  
	  if(cnt[v[i]] == has[v[i]] && cnt[v[i]] > 0) match--;
	  cnt[v[i]]++;
	  if(cnt[v[i]] == has[v[i]] && cnt[v[i]] > 0) match++;
	  
	  cur += abs(v[i] - (i-1 >= 0 ? v[i-1] : 0));
	  
	  cur -= abs(v[i-m+1] - (i-m >= 0 ? v[i-m] : 0));
	  
	  if(match == sz) possible.insert(cur);
	}
	/*if(n == 100 && v[0] == 474){
	  cout << "entrei aq" << endl;
	  for(int x : possible) cout << x << " ";
	  cout << endl;
	}*/
	if(possible.size() > 1) cout << -1 << endl;
	else if(possible.size() == 0) cout << -1 << endl;
	else cout << *possible.begin() << endl;
}