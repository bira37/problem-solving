#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define M 1000000007
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

char mat[3][3][3][3];

void o_read_mais_barril_de_todos(){
	cin >> mat[0][0][0][0];
	cin >> mat[0][0][0][1];
	cin >> mat[0][0][0][2];
	cin >> mat[0][1][0][0];
	cin >> mat[0][1][0][1];
	cin >> mat[0][1][0][2];
	cin >> mat[0][2][0][0];
	cin >> mat[0][2][0][1];
	cin >> mat[0][2][0][2];//linha 0
	
	cin >> mat[0][0][1][0];
	cin >> mat[0][0][1][1];
	cin >> mat[0][0][1][2];
	cin >> mat[0][1][1][0];
	cin >> mat[0][1][1][1];
	cin >> mat[0][1][1][2];
	cin >> mat[0][2][1][0];
	cin >> mat[0][2][1][1];
	cin >> mat[0][2][1][2];//linha 1
	
	cin >> mat[0][0][2][0];
	cin >> mat[0][0][2][1];
	cin >> mat[0][0][2][2];
	cin >> mat[0][1][2][0];
	cin >> mat[0][1][2][1];
	cin >> mat[0][1][2][2];
	cin >> mat[0][2][2][0];
	cin >> mat[0][2][2][1];
	cin >> mat[0][2][2][2];//linha 2
	
	cin >> mat[1][0][0][0];
	cin >> mat[1][0][0][1];
	cin >> mat[1][0][0][2];
	cin >> mat[1][1][0][0];
	cin >> mat[1][1][0][1];
	cin >> mat[1][1][0][2];
	cin >> mat[1][2][0][0];
	cin >> mat[1][2][0][1];
	cin >> mat[1][2][0][2];//linha 0
	
	cin >> mat[1][0][1][0];
	cin >> mat[1][0][1][1];
	cin >> mat[1][0][1][2];
	cin >> mat[1][1][1][0];
	cin >> mat[1][1][1][1];
	cin >> mat[1][1][1][2];
	cin >> mat[1][2][1][0];
	cin >> mat[1][2][1][1];
	cin >> mat[1][2][1][2];//linha 1
	
	cin >> mat[1][0][2][0];
	cin >> mat[1][0][2][1];
	cin >> mat[1][0][2][2];
	cin >> mat[1][1][2][0];
	cin >> mat[1][1][2][1];
	cin >> mat[1][1][2][2];
	cin >> mat[1][2][2][0];
	cin >> mat[1][2][2][1];
	cin >> mat[1][2][2][2];//linha 2
	
	cin >> mat[2][0][0][0];
	cin >> mat[2][0][0][1];
	cin >> mat[2][0][0][2];
	cin >> mat[2][1][0][0];
	cin >> mat[2][1][0][1];
	cin >> mat[2][1][0][2];
	cin >> mat[2][2][0][0];
	cin >> mat[2][2][0][1];
	cin >> mat[2][2][0][2];//linha 0
	
	cin >> mat[2][0][1][0];
	cin >> mat[2][0][1][1];
	cin >> mat[2][0][1][2];
	cin >> mat[2][1][1][0];
	cin >> mat[2][1][1][1];
	cin >> mat[2][1][1][2];
	cin >> mat[2][2][1][0];
	cin >> mat[2][2][1][1];
	cin >> mat[2][2][1][2];//linha 1
	
	cin >> mat[2][0][2][0];
	cin >> mat[2][0][2][1];
	cin >> mat[2][0][2][2];
	cin >> mat[2][1][2][0];
	cin >> mat[2][1][2][1];
	cin >> mat[2][1][2][2];
	cin >> mat[2][2][2][0];
	cin >> mat[2][2][2][1];
	cin >> mat[2][2][2][2];//linha 2
}

