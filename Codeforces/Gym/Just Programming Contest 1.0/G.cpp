#include <bits/stdc++.h>
#define double long double
using namespace std;
 
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
	  double oa, od, oda, obc;
	  scanf("%Lf%Lf%Lf%Lf", &oa, &od, &oda, &obc);
	  
	  double k = sqrt(obc/oda);
	  
	  double oc = oa*k;
	  double ob = od*k;
	  
	  printf("%.9Lf %.9Lf\n", oc - od, ob - oa);
	}
}
