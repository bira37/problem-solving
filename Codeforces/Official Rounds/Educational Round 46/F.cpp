#include <bits/stdc++.h>
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
 
int cnt[512345] = {0};
bool ok[512345] = {0};
int v[512345];
vector<int> cand;
 
int n;
int bl;
struct query{
	int id, l, r, ans;
	/*bool operator<(const query & b) const {
	  return l/(int)sqrt(n) < b.l/(int)sqrt(n) || l/(int)sqrt(n) == b.l/(int)sqrt(n) && r < b.r;
	}*/
	bool operator<(const query & b) const{
		if(l/bl != b.l/bl) return l < b.l;
		else if(l/bl & 1) return r < b.r;
		else return r > b.r;
	} 
};
 
struct SqrtDecomposition {
 
  vector<query> q;
 
  void init(int n){
  	q.resize(n);
  }
 
  void add(int idx){
    cnt[v[idx]]++;
    if(cnt[v[idx]] == 1 && !ok[v[idx]]) ok[v[idx]] = true, cand.pb(v[idx]);
  }
 
  void remove(int idx){
    cnt[v[idx]]--;
    if(cnt[v[idx]] == 1 && !ok[v[idx]]) ok[v[idx]] = true, cand.pb(v[idx]);
  }
 
  int answer_query(){
    while(cand.size() > 0 && cnt[cand.back()] != 1) ok[cand.back()] = false, cand.pop_back();
    return cand.size() == 0 ? 0 : cand.back();
  }
 
  void calculate(){
	  sort(q.begin(), q.end());
	  int l = 0, r = -1;
	  for(int i=0; i<q.size(); i++){
		  while(q[i].l < l) add(--l);
		  while(r < q[i].r) add(++r);
		  while(q[i].l > l) remove(l++);
		  while(r > q[i].r) remove(r--);
		  q[i].ans = answer_query();
	  }
  }
 
  void print_ans(){
    sort(q.begin(), q.end(), [](const query & a, const query & b){
      return a.id < b.id;
    });
 
    for(query x : q){
      printf("%d\n", x.ans);
    }
  }
};
 
int32_t main(){
	scanf("%d", &n);
	bl = sqrt(n);
	for(int i=0; i<n; i++) scanf("%d", v+i);
	int q;
	scanf("%d", &q);
	SqrtDecomposition mos;
	mos.init(q);
	for(int i=0; i<q; i++){
	  scanf("%d%d", &mos.q[i].l, &mos.q[i].r);
	  mos.q[i].l--;
	  mos.q[i].r--;
	  mos.q[i].id = i;
	}
	mos.calculate();
	mos.print_ans();
}
