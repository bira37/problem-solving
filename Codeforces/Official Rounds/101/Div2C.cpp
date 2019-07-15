#include <bits/stdc++.h>
#define psi pair<string, int>
#define name first
#define val second
using namespace std;

bool cmp(const psi & a, const psi & b){
	return a.val < b.val;
}

int main(){
	int n;
	cin >> n;
	psi v[n];
	for(int i=0; i<n; i++) cin >> v[i].name >> v[i].val;
	int ans[n];
	sort(v, v+n, cmp);
	if(v[0].val != 0){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<n; i++) ans[i] = (n-i);
	
	/*for(int i=0; i<n; i++){
			cout << v[i].name << " " << ans[i] << endl;
		}
	cout << endl;*/
	for(int i=1; i<n; i++){
		int need = v[i].val;
		if(v[i].val > i){
			cout << -1 << endl;
			return 0;
		}
		int marcado = -1;
		for(int j=0; j<i; j++){
			if(need == 0){
				marcado = j;
				break;
			}
			if(ans[j] > ans[i]){
				need--;
			}
		}
		if(marcado == -1) continue;
		psi aux = v[i];
		int aux2 = ans[i];
		for(int j=i; j>marcado; j--){
			ans[j] = ans[j-1];
			v[j] = v[j-1];
		}
		v[marcado] = aux;
		ans[marcado] = aux2; 
		
		/*for(int i=0; i<n; i++){
			cout << v[i].name << " " << ans[i] << endl;
		}
		cout << endl;*/
	}
		
	
	for(int i=0; i<n; i++){
		cout << v[i].name << " " << ans[i] << endl;
	}
}
	