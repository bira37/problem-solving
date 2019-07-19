#include <bits/stdc++.h>

using namespace std;

int rnk[112345],tmp[112345], sa[112345], sa_aux[112345];
int block=0, n;

string s;

bool suffixcmp(int i, int j){ 
	if(rnk[i] != rnk[j]) return rnk[i] < rnk[j];
	i+=block, j+=block;
	i%=n;
	j%=n;
	return rnk[i] < rnk[j];
}

void suffixSort(int MAX_VAL){
    for(int i=0; i<=MAX_VAL; i++) tmp[i] = 0;
    for(int i=0; i<n; i++) tmp[rnk[i]]++;
    for(int i=1; i<=MAX_VAL; i++) tmp[i] += tmp[i-1];
    for(int i = n-1; i>=0; i--){
        int aux = sa[i]-block;
        aux%=n;
        if(aux < 0) aux+=n;
        sa_aux[--tmp[rnk[aux]]] = aux;
    }
    for(int i=0; i<n; i++) sa[i] = sa_aux[i];
    tmp[0] = 0;
	for(int i=1; i<n; i++) tmp[i] = tmp[i-1] + suffixcmp(sa[i-1], sa[i]);
	for(int i=0; i<n; i++) rnk[sa[i]] = tmp[i];
}

void build_sa(){ 
	for(int i=0; i<n; i++){
		sa[i] = i;
		rnk[i] = s[i];
		tmp[i] = 0;
	}
	suffixSort(256);
	block = 1;
	int contador = 20;
	while(contador--){
		suffixSort(tmp[n-1]);
		block*=2;
	}
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	build_sa();
	int raaa = rnk[sa[0]];
	int ans = sa[0];
	for(int i=0; i<n; i++) if(rnk[sa[i]] == raaa) ans = min(ans, sa[i]);
	cout << ans << endl;
}