void o_print_mais_barril_de_todos(){
	cout << mat[0][0][0][0];
	cout << mat[0][0][0][1];
	cout << mat[0][0][0][2];
	cout << " ";
	cout << mat[0][1][0][0];
	cout << mat[0][1][0][1];
	cout << mat[0][1][0][2];
	cout << " ";
	cout << mat[0][2][0][0];
	cout << mat[0][2][0][1];
	cout << mat[0][2][0][2];//linha 0
	cout << endl;
	
	cout <<  mat[0][0][1][0];
	cout <<  mat[0][0][1][1];
	cout <<  mat[0][0][1][2];
	cout << " ";
	cout <<  mat[0][1][1][0];
	cout <<  mat[0][1][1][1];
	cout <<  mat[0][1][1][2];
	cout << " ";
	cout <<  mat[0][2][1][0];
	cout <<  mat[0][2][1][1];
	cout <<  mat[0][2][1][2];//linha 1
	cout << endl;
	
	cout <<  mat[0][0][2][0];
	cout <<  mat[0][0][2][1];
	cout <<  mat[0][0][2][2];
	cout << " ";
	cout <<  mat[0][1][2][0];
	cout <<  mat[0][1][2][1];
	cout <<  mat[0][1][2][2];
	cout << " ";
	cout <<  mat[0][2][2][0];
	cout <<  mat[0][2][2][1];
	cout <<  mat[0][2][2][2];//linha 2
	cout << endl << endl;
	
	cout <<  mat[1][0][0][0];
	cout <<  mat[1][0][0][1];
	cout <<  mat[1][0][0][2];
	cout << " ";
	cout <<  mat[1][1][0][0];
	cout <<  mat[1][1][0][1];
	cout <<  mat[1][1][0][2];
	cout << " ";
	cout <<  mat[1][2][0][0];
	cout <<  mat[1][2][0][1];
	cout <<  mat[1][2][0][2];//linha 0
	cout << endl;
	
	cout <<  mat[1][0][1][0];
	cout <<  mat[1][0][1][1];
	cout <<  mat[1][0][1][2];
	cout << " ";
	cout <<  mat[1][1][1][0];
	cout <<  mat[1][1][1][1];
	cout <<  mat[1][1][1][2];
	cout << " ";
	cout <<  mat[1][2][1][0];
	cout <<  mat[1][2][1][1];
	cout <<  mat[1][2][1][2];//linha 1
	cout << endl;
	
	cout <<  mat[1][0][2][0];
	cout <<  mat[1][0][2][1];
	cout <<  mat[1][0][2][2];
	cout << " ";
	cout <<  mat[1][1][2][0];
	cout <<  mat[1][1][2][1];
	cout <<  mat[1][1][2][2];
	cout << " ";
	cout <<  mat[1][2][2][0];
	cout <<  mat[1][2][2][1];
	cout <<  mat[1][2][2][2];//linha 2
	cout << endl << endl;
	
	cout <<  mat[2][0][0][0];
	cout <<  mat[2][0][0][1];
	cout <<  mat[2][0][0][2];
	cout << " ";
	cout <<  mat[2][1][0][0];
	cout <<  mat[2][1][0][1];
	cout <<  mat[2][1][0][2];
	cout << " ";
	cout <<  mat[2][2][0][0];
	cout <<  mat[2][2][0][1];
	cout <<  mat[2][2][0][2];//linha 0
	cout << endl;
	
	cout <<  mat[2][0][1][0];
	cout <<  mat[2][0][1][1];
	cout <<  mat[2][0][1][2];
	cout << " ";
	cout <<  mat[2][1][1][0];
	cout <<  mat[2][1][1][1];
	cout <<  mat[2][1][1][2];
	cout << " ";
	cout <<  mat[2][2][1][0];
	cout <<  mat[2][2][1][1];
	cout <<  mat[2][2][1][2];//linha 1
	cout << endl;
	
	cout <<  mat[2][0][2][0];
	cout <<  mat[2][0][2][1];
	cout <<  mat[2][0][2][2];
	cout << " ";
	cout <<  mat[2][1][2][0];
	cout <<  mat[2][1][2][1];
	cout <<  mat[2][1][2][2];
	cout << " ";
	cout <<  mat[2][2][2][0];
	cout <<  mat[2][2][2][1];
	cout <<  mat[2][2][2][2];//linha 2
	cout << endl;
}
	

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	o_read_mais_barril_de_todos();
	int x,y;
	cin >> x >> y;
	x--;y--;
	int ax = x/3, ay = y/3;
	ax = 3*ax +1;
	ay = 3*ay+1;
	int px, py;
	if(ax-1 == x && ay-1 == y){
		px = 0;
		py = 0;
	}
	else if(ax-1 == x && ay == y){
		px = 0;
		py = 1;
	}
	else if(ax-1 == x && ay+1 == y){
		px = 0;
		py = 2;
	}
	else if(ax == x && ay-1 == y){
		px = 1;
		py = 0;
	}
	else if(ax == x && ay == y){
		px = 1;
		py = 1;
	}
	else if(ax == x && ay+1 == y){
		px = 1;
		py = 2;
	}
	else if(ax+1 == x && ay-1 == y){
		px = 2;
		py = 0;
	}
	else if(ax+1 == x && ay == y){
		px = 2;
		py = 1;
	}
	else if(ax+1 == x && ay+1 == y){
		px = 2;
		py = 2;
	}
	bool flag = false;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(mat[px][py][i][j] == '.') flag = true;
		}
	}
	if(flag){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(mat[px][py][i][j] == '.') mat[px][py][i][j] = '!';
			}
		}
	}
	else {
		for(int a = 0; a < 3; a++){
			for(int b = 0; b<3; b++){
				for(int i=0; i<3; i++){
					for(int j=0; j<3; j++){
						if(mat[a][b][i][j] == '.') mat[a][b][i][j] = '!';
					}
				}
			}
		}
	}
	o_print_mais_barril_de_todos();
}
	