#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define piii pair<int,pii> 
#define F first
#define S second
int n , m;
vector<pii> v;
vector<piii> a;
int ans[123456];
multiset< piii > w;
 
int main(){	
	scanf("%d%d" , &n , &m);
	v.resize(n);
	for(int i=0;i<n;i++) scanf("%d" , &v[i].F) , v[i].S = i; 
	a.resize(m);
	for(int i = 0 ; i < m ;i ++){
		scanf("%d" , & a[i].F);
	}
	for(int i = 0 ; i < m ;i ++){
		scanf("%d" , & a[i].S.F);
		a[i].S.S = i;
	}
	sort(v.rbegin() , v.rend());
	sort(a.rbegin(), a.rend());
 
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < m && a[j].F >= v[i].F) {
			w.insert(piii(a[j].S.F, pii(a[j].F, a[j].S.S)));
			j++;
		}
 
		if(w.empty()) {
			cout << "impossible" << endl;
			return 0;
		}
 
		multiset<piii>::iterator it = w.begin();
		piii k = *it;
		ans[v[i].S] = k.S.S;
		w.erase(it);
		// opt = it;
 
	}
 
	for(int i = 0 ; i < n; i ++){
		cout<<ans[i] + 1;
		if(i < n - 1) cout<<" ";
	}	
	cout<<endl;
 
	// for(int i = 0 ; i< m ;i++){
	// 	w.insert(piii(a[i].S.F , pii(a[i].F, a[i].S.S)));
	// }
	// bool f = false;
	// for(int i = 0 ; i < n; i ++){
	// 	multiset<piii>::iterator it = w.begin();
	// 	multiset<piii>::iterator opt;
	// 	bool c = false;
	// 	for(it = w.begin() ; it != w.end() ; it++){
	// 		piii k = *it;
	// 		if(k.S.F >= v[i].F){
	// 			opt = it;
	// 			c = true;
	// 			break;
	// 		}
	// 	}
	// 	if(!c) f = true;
	// 	if(f) break;
	// 	piii k = *opt;
	// 	ans[v[i].S] = k.S.S;
	// 	w.erase(opt);
	// }
	// if(f) cout<<"impossible"<<endl;
	// else{
	// 	for(int i = 0 ; i < n; i ++){
	// 		cout<<ans[i] + 1;
	// 		if(i < n - 1) cout<<" ";
	// 	}	
	// 	cout<<endl;
	// }
}
