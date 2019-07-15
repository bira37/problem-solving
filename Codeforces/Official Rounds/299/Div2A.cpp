#include <bits/stdc++.h>

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int32_t main(){
	DESYNC;
	int n;
	cin >> n;
	string dec[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string dec2[] = {"ue", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	
	string ocu[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	if(n == 0) cout << "zero" << endl;
	else if(n < 10) cout << dec[n-1] << endl;
	else if(10 <= n && n <= 19) cout << ocu[n - 10] << endl;
	else {
		if(n%10 == 0) cout << dec2[n/10 - 1] << endl;
		else cout << dec2[n/10 - 1] << "-" << dec[n%10-1] << endl;
	}
} 