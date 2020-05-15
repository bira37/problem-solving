#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int aux[231];
		for(int i=0; i<231; i++){
			aux[i] = 0;
		}
		for(int i=0; i < n; i++){
			int x;
			scanf("%d", &x);
			aux[x]++;
		}
		int flag = true;
		for(int i=0; i<231; i++){
			while(aux[i]--){
				if(flag){
					printf("%d", i);
					flag = false;
				}
				else printf(" %d", i);
			}
		}
		cout << endl;
	}	
}
