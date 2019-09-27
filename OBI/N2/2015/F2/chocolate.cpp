#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int met = n/2;
	int x1,y1,x2,y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	int x = min(x1,x2);
	int X = max(x1,x2);
	int y = min(y1,y2);
	int Y = max(y1,y2);
	if((x<=met && X>met )|| (y<=met && Y>met))cout<<"S"<<endl;
	else cout<<"N"<<endl;
}