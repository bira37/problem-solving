#include <bits/stdc++.h>
#define int long long
#define double long double
#define ms(v,x) memset(v,x,sizeof(v))
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define td(v) v.begin(), v.end()
#define tdr(v) v.rbegin(), v.rend()
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long mod(long long n, long long m) {
    long long ret = n % m;
    if (ret < 0) ret += m;
    return ret;
}

double rad(double x) { return x * pi / 180.0; }

int exp(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = result * a % MOD;

        b >>= 1;
        a = a *a  % MOD;
    }
    return result;
}

vector<vector<pair<int, int>>> adj;
int mat[520][520];
int memo[520][520][20];
int r, c, n;
bool confere(int q, int j){
    if(j == c) return false;
    if(mat[q-1][j] == -1 or mat[q+1][j] == -1 or mat[q][j+1] == -1 or mat[q][j-1] == -1) return false;
    return (mat[q - 1][j] > mat[q][j]) and (mat[q+1][j] > mat[q][j]) and (mat[q][j-1] < mat[q][j]) and (mat[q][j+1] < mat[q][j]);
}
int dp(int i, int j, int qt){
    if(qt > 10) return INF;
    if(mat[i][j] == -1) return INF;
    if(j == c) {
        if(qt == n)
            return mat[i][j];
        else{
            return INF;
        }
    }
    int &x = memo[i][j][qt];
    if(x != -1) return x;
    int ans = INF;
    x = mat[i][j];
    ans = min(ans, dp(i+1, j+1, qt+confere(i, j)));
    ans = min(ans, dp(i, j+1, qt+confere(i, j)));
    ans = min(ans, dp(i-1, j+1, qt+confere(i, j)));
    x += ans;
    x = min(x, INF);
    return x;
}

void solve(){
    cin >> r >> c >> n;
    for(int i = 0; i < 520; i++){
        for(int j = 0; j < 520; j++){
            mat[i][j] = -1;
            for(int z = 0; z < 20; z++){
                memo[i][j][z] = -1;
            }
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> mat[i][j];
        }
    }
    int ans = INF;
    for(int i = 1; i <= r; i++){
        ans = min(ans, dp(i, 1, 0));
    }
    if(ans == INF){
        cout << "impossible" << endl;
    }
    else{
        cout << ans << endl;
    }
}

int32_t main() {
	// fastio;
	// freopen("in.txt", "r", stdin);
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
}
