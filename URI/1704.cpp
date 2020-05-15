#include <bits/stdc++.h>
 
using namespace std;

struct process{
	int l,d;
};

bool cmp(const process & a, const process & b){
	return a.l > b.l;
}
	
int main(){
	ios_base::sync_with_stdio(false);
	int n,h;
	while(cin >> n >> h){
		vector<process> job(n);
		int ans = 0;
		int deadline[h+1];
		for(int i=0; i<h+1; i++) deadline[i] = 0;
		for(int i=0; i<n; i++){
			cin >> job[i].l >> job[i].d;
			ans += job[i].l;
		}
		sort(job.begin(), job.end(), cmp);
		for(int i=0; i<n; i++){
			int dead = job[i].d;
			while(deadline[dead] != 0 && dead > 0) dead--;
			deadline[dead] = job[i].l;
		}
		for(int i=1; i<=h; i++){
			ans -= deadline[i];
		}
		cout << ans << endl;
	}
	
}
