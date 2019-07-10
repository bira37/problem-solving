#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	long long vet[n];
	for(int i=0; i<n; i++){
		cin >> vet[i];
	}
	sort(vet,vet+n);
	
	long long l1,l2,l3;
 
	bool flag = false;
	for(int i=0; i<n-2; i++){
		l1 = vet[i];
		l2 = vet[i+1];
		l3 = vet[i+2];
		
		if(abs(l2-l3) < l1 && l1 < l2+l3){
			 if(abs(l1-l3) < l2 && l2 < l1+l3){
				if(abs(l1-l2) < l3 && l3 < l1+l2){
					flag = true;
					break;
				}
			}
		}
	}
 
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
