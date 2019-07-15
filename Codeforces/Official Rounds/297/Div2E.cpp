#include <bits/stdc++.h>
#define int long long
using namespace std;

long long sum = 0;

vector< vector<int> > A(13);
vector< map<int,int> > B(14);

vector<int> a,b,v;

int n, k, s;

int fat[19];

void solveA(int i, int stickers){
	if(i == a.size()){
		A[stickers].push_back(sum);
		return;
	}
	//cout << "at " << a[i] << endl;
	//cout << "sum " << sum << endl;
	//dont pick the guuuuuy
	solveA(i+1, stickers);
	
	//pick the guuuuuuuy
	sum += a[i];
	solveA(i+1, stickers);
	sum -= a[i];
	if(a[i] <= 18){
		sum += fat[a[i]];
		solveA(i+1, stickers+1);
		sum -= fat[a[i]];
	}
}

void solveB(int i, int stickers){
	if(i == b.size()){
		B[stickers][sum]++;
		return;
	}
	//cout << "at " << b[i] << endl;
	//cout << "sum " << sum << endl;
	//dont pick the guuuuuy
	solveB(i+1, stickers);
	
	//pick the guuuuuuuy
	sum += b[i];
	solveB(i+1, stickers);
	sum -= b[i];
	if(b[i] <= 18){
		sum += fat[b[i]];
		solveB(i+1, stickers+1);
		sum -= fat[b[i]];
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	fat[0] = 1;
	fat[1] = 1;
	for(int i=2; i<=18; i++){
		fat[i] = i*fat[i-1];
	}
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n/2; i++){
		a.push_back(v[i]);
	}
	for(int i=n/2; i<n; i++){
		b.push_back(v[i]);
	}
	//cout << "doing A" << endl;
	solveA(0, 0);
	//cout << "doing B" << endl;
	solveB(0, 0);
	int ans = 0;
	/*for(int i=0; i<=k; i++){
		sort(B[i].begin(), B[i].end());
	}*/
	for(int i=0; i<=min(12LL, k); i++){
		//considering i stickers in A
		for(int x : A[i]){
			for(int j=0; j<=min(13LL, k-i); j++){
				ans+= B[j][s - x];
			}
		}
	}
	cout << ans << endl;	
}