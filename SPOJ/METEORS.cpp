#include <bits/stdc++.h>
#define int long long
using namespace std;

struct PL{
    int l, r, m, id, want;
    PL() {}
    bool operator<(const PL & b) const {
      return m < b.m;
    }
};

struct update{
  int l, r, val;
  update() {}
  update(int l, int r, int val) : l(l), r(r), val(val) {}
};

int n, m;

int bit[312345];

void init(int n){
	for(int i=0; i<=n; i++){
		bit[i] = 0;
	}
}

void add(int idx, int val, int n){
	for(int i = idx; i <= n; i += i&-i){
		bit[i]+=val;
	}
}

int query(int idx){
	int ans = 0;
	for(int i=idx; i>0; i -= i&-i){
		ans += bit[i];
	}
	return ans;
}

vector<int> own[312345];
PL state[312345];
update upd[312345];
int ans[312345];

int32_t main(){
  scanf("%lld%lld", &n, &m);
  for(int i=0; i<m; i++){
    int x;
    scanf("%lld", &x);
    own[x-1].push_back(i+1);
  }
  for(int i=0; i<n; i++){
    scanf("%lld", &state[i].want);
  }
  int q;
  scanf("%lld", &q);
  for(int i=0; i<n; i++){
    state[i].l = 0;
    state[i].r = q-1;
    state[i].m = (state[i].l+state[i].r)>>1;
    state[i].id = i;
    ans[i] = 512345;
  }
  
  for(int i=0; i<q; i++){
    scanf("%lld%lld%lld", &upd[i].l, &upd[i].r, &upd[i].val);
  }
  
  //do parallel
  for(int it = 0; it < 19; it++){
    //cout << "iteration " << it << endl;
    init(312344);
    //for(int i=0; i<=4*m; i++) st[i] = node(0,0);
    sort(state, state+n);
    int u = 0;
    for(int i=0; i<n; i++){
      
      for(; u<q && u <= state[i].m; u++){
        if(upd[u].l > upd[u].r){
          add(upd[u].l, upd[u].val, 312344);
          add(m+1, -upd[u].val, 312344);
          add(1, upd[u].val, 312344);
          add(upd[u].r+1, -upd[u].val, 312344);
        }
        else {
        	add(upd[u].l, upd[u].val, 312344);
        	add(upd[u].r+1, -upd[u].val, 312344);
        }
      }
      
      long long sum = 0;
      for(int idx : own[state[i].id]){
        sum += query(idx);
        if(sum >= state[i].want) break;
      }
      //cout << "sum and want for " << state[i].id+1 << " = " << sum << " " << state[i].want << " considering " << state[i].m+1 << " queries " << endl;
      if(sum >= state[i].want){
        ans[state[i].id] = min(ans[state[i].id], state[i].m);
        state[i].r = state[i].m-1;
      }
      else state[i].l = state[i].m+1;
      state[i].m = (state[i].l+state[i].r)>>1;
    }
  }
  
  for(int i=0; i<n; i++){
  	if(ans[i] == 512345) printf("NIE\n");
  	else printf("%lld\n", ans[i]+1);
  }
  
}
