#include <bits/stdc++.h>
#define N (int)1e5+1
#define ii pair<int,int>
#define ff first
#define ss second
 
using namespace std;
 
int main(){
	char hor = ' ', ver = ' ';
	int n;
	string str;
	int ans = 1;
	cin >> n;
	cin >> str;
	for(int i=0; i<n; i++){
		if(str[i] == 'L' || str[i] == 'R'){
			if(hor == ' '){
				hor = str[i];
			}
			else if(hor != str[i]){
				ver = ' ';
				hor = str[i];
				ans++;
			}
		}
		else {
			if(ver == ' '){
				ver = str[i];
			}
			else if(ver != str[i]){
				hor = ' ';
				ver = str[i];
				ans++;
			}
		}
		//cout << hor << " " << ver << " " << ans << endl;
	}
	cout << ans << endl;
}
