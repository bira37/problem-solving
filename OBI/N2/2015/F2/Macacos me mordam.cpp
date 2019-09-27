#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
	ll x;
	ll y;
};

ll compare(Point a,Point b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

ll sentido(Point A,Point B,Point O ){
	return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

ll Covex(vector<Point> P,ll N){
		ll K=0;
	sort(P.begin(),P.end(),compare);
	vector<Point> H(2*N);
	//lower
	for(ll i=0;i<N;i++){
		while(K>=2 && sentido(H[K-1],H[K-2],P[i])<=0)K--;
		H[K++]=P[i];
	}
	//upper
	for(ll i=N-1,t=K-2;i>=0;i--){
		while(K>=t && K>=2 && sentido(H[K-1],H[K-2],P[i])<=0)K--;
		H[K++]=P[i];
	}
	H.resize(K-1);
/* Uncomment to see the Hull	
for(int i=0;i<(int)H.size();i++){
		cout<<H[i].x<<" "<<H[i].y<<endl;
	}
	*/
	return H.size()-3;
}

int main(){
	   ll N;
	   cin>>N;
	   Point aux;
	   vector<Point> A;
	   ll maior=0,menor=1e9+7;
	   for(ll i=0;i<N;i++){
		   cin>>aux.x>>aux.y;
		   A.push_back(aux);
		maior=max(maior,aux.x);	  
		menor=min(menor,aux.x);	   
	   }	
	   aux.x=menor;
	   aux.y=0;
	   A.push_back(aux);
		  aux.x=maior;
	A.push_back(aux);
	N=A.size();	  	
	cout<<Covex(A,N)<<endl;
}