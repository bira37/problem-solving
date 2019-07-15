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

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  if(b == 1) return b;
  else return gcd(b, a%b);
}

struct Event{
  int type;
  int p;
  Event() {}
  Event(int t, int point) : type(t), p(point) {}
  bool operator<(const Event & e) const {
    return p < e.p || (p == e.p && type < e.type);
  }
};

vector<int> ans(212345);

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	vector<Event> event;
	set<int> s;
	for(int i=0; i<n; i++){
	  int l, r;
	  cin >> l >> r;
	  event.pb(Event(0, l));
	  event.pb(Event(2, r));
	  s.insert(r);
	}
	for(int x : s) event.pb(Event(1, x));
	sort(event.begin(), event.end());
	int cnt = 0;
	int last = -1;
	for(Event e : event){
	  //cout << "at " << e.type << " " << e.p << " " << cnt << endl;
	  if(e.type == 0){
	    if(last == -1) last = e.p;
	    else {
	      if(last != e.p) ans[cnt] += (e.p - last);
	      last = e.p;
	    }
	    cnt++;
	  }
	  else if(e.type == 2){
	    cnt--;
	  }
	  else if(e.type == 1){
	    ans[cnt] += (e.p - last+1);
	    last = e.p+1;
	  }
	}
	for(int i = 1; i<=n; i++){
	  if(i > 1) cout << " ";
	  cout << ans[i];
	}
	cout << endl;
	  
}

