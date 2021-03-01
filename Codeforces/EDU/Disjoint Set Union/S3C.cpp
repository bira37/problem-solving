#include <bits/stdc++.h>

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
#define INF 2e18
#define ROOT 1
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);
const int M = 1000000007;

using namespace std;

struct RollbackDsu
{
  int uf[312345];
  int sz[312345];
  stack<pair<int *, int>> history;
  RollbackDsu() {}
  RollbackDsu(int n)
  {
    rep(i, 0, n + 1, 1)
    {
      uf[i] = i;
      sz[i] = 1;
    }
  }

  int find(int u)
  {
    if (uf[u] == u)
      return u;
    else
      return find(uf[u]);
  }

  bool merge(int a, int b)
  {
    int x = find(a);
    int y = find(b);
    if (x == y)
      return false;
    if (sz[x] < sz[y])
      swap(x, y);

    history.emplace(&uf[y], uf[y]);
    history.emplace(&sz[x], sz[x]);
    uf[y] = x;
    sz[x] += sz[y];

    return true;
  }

  int snapshot()
  {
    return history.size();
  }

  void rollback(int sz)
  {
    while (history.size() > sz)
    {
      *history.top().ff = history.top().ss;
      history.pop();
    }
  }
};

struct Burunduk
{
  struct Event
  {
    int l, r, u, v;
    Event() {}
    Event(int l, int r, int u, int v) : l(l), r(r), u(u), v(v) {}
  };

  vector<Event> e;
  vector<int> queries;
  vector<ii> answers;
  RollbackDsu dsu;

  Burunduk(int n)
  {
    dsu = RollbackDsu(n);
  };

  void _solve(int l, int r, vector<Event> &e, vector<int> &queries, int comps)
  {
    if (e.size() == 0)
    {
      for (int x : queries)
      {
        answers.emplace_back(x, comps);
      }
      return;
    }

    // cout << "at " << l << " " << r << " with: " << endl;
    // for (Event ev : e)
    // {
    //   cout << ev.l << " " << ev.r << " " << ev.u << " " << ev.v << endl;
    // }
    // cout << "/-----------/" << endl;
    // for (int x : queries)
    //   cout << x << " ";
    // cout << endl;
    // cout << "===> " << comps << endl;
    // cout << "//////////////////" << endl;
    int m = (l + r) >> 1;
    vector<int> lef_queries, rig_queries;
    for (int x : queries)
    {
      if (x <= m)
        lef_queries.pb(x);
      else
        rig_queries.pb(x);
    }

    // Processing [l, m]
    vector<Event> lef;
    int snap = dsu.snapshot();
    int removed = 0;
    for (Event ev : e)
    {
      if (ev.l <= l && m <= ev.r)
      {
        removed += dsu.merge(ev.u, ev.v);
      }
      else if (ev.l <= m)
        lef.pb(ev);
    }

    _solve(l, m, lef, lef_queries, comps - removed);
    dsu.rollback(snap);

    // Processing [m+1, r]
    snap = dsu.snapshot();
    removed = 0;
    vector<Event> rig;
    for (Event ev : e)
    {
      if (ev.l <= m + 1 && r <= ev.r)
      {
        removed += dsu.merge(ev.u, ev.v);
      }
      else if (ev.r >= m + 1)
        rig.pb(ev);
    }

    _solve(m + 1, r, rig, rig_queries, comps - removed);
    dsu.rollback(snap);
  }

  void solve(int l, int r, int start)
  {
    _solve(l, r, e, queries, start);
  }
};

void solution()
{
  int n, q;
  cin >> n >> q;
  Burunduk b = Burunduk(n);
  map<ii, int> lef;
  rep(i, 0, q, 1)
  {
    char op;
    cin >> op;
    int u, v;
    if (op == '?')
      b.queries.push_back(i);
    else if (op == '+')
    {
      cin >> u >> v;
      if (u > v)
        swap(u, v);
      b.e.push_back(Burunduk::Event(i, -1, u, v));
      lef[ii(u, v)] = b.e.size() - 1;
    }
    else
    {
      cin >> u >> v;
      if (u > v)
        swap(u, v);
      b.e[lef[ii(u, v)]].r = i;
    }
  }
  for (Burunduk::Event &ev : b.e)
  {
    if (ev.r == -1)
      ev.r = q;
  }
  b.solve(0, q - 1, n);
  for (ii x : b.answers)
  {
    cout << x.ss << endl;
  }
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
