#include <bits/stdc++.h>

using namespace std;

int rnk[1123456],tmp[1123456], sa[1123456], sa_aux[1123456], lcp[1123456];
int block=0, n;

string s,s2;
int t1;

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
	s+='\0';
	n++;
	for(int i=0; i<n; i++){
		sa[i] = i;
		rnk[i] = s[i];
		tmp[i] = 0;
	}
	suffixSort(256);
	block = 1;
	while(tmp[n-1] != n-1){
		suffixSort(tmp[n-1]);
		block*=2;
	}
	for(int i=0; i<n-1; i++) sa[i] = sa[i+1];
	n--;
	tmp[0] = 0;
	for(int i=1; i<n; i++) tmp[i] = tmp[i-1] + suffixcmp(sa[i-1], sa[i]);
	for(int i=0; i<n; i++) rnk[sa[i]] = tmp[i];
}

void calculate_lcp(){
	int last = 0;
	//for(int i=0; i<n; i++) cout << sa[i] << " ";
	//cout << endl;
	for(int i=0; i<n; i++){
		if(rnk[i] == n-1) continue;
		int x = rnk[i];
		lcp[x] = max(0,last-1);
		//cout << x << " " << x+1 << endl;
		while(sa[x] + lcp[x] < n && sa[x+1] + lcp[x] < n && s[sa[x]+lcp[x]] == s[sa[x+1]+lcp[x]]){
			//cout << sa[x]+lcp[x] << " " << sa[x+1] + lcp[x] << endl;
			//cout << s[sa[x]+lcp[x]] << endl;
			lcp[x]++;
		}
		last = lcp[x];
	}
}

int main(){
	cin >> s >> s2;
	t1 = s.size();
	s+=char('#');
	s+=s2;
	n = s.size();
	build_sa();
	calculate_lcp();
	int best = 0;
	//for(int i=0; i<n; i++) cout << rnk[sa[i]] << " ";
	//cout << endl;
	//cout << t1 << endl;
	//cout << s << endl;
	for(int i=0; i<n-1; i++){
		//cout << sa[i] << " " << sa[i+1] << endl;
		//cout << lcp[i] << endl;
		if(sa[i] < t1 && sa[i+1] > t1 || sa[i] > t1 && sa[i+1] < t1) best = max(best, lcp[i]);
	}
	cout << best << endl;
}
