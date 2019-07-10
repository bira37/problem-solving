#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,k;
	cin >> n >> k;
	if(n == 2){
		if(k == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			int x = k^(k+5);
			cout << k+5 << " " << x << endl;
		}
		return 0;
	}
	cout << "YES" << endl;
	int num = n%4;
	int count[1123456];
	for(int i=0; i<=1000000; i++) count[i] = 0;
	if(num == 1){
		cout << k;
		count[k] = 1;
		n--;
		for(int cnt = 0; n>0;){
			if(count[cnt]+count[cnt+1]+count[cnt+2]+count[cnt+3] == 0){
				cout << " " << cnt << " " << cnt+1 << " " << cnt+2 << " " << cnt+3;
				n-=4;
			}
			cnt+=4;
		}
	}
	else if(num == 2){
		int x = k^(k+5);
		int y = x^(x+5);
		int z = y^(y+5);
		int w = z^(z+5);
		int a = w^(w+5);
		count[k+5]++;
		count[x+5]++;
		count[y+5]++;
		count[w+5]++;
		count[z+5]++;
		count[a]++;
		cout << k+5 << " " << x+5 << " " << y+5 << " " << z+5 << " " << w+5 << " " << a;
		n-=6;
		for(int cnt = 0; n>0;){
			if(count[cnt]+count[cnt+1]+count[cnt+2]+count[cnt+3] == 0){
				cout << " " << cnt << " " << cnt+1 << " " << cnt+2 << " " << cnt+3;
				n-=4;
			}
			cnt+=4;
		}
	}
	else if(num == 3){
		int x = k^(k+5);
		int y = x^(x+5);
		count[k+5]++;
		count[x+5]++;
		count[y]++;
		cout << k+5 << " " << x+5 << " " << y;
		n-=3;
		for(int cnt = 0; n>0;){
			if(count[cnt]+count[cnt+1]+count[cnt+2]+count[cnt+3] == 0){
				cout << " " << cnt << " " << cnt+1 << " " << cnt+2 << " " << cnt+3;
				n-=4;
			}
			cnt+=4;
		}
	}
	else {
		int x = k^(k+5);
		int y = x^(x+5);
		int z = y^(y+5);
		count[k+5]++;
		count[x+5]++;
		count[y+5]++;
		count[z]++;
		cout << k+5 << " " << x+5 << " " << y+5 << " " << z;
		n-=4;
		for(int cnt = 0; n>0;){
			if(count[cnt]+count[cnt+1]+count[cnt+2]+count[cnt+3] == 0){
				cout << " " << cnt << " " << cnt+1 << " " << cnt+2 << " " << cnt+3;
				n-=4;
			}
			cnt+=4;
		}
	}
	cout << endl;
}
