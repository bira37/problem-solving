#include <bits/stdc++.h>
 
using namespace std;
 
struct exam{
	int id, day;
	exam(int id, int day) : id(id), day(day) {}
	bool operator <(const exam & a) const {
		return day < a.day;
	}
};
 
int prep[(int)1e5+1];
int days[(int)1e5+1];
int n,m;
 
bool check(int d){
	bool vis[m+1];
	vector<exam> v;
	for(int i=1; i<m+1; i++){
		vis[i] = false;
	}
	int cont = 0;
	for(int i=d; i>=1; i--){
		if(days[i] != 0 && !vis[days[i]]){
			v.emplace_back(days[i], i);
			vis[days[i]] = true;
			cont++;
		} 
	}
	//for(int i=0; i<v.size(); i++){
	//	cout << v[i].id << " " << v[i].day << endl;
	//}
	if(cont != m) return false;
	
	sort(v.begin(), v.end());
 
	int cur = 0;
	if(prep[v[0].id] < v[0].day){
		cur += (v[0].day - 1 - prep[v[0].id]);
		//cout << "passing exam " << v[0].id << endl;
		//cout << "cur = " << cur << endl;
		for(int i=1; i<v.size(); i++){
			cur+= (v[i].day - 1 - v[i-1].day);
			if(prep[v[i].id] <= cur){
				cur-= prep[v[i].id];
			}
			else return false;
			//cout << "passing exam " << v[i].id << endl;
			//cout << "cur = " << cur << endl;
		}
	}
	else return false;
	return true;  
	
}
 
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> days[i];
	}
	for(int i=1; i<=m; i++){
		cin >> prep[i];
	}
	
	int l = 0, r = 1e5;
	
	int ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		//cout << mid << " days" << endl;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
 
	cout << ans << endl;
}
	
