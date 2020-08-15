#include <bits/stdc++.h>

#define endl "\n"
#define double long double
#define ff first
#define ss second
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
#define INF 1e9 + 15
#define ROOT 1
#define M 1000000007
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

#define CANCER_PROBLEM THIS_PROBLEM

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

namespace PersistentSegmentTree
{

  struct Node
  {
    Node *left, *right;
    int x;
    Node()
    {
      left = nullptr;
      right = nullptr;
      x = 0;
    }

    Node(Node *n)
    {
      left = n->left;
      right = n->right;
      x = n->x;
    }
  };

  Node *update(Node *cur, int l, int r, int x, int val)
  {
    assert(cur != nullptr);
    Node *new_cur = new Node(cur);
    if (l == r)
    {
      new_cur->x += val;
      return new_cur;
    }

    int m = (l + r) >> 1;
    if (x <= m)
    {
      if (!new_cur->left)
        new_cur->left = new Node();
      new_cur->left = update(new_cur->left, l, m, x, val);
    }
    else
    {
      if (!new_cur->right)
        new_cur->right = new Node();
      new_cur->right = update(new_cur->right, m + 1, r, x, val);
    }
    new_cur->x = (new_cur->left ? new_cur->left->x : 0) +
                 (new_cur->right ? new_cur->right->x : 0);
    return new_cur;
  }

  int query(Node *cur, int l, int r, int a, int b)
  {
    assert(cur != nullptr);
    if (r < a || b < l)
      return 0;
    if (a <= l and r <= b)
      return cur->x;
    int m = (l + r) >> 1;
    int ansl = 0, ansr = 0;
    if (cur->left)
      ansl = query(cur->left, l, m, a, b);
    if (cur->right)
      ansr = query(cur->right, m + 1, r, a, b);
    return ansl + ansr;
  }

}; // namespace PersistentSegmentTree

PersistentSegmentTree::Node *st[112345], *more_cancer[112345];

map<string, int> idx;

int get(string s)
{
  if (!idx.count(s))
  {
    int l = idx.size() + 1;
    idx[s] = l;
  }
  return idx[s];
}

//#define MULTIPLE_TEST_CASE
void solution()
{
  int q;
  cin >> q;
  st[0] = new PersistentSegmentTree::Node();
  more_cancer[0] = new PersistentSegmentTree::Node();
  int lim = 1e9 + 10;
  int lim2 = q + 10;
  int it = 0;
  for (int it = 1; it <= q; it++)
  {
    string type;
    cin >> type;
    if (type == "set")
    {
      st[it] = st[it - 1];
      more_cancer[it] = more_cancer[it - 1];
      string a;
      int b;
      cin >> a >> b;
      int id = get(a);
      int val = PersistentSegmentTree::query(more_cancer[it], 1, lim2, id, id);
      if (val)
      {
        st[it] = PersistentSegmentTree::update(st[it], 1, lim, val, -1);
      }
      more_cancer[it] = PersistentSegmentTree::update(more_cancer[it], 1, lim2, id, -val);
      more_cancer[it] = PersistentSegmentTree::update(more_cancer[it], 1, lim2, id, b);
      st[it] = PersistentSegmentTree::update(st[it], 1, lim, b, 1);
    }
    else if (type == "query")
    {
      string a;
      cin >> a;
      st[it] = st[it - 1];
      more_cancer[it] = more_cancer[it - 1];
      int id = get(a);
      int val = PersistentSegmentTree::query(more_cancer[it], 1, lim2, id, id);
      if (!val)
        cout << -1 << endl;
      else
        cout << PersistentSegmentTree::query(st[it], 1, lim, 1, val - 1) << endl;
      cout.flush();
    }
    else if (type == "undo")
    {
      int steps;
      cin >> steps;
      st[it] = st[it - steps - 1];
      more_cancer[it] = more_cancer[it - steps - 1];
    }
    else
    {
      string a;
      cin >> a;
      st[it] = st[it - 1];
      more_cancer[it] = more_cancer[it - 1];
      int id = get(a);
      int val = PersistentSegmentTree::query(more_cancer[it], 1, lim2, id, id);
      if (val)
      {
        st[it] = PersistentSegmentTree::update(st[it], 1, lim, val, -1);
        more_cancer[it] = PersistentSegmentTree::update(more_cancer[it], 1, lim2, id, -val);
      }
    }
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

