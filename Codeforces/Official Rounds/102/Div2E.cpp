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

int n,m;
char mat[9][9];

char ans[9][9];
int best = 0;

map< vector< vector<bool> >, bool> visited;

void atributte(){
	for(int i=0; i<9; i++){
		for(int j = 0; j<9; j++){
			ans[i][j] = mat[i][j];
		}
	}
}

void solve(int idx, int curr){
	if(curr > best){
		best = curr;
		atributte();
	}
	vector< vector<bool> > bit;
	
	char c = ('A'+idx);
	for(int i=0; i<n; i++){
		for(int j = 0;  j< m; j++){
			if(mat[i][j] != '.') continue;
			//try all 4 rotations
			
			if(i+1 < n && i-1 >= 0 && j-1 >= 0 && j+1 < m){
				if(mat[i+1][j] == '.' && mat[i-1][j-1] == '.' && mat[i-1][j+1] == '.' && mat[i-1][j] == '.'){
					mat[i+1][j] = c;
					mat[i-1][j-1] = c;
					mat[i-1][j] = c;
					mat[i][j] = c;
					mat[i-1][j+1] = c;
					solve(idx+1, curr+1);
					mat[i+1][j] = '.';
					mat[i-1][j-1] = '.';
					mat[i-1][j] = '.';
					mat[i][j] = '.';
					mat[i-1][j+1] = '.';
				}
			}
			
			if(i+1 < n && i-1 >= 0 && j-1 >= 0 && j+1 < m){
				if(mat[i+1][j] == '.' && mat[i+1][j-1] == '.' && mat[i+1][j+1] == '.' && mat[i-1][j] == '.'){
					mat[i+1][j] = c;
					mat[i+1][j-1] = c;
					mat[i-1][j] = c;
					mat[i][j] = c;
					mat[i+1][j+1] = c;
					solve(idx+1, curr+1);
					mat[i+1][j] = '.';
					mat[i+1][j-1] = '.';
					mat[i-1][j] = '.';
					mat[i][j] = '.';
					mat[i+1][j+1] = '.';
				}
			}
			
			if(i+1 < n && i-1 >= 0 && j-1 >= 0 && j+1 < m){
				if(mat[i][j-1] == '.' && mat[i][j+1] == '.' && mat[i+1][j+1] == '.' && mat[i-1][j+1] == '.'){
					mat[i][j-1] = c;
					mat[i][j+1] = c;
					mat[i+1][j+1] = c;
					mat[i][j] = c;
					mat[i-1][j+1] = c;
					solve(idx+1, curr+1);
					mat[i][j-1] = '.';
					mat[i][j+1] = '.';
					mat[i+1][j+1] = '.';
					mat[i][j] = '.';
					mat[i-1][j+1] = '.';
				}
			}
			
			if(i+1 < n && i-1 >= 0 && j-1 >= 0 && j+1 < m){
				if(mat[i][j-1] == '.' && mat[i][j+1] == '.' && mat[i-1][j-1] == '.' && mat[i+1][j-1] == '.'){
					mat[i][j-1] = c;
					mat[i][j+1] = c;
					mat[i-1][j-1] = c;
					mat[i][j] = c;
					mat[i+1][j-1] = c;
					solve(idx+1, curr+1);
					mat[i][j-1] = '.';
					mat[i][j+1] = '.';
					mat[i-1][j-1] = '.';
					mat[i][j] = '.';
					mat[i+1][j-1] = '.';
				}
			}
		}
	}
}
			
			
int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			ans[i][j] = '.';
			mat[i][j] = '.';
		}
	}
	if(max(n,m) <= 6 || min(n,m) <= 4 || (max(n,m) <= 8 && min(n,m) <= 5) || (max(n,m) <= 7 && min(n,m) <= 6)){
		solve(0, 0);
		cout << best << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	else if(n == 7 && m == 6){
		puts("6");
		puts("AAABBB");
		puts(".A..B.");
		puts("CA.DB.");
		puts("CCCDDD");
		puts("CE.DF.");
		puts(".EEEF.");
		puts(".E.FFF");
    }
	else if(n == 7 && m == 7){
		puts("8");
		puts("AAABCCC");
		puts(".A.B.C.");
		puts("DABBBCE");
		puts("DDDFEEE");
		puts("DG.F.HE");
		puts(".GFFFH.");
		puts("GGG.HHH");
	}
	else if(n == 7 && m == 8){
		puts("9");
		puts("AAA.BBB.");
		puts(".ACCCBD.");
		puts(".AEC.BD.");
		puts("EEECFDDD");
		puts("G.EHFFFI");
		puts("GGGHFIII");
		puts("G.HHH..I");
	}
	else if(n == 7 && m == 9){
		puts("10");
		puts("AAAB..CCC");
		puts(".ADBBB.C.");
		puts(".ADBEEECF");
		puts("GDDD.EFFF");
		puts("GGGHIE.JF");
		puts("GHHHIIIJ.");
		puts("...HI.JJJ");
	}
	else if(n == 8 && m == 6){
		puts("7");
		puts("AAABBB");
		puts(".AC.B.");
		puts(".AC.B.");
		puts("DCCC.E");
		puts("DDDEEE");
		puts("DFFFGE");
		puts("..F.G.");
		puts("..FGGG");
    }
    else if(n == 6 && m == 8){
    	puts("7");
		puts("AAABBBC.");
		puts(".AD.B.C.");
		puts(".AD.BCCC");
		puts("EDDDFGGG");
		puts("EEE.F.G.");
		puts("E..FFFG.");
	}
	else if(n == 8 && m == 7){
		puts("9");
		puts("AAAB...");
		puts(".ACBBBD");
		puts(".ACBDDD");
		puts("ECCCF.D");
		puts("EEEGFFF");
		puts("EH.GFI.");
		puts(".HGGGI.");
		puts("HHH.III");
	}
	else if(n == 8 && m == 8){
		puts("10");
		puts("AAABBBC.");
		puts(".A..B.C.");
		puts("DA..BCCC");
		puts("DDDEEE.F");
		puts("DGGGEFFF");
		puts(".HGIE.JF");
		puts(".HGIIIJ.");
		puts("HHHI.JJJ");
	}
	else if(n == 8 && m == 9){
		puts("12");
		puts("AAABBB..C");
		puts(".AD.BECCC");
		puts(".AD.BEEEC");
		puts("FDDDGEHHH");
		puts("FFFIGGGH.");
		puts("FJ.IGK.HL");
		puts(".JIIIKLLL");
		puts("JJJ.KKK.L");
	}
	else if(n == 9 && m == 5){
		puts("7");
		puts("AAAB.");
		puts(".A.B.");
		puts("CABBB");
		puts("CCC.D");
		puts("CEDDD");
		puts(".EEED");
		puts("FEGGG");
		puts("FFFG.");
		puts("F..G.");
    }
    else if(n == 5 && m == 9){
    	puts("7");
		puts("AAABBBC..");
		puts(".A..BDCCC");
		puts("EA.FBDCG.");
		puts("EEEFDDDG.");
		puts("E.FFF.GGG");
	}
	else if(n == 6 && m == 9){
		puts("8");
		puts("AAABBBCCC");
		puts(".AD.B.EC.");
		puts(".AD.B.EC.");
		puts("FDDDGEEEH");
		puts("FFF.G.HHH");
		puts("F..GGG..H");
	}
    else if(n == 9 && m == 6){
		puts("8");
		puts("AAABBB");
		puts(".AC.B.");
		puts(".AC.B.");
		puts("DCCCE.");
		puts("DDD.E.");
		puts("D.FEEE");
		puts(".GFFFH");
		puts(".GFHHH");
		puts("GGG..H");
    }
	else if(n == 9 && m == 7){
		puts("10");
		puts("AAABBB.");
		puts(".A..BC.");
		puts("DA.EBC.");
		puts("DDDECCC");
		puts("DFEEE.G");
		puts(".FFFGGG");
		puts("HFIIIJG");
		puts("HHHI.J.");
		puts("H..IJJJ");
	}
	else if(n == 9 && m == 8){
		puts("12");
		puts("A..FFF.J");
		puts("AAADFJJJ");
		puts("ADDDF.IJ");
		puts("B..DIII.");
		puts("BBBGGGIK");
		puts("BEEEGKKK");
		puts(".CEHG.LK");
		puts(".CEHHHL.");
		puts("CCCH.LLL");
	}
	else if(n == 9 && m == 9){
		puts("13");
		puts("AAABBBCCC");
		puts(".AD.BE.C.");
		puts(".AD.BE.C.");
		puts("FDDDEEE.G");
		puts("FFFHHHGGG");
		puts("FIIIHJJJG");
		puts(".KILH.JM.");
		puts(".KILLLJM.");
		puts("KKKL..MMM");
	}
}