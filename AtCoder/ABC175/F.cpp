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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M)
{
  int ret = n % m;
  if (ret < 0)
    ret += m;
  return ret;
}

int exp(int n, int k)
{
  if (k == 0)
    return 1;
  if (k == 1)
    return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2)
    ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

bool ok(string a, string b)
{
  int mn = min(a.size(), b.size());
  reverse(all(b));
  bool oks = true;
  for (int i = 0; i < mn; i++)
  {
    if (a[i] != b[i])
      oks = false;
  }
  return oks;
}

tuple<string, string> calc(string a, string b)
{
  //cout << a << " | " << b << " makes ";
  string s, t;
  if (a.size() < b.size())
  {
    reverse(all(b));
    for (int i = a.size(); i < b.size(); i++)
      t += b[i];
    reverse(all(t));
  }
  else if (b.size() < a.size())
  {
    for (int i = b.size(); i < a.size(); i++)
      s += a[i];
  }
  //cout << s << " | " << t << endl;
  return mt(s, t);
}

bool palin(string &s)
{
  string t = s;
  reverse(all(t));
  return s == t;
}
//#define MULTIPLE_TEST_CASE
void solution()
{
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i] >> c[i];
  }
  using pss = pair<string, string>;

  map<pss, int> dist;
  set<pair<int, pss>> pq;
  for (int i = 0; i < n; i++)
  {
    if (!dist.count(mp(s[i], "")))
      dist[mp(s[i], "")] = INF;
    if (!dist.count(mp("", s[i])))
      dist[mp("", s[i])] = INF;
    dist[mp(s[i], "")] = min(dist[mp(s[i], "")], c[i]);
    dist[mp("", s[i])] = min(dist[mp("", s[i])], c[i]);
    pq.insert(mp(c[i], mp("", s[i])));
    pq.insert(mp(c[i], mp(s[i], "")));
  }

  while (!pq.empty())
  {
    int cur = pq.begin()->ff;
    string pre = pq.begin()->ss.ff;
    string suf = pq.begin()->ss.ss;
    pq.erase(pq.begin());
    if (dist[mp(pre, suf)] != cur)
      continue;

    //cout << "dist " << pre << " | " << suf << " = " << cur << endl;
    if (pre == "")
    {
      // append prefix
      for (int i = 0; i < n; i++)
      {
        if (!ok(s[i], suf))
          continue;
        string new_pre, new_suf;
        tie(new_pre, new_suf) = calc(s[i], suf);
        if (!dist.count(mp(new_pre, new_suf)))
          dist[mp(new_pre, new_suf)] = INF;
        if (cur + c[i] < dist[mp(new_pre, new_suf)])
        {
          dist[mp(new_pre, new_suf)] = cur + c[i];
          pq.insert(mp(cur + c[i], mp(new_pre, new_suf)));
        }
      }
    }
    else
    {
      // append suffix
      for (int i = 0; i < n; i++)
      {
        if (!ok(pre, s[i]))
          continue;
        string new_pre, new_suf;
        tie(new_pre, new_suf) = calc(pre, s[i]);
        if (!dist.count(mp(new_pre, new_suf)))
          dist[mp(new_pre, new_suf)] = INF;
        if (cur + c[i] < dist[mp(new_pre, new_suf)])
        {
          dist[mp(new_pre, new_suf)] = cur + c[i];
          pq.insert(mp(cur + c[i], mp(new_pre, new_suf)));
        }
      }
    }
  }

  int ans = INF;
  for (auto state : dist)
  {
    string a = state.ff.ff;
    string b = state.ff.ss;
    bool ok = false;
    ok |= (a.size() == 0 && b.size() == 0);
    ok |= (a.size() == 0 && palin(b));
    ok |= (b.size() == 0 && palin(a));
    if (ok)
      ans = min(ans, state.ss);
  }
  cout << (ans < INF ? ans : -1) << endl;
}

int32_t main()
{
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--)
    solution();
}
