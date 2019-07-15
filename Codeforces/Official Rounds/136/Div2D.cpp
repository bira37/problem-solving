#include <bits/stdc++.h>

#define ff first
#define ss second
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define endl '\n'
#define pii pair<int, int>
#define pll pair<ll,ll> 
#define DESYNC_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<int>
#define vll vector<ll>
#define vpll vector< pll >
#define vpii vector< pii >

using namespace std;

typedef long long ll;

inline int mod(int n){ return (n%1000000007); } 

int cnt[112345] = {0};
int v[112345];
int n,m;

struct query{
	int id, l, r, ans;
	bool operator<(const query & b) const {
	  return l/(int)sqrt(n) < b.l/(int)sqrt(n) || l/(int)sqrt(n) == b.l/(int)sqrt(n) && r < b.r;
	}
};

struct SqrtDecomposition {

  vector<query> q;
  
  void read(int sz){
    q.resize(sz);
    for(int i=0; i<q.size(); i++){
      q[i].id = i;
      scanf("%d%d", &q[i].l, &q[i].r);
      q[i].l--;
      q[i].r--;
    }
  }
  
  int curr = 0;

  void add(int idx){
    if(v[idx] > 100000) return;
    if(cnt[v[idx]] == v[idx]) curr--;
    cnt[v[idx]]++;
    if(cnt[v[idx]] == v[idx]) curr++;
  }
  
  void remove(int idx){
    if(v[idx] > 100000) return;
    if(cnt[v[idx]] == v[idx]) curr--;
    cnt[v[idx]]--;
    if(cnt[v[idx]] == v[idx]) curr++;
  }
  
  int answer_query(){
    return curr;
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

int main(){
	scanf("%d%d", &n, &m);
	SqrtDecomposition mos;
	for(int i=0; i<n; i++){
	  scanf("%d", &v[i]);
	}
	mos.read(m);
	mos.calculate();
	mos.print_ans();
}

