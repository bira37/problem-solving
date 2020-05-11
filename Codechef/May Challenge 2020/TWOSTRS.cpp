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
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;
typedef long long ll;

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

class AhoCorasick {
public:
    const static int ALPHABET_SIZE = 26;

    struct Vertex {
      std::array<int, ALPHABET_SIZE> next;
      int p = -1;
      char pch;
      int depth = 0;
      int link = 0;
      int next_terminal = 0;
      std::array<int, ALPHABET_SIZE> go;
      bool terminal = false;

      // extra values
      int value = 0;
      ll value_acc = 0;
      // vector< pair<ll, int> > occ;

      Vertex(int p, char ch, int depth) : p(p), pch(ch), depth(depth) {
          std::fill(next.begin(), next.end(), 0);
          std::fill(go.begin(), go.end(), 0);
      }
    };

    std::vector<Vertex> t;

    AhoCorasick() : t(1, {-1, '$', 0}) {}

    void add(std::string const& s, ll value, int x = -1) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t[v].next[c]) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch, t[v].depth + 1);
            }
            v = t[v].next[c];
        }
        t[v].terminal = true;
        t[v].value += value;
        // t[v].occ.pb(ii(value, x));
    }

    void push_links() {
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            auto& cur = t[v];
            auto& link = t[cur.link];
            q.pop();
            cur.next_terminal = link.terminal ? cur.link : link.next_terminal;
            cur.value_acc = link.value_acc + (cur.terminal ? cur.value : 0);
            // for(ii x : t[cur.next_terminal].occ) cur.occ.pb(x);
            for (int c = 0; c < ALPHABET_SIZE; c++) {
                if (cur.next[c]) {
                    t[cur.next[c]].link = v ? link.next[c] : 0;
                    q.push(cur.next[c]);
                } else {
                    cur.next[c] = link.next[c];
                }
            }
        }
    }

    int go(int idx, char c) {
        return t[idx].next[c - 'a'];
    }

    // pair<bool, int> get_val(int idx){
    //   return mp(t[idx].terminal, t[idx].value);
    // }

    ll get_acc(int idx){
      return t[idx].value_acc;
    }

    int get_next_terminal(int idx){
      return t[idx].next_terminal;
    }
};

void solution(int testcase) { 
  string A, B;
  cin >> A >> B;
  
  AhoCorasick aho = AhoCorasick();
  AhoCorasick rev_aho = AhoCorasick();

  int k;
  cin >> k;
  for(int i=0; i<k; i++){
    string s;
    ll score;
    cin >> s >> score;
    // add string to aho
    aho.add(s, score, s.size());
    // add string to rev_aho
    reverse(s.begin(), s.end());
    rev_aho.add(s, score, s.size());
  }

  // push links
  aho.push_links();
  rev_aho.push_links();

  ll suffix_b[B.size()];

  //calculate suffix for B
  for(int i=B.size()-1, u = 0; i>=0; i--){
    u = rev_aho.go(u, B[i]);
    suffix_b[i] = (i+1 < B.size() ? suffix_b[i+1] : 0) + rev_aho.get_acc(u);
  }

  ll pleasure = 0;
  int BRUTE_SZ = 26;
  // brute the ans
  ll cur = 0;
  for(int a=0, u = 0; a<A.size(); a++){
    //pick a prefix of A
    u = aho.go(u, A[a]);
    cur += aho.get_acc(u);

    for(int b = 0; b<B.size(); b++){
      // what is the answer if we pick A[0..a] + B[b..|B|] (inclusive) ?
      int state = u;
      ll acc = cur;

      acc += suffix_b[b];
      int cut_state = 0;

      for(int i=b; i<B.size() && i < b+BRUTE_SZ; i++){
        state = aho.go(state, B[i]);
        acc += aho.get_acc(state);

        cut_state = aho.go(cut_state, B[i]);
        acc -= aho.get_acc(cut_state);
      }
    
      // maximize
      pleasure = max(pleasure, acc);
    }
  }
  cout << pleasure << endl;
}

int32_t main() {
  DESYNC;
  int testcase;
  cin >> testcase;
  for (int _testcase = 1; _testcase <= testcase; _testcase++)
    solution(_testcase);
}

