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

int q;

char make_query(int id) {
  cout << id + 1 << endl;
  cout.flush();
  char c;
  cin >> c;
  q++;
  return c;
}

void check_all(string& s, int B, ii p1, ii p2) {
  int x1, x2, x3, x4, y1, y3;
  x1 = p1.ff;
  x2 = p1.ss;
  x3 = p2.ff;
  x4 = p2.ss;
  y1 = make_query(x1);
  y3 = make_query(x3);

  if (s[x2] == y1 && s[x4] == y3) {
    reverse(s.begin(), s.end());
  } else if (s[x2] != y1 && s[x4] != y3) {
    reverse(s.begin(), s.end());
    for (char& c : s) {
      if (c == '0')
        c = '1';
      else
        c = '0';
    }
  } else if (s[x1] != y1 && s[x3] != y3) {
    for (char& c : s) {
      if (c == '0')
        c = '1';
      else
        c = '0';
    }
  }
}

void check_one(string& s, int B, ii p) {
  int l = p.ff, r = p.ss;
  int fst = make_query(l);
  int lst = make_query(r);

  if (s[l] != fst && s[r] != lst) {
    for (char& c : s) {
      if (c == '0')
        c = '1';
      else
        c = '0';
    }
  }
}

void verify(string& s, int B, map<int, ii> m) {
  int x1, x2, x3, x4, y1, y2, y3, y4;
  if (m.count(0) && m.count(1))
    check_all(s, B, m[0], m[1]);
  else if (m.count(0))
    check_one(s, B, m[0]);
  else if (m.count(1))
    check_one(s, B, m[1]);
}

void real_run(int B) {
  string s;
  for (int i = 0; i < B; i++) s += '0';
  map<int, pair<int, int> > m;
  q = 0;
  for (int l = 0, r = B - 1; l < r; l++, r--) {
    // make l

    if (q != 0 && q % 10 == 0) {
      verify(s, B, m);
    }

    s[l] = make_query(l);

    if (q != 0 && q % 10 == 0) {
      verify(s, B, m);
    }

    // make r
    s[r] = make_query(r);

    if (s[l] == s[r])
      m[0] = ii(l, r);
    else
      m[1] = ii(l, r);
  }
  cout << s << endl;
  cout.flush();
  char verdict;
  cin >> verdict;
  if (verdict == 'Y')
    return;
  else
    exit(0);
}

void run(int test_num, int B) { real_run(B); }

int32_t main() {
  srand(time(0));
  int t, b;
  cin >> t >> b;
  for (int i = 1; i <= t; i++) run(i, b);
}

