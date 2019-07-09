#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int a,g,c,t,q;
	a=g=c=t=q=0;
	int n;
	string str;
	cin >> n;
	cin >> str;
	int change[] = {'A','C','G','T'};
	stack<char> ans;
	for(int i=0; i<n; i++){
		if(str[i] == 'A') a++;
		else if(str[i] == 'G') g++;
		else if(str[i] == 'C') c++;
		else if(str[i] == 'T') t++;
		else q++;
	}
 
	if(n%4 != 0){
		cout << "===" << endl;
		return 0;
	}
	
	if(a+g+c+t == 0 && n%4 == 0){
		int len = n/4;
		for(int i=0; i<len; i++) cout << 'A';
		for(int i=0; i<len; i++) cout << 'G';
		for(int i=0; i<len; i++) cout << 'C';
		for(int i=0; i<len; i++) cout << 'T';
		cout << endl;
		return 0;
	}
 
	int max = std::max({a,g,c,t});
	a = max - a;
	g = max - g;
	c = max - c;
	t = max - t;
 
	if(q != (a+g+c+t) && (q-(a+g+c+t))%4 != 0){
		cout << "==="  << endl;
		return 0;
	}
	
	for(int i=0; i<a; i++) ans.push('A');
	for(int i=0; i<g; i++) ans.push('G');
	for(int i=0; i<c; i++) ans.push('C');
	for(int i=0; i<t; i++) ans.push('T');
	
	if((q-(a+g+c+t))%4 == 0 ){
		for(int i=0; i<(q-(a+g+c+t))/4; i++) ans.push('A');
		for(int i=0; i<(q-(a+g+c+t))/4; i++) ans.push('G');
		for(int i=0; i<(q-(a+g+c+t))/4; i++) ans.push('C');
		for(int i=0; i<(q-(a+g+c+t))/4; i++) ans.push('T');
	}
	int noob = 0;
	for(int i=0; i<n; i++){
		if(str[i] == '?'){
			str[i] = ans.top();
			ans.pop();
		}
	}
	a=g=c=t=0;
	for(int i=0; i<n; i++){
		if(str[i] == 'A') a++;
		else if(str[i] == 'G') g++;
		else if(str[i] == 'C') c++;
		else if(str[i] == 'T') t++;
		else q++;
	}
	if(a != g || a != c || a != t || g != c || g != t || c != t) cout << "===" << endl;
	else cout << str << endl;
}
