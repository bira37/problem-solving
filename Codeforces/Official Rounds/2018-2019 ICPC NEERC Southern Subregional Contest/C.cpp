/*

    Topics:
        - 
        - 

    From:
        - 
*/

#include <bits/stdc++.h>
 
using namespace std;
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
// #define INTASLONG
// #ifdef INTASLONG
    #define int long long
    // #define INT_MAX LLONG_MAX
    // #define INT_MIN LLONG_MIN
// #endif
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define m0(x) memset((x), 0, sizeof(x))
#define m1(x) memset((x), -1, sizeof(x))
#define INF (int)1e9
// #define DEBUG
#ifdef DEBUG
    #define debug(x) cout << x
#else
    #define debug(x) do {} while(0)
#endif

typedef pair<int,int> ii;
typedef vector< int > vi;
typedef vector< ii > vii;
 
int _gcd(int a, int b) { return b == 0 ? a : _gcd(b, a%b); }
int gcd(int a, int b) { return _gcd(abs(a), abs(b)); }

int32_t main() {
  DESYNC;
    
  int n, m, k;
  cin >> n >> k >> m;
  
  tuple<int, int, int, int> off[m];
  

  for(int i = 0; i < m; i++) {
      int l,r,c,p; 
    cin >> l >> r >> c >> p;
    off[i] = make_tuple(l,r,c,p);
  }
  
  sort(off, off+m);
  
  // P, I, X
  multiset< tuple<int,int,int> , greater< tuple<int,int,int> > > use;
  multiset< tuple<int,int,int> > dis;
  int tot = 0;
  int cost = 0;
  int ans = 0;
  
  // R, P, I
  multiset< tuple<int, int, int> > rem;
  
  int ll = 0;
  int j = 0;
  for(int i = 1; i <= n; i++) {
    //cout << "DAY " << i << endl;
    //int kk = k*(l-ll);
    
    /*for(auto it : use) {
      int dp,did,dx;
      tie(dp,did,dx) = it;
      cout << "Use has " << dp << " " << did << " " << dx << endl;
    }
    
    for(auto it : dis) {
      int dp,did,dx;
      tie(dp,did,dx) = it;
      cout << "Dis has " << dp << " " << did << " " << dx << endl;
    }*/
        
    // Remove all unavaliable offers
    while(!rem.empty()) {
      int re, pe, ide;
      tie(re, pe, ide) = *rem.begin();
      if(re >= i) break;
      //cout << "remove all " << re << " " << pe << " " << ide << endl;
      set< tuple<int,int,int> >::iterator it;
      while(it = use.lower_bound(make_tuple(pe, ide, INF)), it != use.end() && get<1>(*it) == ide) {
        int dp,did,dx;
        tie(dp,did,dx) = *it;
        //cout <<"Rem " <<  dp << " " << did << " " << dx << endl;
        use.erase(it);
        cost -= dx*dp;
        tot -= dx;
      }
      while(it = dis.lower_bound(make_tuple(pe, ide, 0)), it != dis.end() && get<1>(*it) == ide) {
        dis.erase(it);
      }
      
      rem.erase(rem.begin());
    }
    
    //cout << "Cost/tot before " << cost << "/" << tot << endl;
    
    for(; j < m; j++) {
      int l,r,c,p;
      tie(l,r,c,p) = off[j];
      //cout << endl;
      if(l > i) break;
      //cout << "Inserting " << l << " "<< r << " " << c << " "<< p << endl;
      dis.insert(make_tuple(p, j, c));
      rem.insert(make_tuple(r,p,j));
    }
        
    // Complete use with k-tot from dis
    while(tot < k && !dis.empty()) {
      set< tuple<int,int,int> >::iterator it = dis.begin();
      int dp,did,dx;
      tie(dp,did,dx) = *it;
      //cout << "available " << dp << " " << did << " " << dx << " " << endl;
      if(dx > k-tot) {
        int put = k - tot;
        //cout << "putting " << put << endl;
        use.insert(make_tuple(dp,did,put));
        cost += (put)*dp;
        tot += (put);
        
        dis.erase(it);
        dis.insert(make_tuple(dp,did,dx-(put)));
      } else {
        use.insert(make_tuple(dp,did,dx));
        cost += dx*dp;
        tot += dx;
        dis.erase(it);
      }
    }
    
    //cout << "Update..." << endl;
    while(!use.empty() && !dis.empty()) {
      int up, uid, ux;
      tie(up, uid, ux) = *use.begin();
      
      int dp, did, dx;
      tie(dp, did, dx) = *dis.begin();
      
      //cout <<"-> " <<  up << " " << uid << " " << ux << endl;
      //cout <<"-> " <<  dp << " " << did << " " << dx << endl;
      
      if(up <= dp) break;
        
      if(dx > ux) {
        use.erase(use.begin());
        cost -= ux*up;
        tot -= ux;
        dis.erase(dis.begin());
        
        use.insert(make_tuple(dp,did,ux));
        cost += ux*dp;
        tot += ux;
        
        dis.insert(make_tuple(dp,did,dx-ux));
        dis.insert(make_tuple(up,uid,ux));
      } else {
        use.erase(use.begin());
        cost -= ux*up;
        tot -= ux;
        dis.erase(dis.begin());
        
        use.insert(make_tuple(dp,did,dx));
        cost += dx*dp;
        tot += dx;
        
        if(ux-dx > 0) use.insert(make_tuple(up,uid,ux-dx));
        cost += (ux-dx)*up;
        tot += (ux-dx);
        
        dis.insert(make_tuple(up,uid,dx));
      }
      
      //cout << "new cost = " << cost << endl;
    }
    
    ans += cost;
    //cout << "cost " << cost << endl;
    
    /*
    //cout << "bla" << endl;
    
    // Evalute rand ll -> i-1
    if(ll <= i) {
      ans += cost;
      ll = i;
    }
    
    // Update use and dis with new offer
    int res = c;
    if(tot < kk) {
      use.insert(make_tuple(p, i, min(kk-tot, c)));
      cost += min(kk-tot, c)*p;
      tot += min(kk-tot, c);
      res -= min(kk-tot, c);
    }
    while(!use.empty() && res) {
      set< tuple<int,int,int> >::iterator it = use.begin();
      int dp,did,dx;
      tie(dp,did,dx) = *it;
      if(dp <= p) break;
      if(dx > res) {
        dis.insert(make_tuple(dp,did,res));
        use.erase(it);
        cost -= dx*dp;
        tot -= dx;
        
        use.insert(make_tuple(dp,did,dx-res));
        cost += (dx-res)*dp;
        tot += (dx-res);
        
        use.insert(make_tuple(p, i, res));
        cost += res*dp;
        tot += res;
        
        res = 0;
      } else {
        dis.insert(make_tuple(dp,did,dx));
        use.erase(it);
        cost -= dx*dp;
        tot -= dx;
        
        use.insert(make_tuple(p, i, dx));
        cost += dx*dp;
        tot += dx;
        
        res -= dx;
      }
    }
    // add new offer to dis if remaining
    if(res) {
      dis.insert(make_tuple(p,i,res));
    }
    rem.insert(make_tuple(r,p,i));
    cout << ans << endl;
  }*/
  }
  cout << ans << endl;
}