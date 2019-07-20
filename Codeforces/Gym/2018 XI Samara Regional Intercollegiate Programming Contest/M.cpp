#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long // LEMBRAR DE TROCAR CASO PROBLEMA DE MEMORIA
#define pii pair<int,int>
#define ieps (int) 1e6
#define eps (int) 1e9
#define mp make_pair
#define pb push_back
 
 
 
int32_t main(){
	/*ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	*/
	string a , b, c;
	cin>>a>>b>>c;
	string target = a;
	int n = a.size();
	for(int i = 0 ; i < a.size() ; i++){
		target[i] = '?';
	}
	while(a.size() < 3){
		a += 'a' , b+= 'a' , c+='a';
	}
	int ans = 0;
	vector<int> pos;
	for(int i  = 0 ; i < n; i ++){
		if(a[i] == b[i] && b[i] == c[i]){
			target[i] = b[i];
		}
		else ans++ , pos.pb(i);
	}
	if(ans > 3){
		cout<<"Impossible";
		return 0;
	}
	for(int i = 0 ; i < a.size(); i ++){
		if(a[i] == b[i] && b[i] == c[i]){
			if(pos.size() < 3){
				pos.pb(i);
			}
		}
	}
	int ansz = 0;
	for(char i = 'a' ; i <= 'z' ; i++)
	for(char j = 'a' ; j <= 'z' ; j++)
	for(char k = 'a' ; k <= 'z' ; k++){
		map<int, int> changepos;
		int x = pos[0] , y = pos[1] , z = pos[2];
		if(a[x] != i) changepos[0]++;
		if(a[y] != j) changepos[0]++;
		if(a[z] != k) changepos[0]++;
		if(b[x] != i) changepos[1]++;
		if(b[y] != j) changepos[1]++;
		if(b[z] != k) changepos[1]++;
		if(c[x] != i) changepos[2]++;
		if(c[y] != j) changepos[2]++;
		if(c[z] != k) changepos[2]++;
		if(changepos[0] <= 1 && changepos[1] <=1 && changepos[2] <= 1){
			ansz++;
			target[x] = i , target[y] = j , target[z] = k;
		}
	}
	if(ansz > 1) cout<<"Ambiguous";
	else if(ansz == 0) cout<<"Impossible";
	else{
		for(int i = 0 ; i < n; i ++){
			cout<<target[i];
		}
	}
}
