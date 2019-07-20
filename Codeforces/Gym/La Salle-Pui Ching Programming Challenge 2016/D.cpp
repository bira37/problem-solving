#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define int long long // LEMBRAR DE TROCAR CASO PROBLEMA DE MEMORIA
#define pii pair<int,int>
#define ieps (int) 1e6
#define eps (int) 1e9
#define mp make_pair
#define pb push_back
struct item{
	int pontos = 0 , x  = 0 , ten = 0;
} v[2];
 
int32_t main(){
	int n;
	cin>>n;
	for(int i = 0 ; i < n;i ++){
		string t;
		cin>>t;
		if((char)t[0] - '0' >= 1 && (char)t[0] - '0' <=9 && t.size() == 1) v[0].pontos += t[0] - '0';
		if((char)t[0] ==  'X' && t.size() == 1) v[0].pontos += 10 , v[0].x++ ,v[0].ten++;
		if(t  == "10") v[0].pontos += 10, v[0].ten++;	
	}
	for(int i = 0 ; i < n;i ++){
		string t;
		cin>>t;
		if( (char) t[0] -'0' >= 1 && (char) t[0] - '0' <=9 && t.size() == 1) v[1].pontos += t[0] - '0';
		if(t.size() == 1 && (char)t[0] == 'X') v[1].pontos += 10 , v[1].x++ ,v[1].ten++;
		if(t  == "10") v[1].pontos += 10, v[1].ten++;
	}	
	if(v[0].pontos == v[1].pontos && v[0].x == v[1].x && v[0].ten == v[1].ten){
		cout<<"Shoot-off"<<endl;
		return 0;
	}
	if(v[0].pontos > v[1].pontos ||(v[0].pontos == v[1].pontos && v[0].ten > v[1].ten) || (v[0].pontos == v[1].pontos && v[0].ten == v[1].ten && v[0].x > v[1].x)){
		cout<<"Yuju"<<endl;
		return 0;
	}
	swap(v[0] , v[1]);
		if(v[0].pontos > v[1].pontos ||(v[0].pontos == v[1].pontos && v[0].ten > v[1].ten) || (v[0].pontos == v[1].pontos && v[0].ten == v[1].ten && v[0].x > v[1].x)){
		cout<<"Yerin"<<endl;
		return 0;
	}
}
