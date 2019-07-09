#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n;
	double n1,n2;
	cin >> n >> n1 >> n2;
	vector<int> p(n);
	for(int i=0; i<n; i++) cin >> p[i];
	sort(p.begin(),p.end());
	reverse(p.begin(),p.end());
	double sum2=0;
	double sum1=0;
	if(n2 < n1) swap(n1,n2);
	int k=0;
	for(int i=0; i<n1; i++){
		sum1+= p[k++];
	}
	sum1 = sum1/(n1*1.0);
	for(int i=0; i<n2; i++){
		sum2+= p[k++];
	}
	sum2 = sum2/(n2*1.0);
	printf("%.8lf\n", sum1+sum2);
}
