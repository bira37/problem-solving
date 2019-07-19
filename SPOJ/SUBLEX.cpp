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

int main() {
	cin >> s;
	n = s.size();
	build_sa();
	calculate_lcp();
	
	int q;
	cin >> q;
	pair<int, int> c[q];
	for(int i = 0; i < q; i++) {
		cin >> c[i].first;
		c[i].first--;
		c[i].second = i;		
	}
	sort(c, c+q);
	int sum_pre = 0;
	int last_pre = 0;
	int j = 0;
	string ans[q];
	lcp[n-1] = 0;
	for(int i = 0; i < n; i++) {
		int lc = i ? lcp[i-1] : 0;
		sum_pre += n-sa[i]-lc;
		//cout << "sp " << sum_pre << endl;
		while(j < q && c[j].first < sum_pre) {
			//cout << sa[i] << endl;
			//cout << c[j].first << endl;
			
			//cout << "-> " << c[j].first-last_pre+lc+1 << endl;
			ans[c[j].second] = s.substr(sa[i], c[j].first-last_pre+lc+1);
			j++;
		}
		last_pre = sum_pre;
	}
	for(int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
}
