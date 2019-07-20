#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define endl '\n'
#define mod(n) (n%1000000007)
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
 
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	int cnt[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
	int d,m,y;
 
	int inputd, inputm, inputy;
 
	scanf("%d/%d/%d", &d, &m, &y);
 
	m--;
 
	inputd = d;
	inputm = m;
	inputy = y;
 
	int bd1, bd2, bm1, bm2;
 
	scanf("%d/%d", &bd1, &bm1);
 
	scanf("%d/%d", &bd2, &bm2);
 
	bm1--;
	bm2--;
 
	int conta100 = 0;
 
	int ans = 0;
 
	if(m == 1){
		if(y%400 == 0 || (y%4 == 0 && y%100 != 0)) cnt[1] = 29;
		else cnt[1] = 28;
	}
 
	d++;
 
	if(d > cnt[m]){
		d=1;
		m++;
		if(m >= 12){
			m = 0;
			y++;
		}
	}
 
	for(int i = 0; i<2048; i++){
		//cout << i << endl;
 
		conta100++;
 
		if(m == 1){
			if(y%400 == 0 || (y%4 == 0 && y%100 != 0)) cnt[1] = 29;
			else cnt[1] = 28;
		}
 
		if(d == inputd && m == inputm && y != inputy){ //namoro
			//printf("namoro\n");
			ans++;
			if(conta100 == 100) conta100 = 0;
		}
		else if(d == bd1 && m == bm1){
			//printf("niver1\n");
			ans++;
			if(conta100 == 100) conta100 = 0;
		}
		else if(d == bd2 && m == bm2){
			//printf("niver2\n");
			ans++;
			if(conta100 == 100) conta100 = 0;
		}
		else if(conta100 == 100){
			//printf("especial\n");
			ans++;
			conta100 = 0;
		}
 
		d++;
		if(d > cnt[m]){
			d=1;
			m++;
			if(m >= 12){
				m = 0;
				y++;
			}
		}
	}
 
	printf("%d\n", ans);
}
