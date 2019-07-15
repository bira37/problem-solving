#include <bits/stdc++.h>
#define int long long
#define M 1000000007
using namespace std;

int binary(int a, int p){
	if(p == 0) return 1;
	if(p == 1) return a;
	int k = binary(a, p/2);
	k*=k;
	k%=M;
	if(p%2) k*=a;
	k%=M;
	return k;
}

int fat[1123456];
int inv[1123456];

void process(){
	fat[0] = 1;
	fat[1] = 1;
	inv[1] = 1;
	for(int i=2; i<1123456; i++){
		fat[i] = fat[i-1]*i;
		fat[i]%=M;
		inv[i] = binary(fat[i], M-2);
	}
}

int cnt[26];

int f(string a){
	int n = a.size();
	int ans = 0;
	int tot = a.size();
	for(int i = 0; i<n; i++){
		int number = 0;
		for(int c = 0; c < (int)(a[i] - 'a'); c++){
			if(cnt[c] != 0) number++;
		}
		int add = fat[tot-1];
		int mul = 1;
		for(int j = 0; j<26; j++){
			if(cnt[j] == 0) continue;
			mul *= inv[cnt[j]];
			mul %= M;
		}
		int sum = 0;
		for(int j=0; j<26; j++){
			if(cnt[j] == 0) continue;
			if(j >= (int)(a[i] - 'a')) continue;
			int aux = mul;
			aux *= fat[cnt[j]];
			aux %= M;
			if(cnt[j] > 1) aux *= inv[cnt[j]-1];
			aux %= M;
			sum += aux;
			sum %= M;
		}
		add *= sum;
		add %= M;	
		ans += add;
		ans %= M;
		if(cnt[a[i]-'a'] > 0){
			cnt[a[i]-'a']--;
			tot--;
		}
		else break;
	}
	return ans;
}
		

int32_t main(){
	string a, b;
	char c;
	while(c = getchar(), c != '\n') a+=c;
	while(c = getchar(), c != '\n') b+=c;
	int n = a.size();
	for(int i=0; i<26; i++) cnt[i] = 0;
	for(int i=0; i<n; i++){
		cnt[a[i]-'a']++;
	}
	process();
	int fb = f(b);
	
	for(int i=0; i<26; i++) cnt[i] = 0;
	for(int i=0; i<n; i++){
		cnt[a[i]-'a']++;
	}
	
	int fa = f(a);
	cout << ((fb - fa -1)%M+M)%M << endl;
}
		