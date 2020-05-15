#include <bits/stdc++.h>

using namespace std;

struct point{
	double x,y;
};

bool cmp(const point & a, const point & b){
	return a.x < b.x;
}

bool cmp2(const point & a, const point & b){
	return a.y < b.y;
}

double dist(const point & a, const point & b){
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y - a.y)*(b.y - a.y));
}

double compare(point* pontos, int ini, int fim, double dl, double dr){

	//calculate min(dleft, dright, dlf) where dlf is the closest points distance between 2 points a,b in opposite sides
	double d = min(dl,dr);
	int meio = (ini+fim)/2;

	//ordering by y
	sort(pontos+ini, pontos+fim+1, cmp2);

	double menor = d;
	
	//for all points that are between mid and mid - min(dleft,dright) in x, check all points between the point and min(dleft,dright) in y
	for(int i=ini; i<=fim; i++){
		if(abs(pontos[i].x - pontos[meio].x) <= d && i != meio){
			int aux = i-1;
			while(aux >= ini && abs(pontos[i].y - pontos[aux].y) <= d){
				menor = min(menor, dist(pontos[i], pontos[aux]));
				aux--;
			}
			aux = i+1;
			while(aux <= fim && abs(pontos[i].y - pontos[aux].y) <= d){
				menor = min(menor, dist(pontos[i], pontos[aux]));
				aux++;
			}
		}
	}
	
	return menor;
			
}
	

double calculate_closest_points(point* pontos, int ini, int fim){
	//brute force if 2 or 3 points
	if(fim <= ini+2){
		double menor = 10e9;
		for(int i=ini; i<=fim-1; i++){
			for(int j=i+1; j<=fim; j++){
				menor = min(menor, dist(pontos[i], pontos[j]));
			}
		}
		return menor;
	}
	//else divide and then calculate min(dleft,dright, dlr)
	else {
		int meio = (ini+fim)/2;
		double dl,dr;
		dl = calculate_closest_points(pontos, ini, meio);
		dr = calculate_closest_points(pontos, meio+1, fim);
		double menor = compare(pontos,ini,fim,dl,dr);
		return menor;
	}
}
		 

int main(){
	//ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n, n != 0){

		point pontos[n];
	
		//get the n points(x,y)
		for(int i=0; i<n; i++) scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
	
		//sort all points using x coordinate
		sort(pontos, pontos+n, cmp);

		//calculate the closest points distance
		double ans = calculate_closest_points(pontos,0,n-1);
		if(ans < 10000) printf("%.4lf\n", ans);
		else printf("INFINITY\n");

	}
}
	
	
