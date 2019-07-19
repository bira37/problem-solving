#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pii pair<int, int>

using namespace std;

struct line{
  int id, a, b;
  line() {}
  line(int id, int a, int b) : id(id), a(a), b(b) {}
};

vector<line> cht;
int x[1123456];
int sum[1123456];
int dp[1123456];
int a,b,c;

bool cmp(const line & a, const line & b){
	return (a.a < b.a || (a.a == b.a && a.b > b.b));
} 

bool remove(line & a, line & b, line & c){
	if((a.a - c.a)*(c.b - b.b) <= (b.a - c.a)*(c.b - a.b)) return true;
	else return false;
}

void add(line & v){
	if(cht.empty()){
	  cht.push_back(v);
	}
	else {
		if(cht.back().a == v.a) return;
		while(cht.size() > 1 && remove(cht[cht.size()-2], cht.back(), v)){
		  cht.pop_back();
		}
		cht.push_back(v);
	}
}

void preprocess_cht(vector< line > & v){
  sort(v.begin(), v.end(), cmp);
  cht.clear();
  for(int i=0; i<v.size(); i++){
    add(v[i]);
  }
}

int cost(int i){
  return a*(sum[i])*(sum[i]) + b*(sum[i]) + c;
}

int f(int i, int x){
  return cht[i].a*x + cht[i].b;
}

int get_max(int x){
  if(cht.size() == 0) return -1;
  if(cht.size() == 1) return 0;
  int l = 0, r = cht.size()-2;
  int ans= cht.size()-1;
  while(l <= r){
    int m = (l+r)/2;
    int y1 = f(m, x);
    int y2 = f(m+1, x);
    if(y1 >= y2){
      ans = m;
      r = m-1;
    }
    else l = m+1;
  }
  return ans;
}

int32_t main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cin >> a >> b >> c;
    sum[0] = 0;
    for(int i=1; i<=n; i++){
      cin >> x[i];
      sum[i]= sum[i-1] + x[i];
    }
    cht.clear();
    dp[0] = 0;
    for(int i=1; i<=n; i++){
      dp[i] = cost(i);
      //cout << "solve for " << i  << endl;
      int j = get_max(-2*a*sum[i]);
      //if(j != -1) cout << "max j is " << j << " " << cht[j].id << endl;
      //if(j != -1) cout << f(j, -2*a*sum[i]) << " " << dp[cht[j].id-1] << " " << cost(i) << endl;
      if(j != -1) dp[i] = max(dp[i], f(j, -2*a*sum[i]) + cost(i));
      line new_line;
      new_line.a = sum[i];
      new_line.b = -b*sum[i]+a*sum[i]*sum[i] + dp[i];
      new_line.id = i;
      add(new_line);
      //cout << "ans is " << dp[i] << endl;
    }
    cout << dp[n] << endl;
  }
}

