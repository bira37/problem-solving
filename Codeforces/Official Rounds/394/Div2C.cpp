#include <bits/stdc++.h>
#define oo 0x3f3f3f
 
using namespace std;
 
struct par{
	int str, distlow, distdigit, distchar;
};
 
bool cmp1(const par & a, const par & b){
	return a.distlow < b.distlow;
}
 
bool cmp2(const par & a, const par & b){
	return a.distdigit < b.distdigit;
}
 
bool cmp3(const par & a, const par & b){
	return a.distchar < b.distchar;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	string pass[n];
	int ans = 0, res = 0x3f3f3f;
	bool used[n];
	for(int i=0; i<n; i++){
		used[i] = false;
		cin >> pass[i];
	}
	par cont[3*n];
 
	//find low case
	for(int i=0; i<n; i++){
		int j;
		//cout << "string " << i << endl;
		cont[i].str = i;
		cont[i].distlow = 0x3f3f3f;
		for(j=0; j<m; j++){
			if(pass[i][j] >= 'a' && pass[i][j] <= 'z'){ 
				cont[i].distlow = min(cont[i].distlow, min(j, m-j));
				//cout << cont[i].distlow << endl;
			}
		}
	}
	//cout << endl;
	//find digit
	for(int i=0; i<n; i++){
		int j;
		//cout << "string " << i << endl;
		cont[i].str = i;
		cont[i].distdigit = 0x3f3f3f;
		for(j=0; j<m; j++){
			if(pass[i][j] >= '0' && pass[i][j] <= '9'){ 
				cont[i].distdigit = min(cont[i].distdigit, min(j, m-j));
				//cout << cont[i].distdigit << endl;
			}
		}
	}
	//cout << endl;
	//find diff
	for(int i=0; i<n; i++){
		int j;
		//cout << "string " << i << endl;
		cont[i].str = i;
		cont[i].distchar = 0x3f3f3f;
		for(j=0; j<m; j++){
			if(pass[i][j] == '#' || pass[i][j] == '&' || pass[i][j] == '*'){ 
				cont[i].distchar = min(cont[i].distchar, min(j, m-j));
				//cout << cont[i].distchar << endl;
			}
		}
	}
	
	sort(cont, cont + n, cmp1);
	int i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	for(int i=0; i<n; i++) used[i] = false;
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp1);
	i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	for(int i=0; i<n; i++) used[i] = false;
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp1);
	i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	for(int i=0; i<n; i++) used[i] = false;
	sort(cont, cont + n, cmp1);
	i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
	
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	for(int i=0; i<n; i++) used[i] = false;
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;	
	
	sort(cont, cont + n, cmp1);
	i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
 
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	for(int i=0; i<n; i++) used[i] = false;
	sort(cont, cont + n, cmp3);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distchar;
	used[cont[i].str] = true;	
	
	sort(cont, cont + n, cmp2);
	i = 0;
	while(used[cont[i].str]) i++;
	ans+= cont[i].distdigit;
	used[cont[i].str] = true;
	
	sort(cont, cont + n, cmp1);
	i = 0;
	while(used[cont[i].str]) i++;
	ans += cont[i].distlow;
	used[cont[i].str] = true;
	res = min(res,ans);
	ans = 0;//
	cout << res << endl;
 
}
