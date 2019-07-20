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
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	multiset<int, greater<int> > p;
	cin >> n;
	int r = 0;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		if(s == "red") r++;
		else if(s == "yellow") p.insert(2);
		else if(s == "green") p.insert(3);
		else if(s == "brown") p.insert(4);
		else if(s == "blue") p.insert(5);
		else if(s == "pink") p.insert(6);
		else if(s == "black") p.insert(7);
	}
	bool red = false;
	int score = 0;
	if(p.size() > 0) red = false;
	else red = true;
	while(true){
		if(red){
			score++;
			r--;
			red = false;
		}
		else {
			if(p.size() == 0) break;
			else {
				score += *p.begin();
				int curr = *p.begin();
				p.erase(p.begin());
				if(r > 0){
					red = true;
					p.insert(curr);
				}
			}
		}
	}
	cout << score << endl;
}
		
