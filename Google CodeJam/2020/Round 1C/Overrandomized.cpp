#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

void solve(vector<string>& qs, vector<string>& nums) {
  set<char> occ;
  map<char, int> frq;
  for (int i = 0; i < 10000; i++) {
    string t;
    t = nums[i];
    for (char c : t) {
      occ.insert(c);
      occ.insert(c);
    }
    frq[t.front()]++;
  }
  vector<pair<int, char> > v;
  for (auto p : frq) {
    v.pb(mp(p.ss, p.ff));
    occ.erase(p.ff);
  }
  for (char c : occ) v.pb(ii(INF, c));
  sort(all(v), greater<pair<int, char> >());
  for (auto p : v) cout << p.ss;
  cout << endl;
}

void solution(int testcase) {
  cout << "Case #" << testcase << ": ";
  int mx[26];
  int u;
  cin >> u;
  for (int i = 0; i < 26; i++) {
    mx[i] = INF;
  }
  set<char> occ;
  vector<string> qs(10000);
  vector<string> nums(10000);
  for (int i = 0; i < 10000; i++) {
    cin >> qs[i] >> nums[i];
  }
  solve(qs, nums);
}

int32_t main() {
  srand(time(NULL));
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++)
    solution(_testcase);
}

