#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;

pii P[10];



int cross(pii a,pii b){
	return a.x*b.y - a.y*b.x;
}
int CCW(pii a,pii b,pii c){
	return cross(pii(b.x-a.x,b.y-a.y),pii(c.x-a.x,c.y-a.y));
}
int sinal(pii a,pii b,pii c){
	int aux = CCW(a,b,c);
	if(aux<0)return -1;
	if(aux>0)return 1;
	return 0;
}
int dist2(pii a,pii b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int reto(pii a,pii b,pii c){
	//b eh  o vertice
	if(dist2(a,c)==dist2(a,b)+dist2(b,c))return true;
	return false;
}

int check1(){
	int P23 = dist2(P[2],P[3]);
	int P12 = dist2(P[1],P[2]);
	int P13 = dist2(P[1],P[3]);
	if(P23<P12 + P13){
		return true;
	}
	return false;
}


int check2(){
	if(dist2(P[1],P[2])==dist2(P[1],P[3]))return true;
	return false;
}
int check3(){
	if(CCW(P[2],P[3],P[4])==0 && CCW(P[2],P[3],P[5])==0 && CCW(P[3],P[4],P[5])==0)return true;
	return false;
}
int check4(){
	double P23x = 1.0*(P[2].x+P[3].x)/2.0;
	double P23y = 1.0*(P[2].y+P[3].y)/2.0;
	double P45x = 1.0*(P[4].x+P[5].x)/2.0;
	double P45y = 1.0*(P[4].y+P[5].y)/2.0;
	if(P23x==P45x && P23y==P45y)return true;
	return false;
}
int check5(){
	if(dist2(P[2],P[3])>dist2(P[4],P[5]))return true;
	return false;
}
int check6(){
	if(reto(P[2],P[4],P[6]) && reto(P[3],P[4],P[6]) && reto(P[3],P[5],P[7]) && reto(P[2],P[5],P[7]))return true;
	return false;
}
int check7(){
	if(dist2(P[4],P[6])==dist2(P[5],P[7]))return true;
	return false;
}
int check8(){
	int a1 = sinal(P[6],P[1],P[2]);
	int b1 = sinal(P[6],P[1],P[3]);
	int c1 = sinal(P[2],P[3],P[1]);
	int d1 = sinal(P[2],P[3],P[6]);
	if(a1*b1==-1 && c1*d1==-1)return true;
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=1;i<=7;i++){
		cin>>P[i].x>>P[i].y;
	}
	if(check1() && check2() && check3() && check4() && check5() && check6() && check7() && check8())cout<<"S"<<endl;
	else cout<<"N"<<endl; 
	
	
}