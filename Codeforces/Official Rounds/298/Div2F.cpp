#include <bits/stdc++.h>
//AGORA VAI CARALHOOOOOO
using namespace std;

int n,m;

char mat[5][20];
int ho[5];
int ve[20];
vector< vector<string> > v[6];
vector<int> cur(5);

set< tuple< int, string, vector<int> > > vis;

bool ok = false;
void solve(string last, int col){
  if(vis.count(tuple<int, string, vector<int> >(col, last, cur))) return;
  vis.insert(tuple<int, string, vector<int> >(col, last, cur));
  if(col == m){
    ok = true;
    for(int i=0; i<n; i++){
      if(cur[i] != ho[i]) ok = false;
    }
    return;
  }
  
  if(ok) return;
  
  for(string s : v[n][ve[col]]){
    int soma[n];
    for(int i=0; i<n; i++) soma[i] = 0;
    for(int i=0; i<n; i++){
      if(last[i] == '.' && s[i] == '*') soma[i] = 1;
    }
    bool go = true;
    for(int i=0; i<n; i++){
      if(cur[i] + soma[i] > ho[i]){
        go = false;
        break;
      }
      if(s[i] == '*' && ho[i] - (cur[i] + soma[i]) > ((m-1) - (col-1) + 1)/2){
        go = false;
        break;
      }
      if(s[i] == '.' && ho[i] - (cur[i] + soma[i]) > ((m-1) - col + 1)/2){
        go = false;
        break;
      }  
    }
    if(!go) continue;
    
    for(int i=0; i<n; i++){
      mat[i][col] = s[i];
      cur[i] += soma[i];
    }
    
    solve(s, col+1);
    
    if(ok) return;
    
    for(int i=0; i<n; i++){
      cur[i] -= soma[i];
    }
  }
}

int main(){
  cin >> n >> m;
  
  //initializing n = 1
  v[1].push_back(vector<string>());
  v[1].push_back(vector<string>());
  v[1][0].push_back("."); 
  v[1][1].push_back("*");
  
  //initializing n = 2
  v[2].push_back(vector<string>());
  v[2].push_back(vector<string>());
  v[2][0].push_back("..");
  v[2][1].push_back("*.");
  v[2][1].push_back(".*");
  v[2][1].push_back("**");
  
  //initializing n = 3
  v[3].push_back(vector<string>());
  v[3].push_back(vector<string>());
  v[3].push_back(vector<string>());
  v[3][0].push_back("...");
  v[3][1].push_back("*..");
  v[3][1].push_back(".*.");
  v[3][1].push_back("..*");
  v[3][1].push_back("**.");
  v[3][1].push_back(".**");
  v[3][1].push_back("***");
  v[3][2].push_back("*.*");
  
  //initializing n = 4
  v[4].push_back(vector<string>());
  v[4].push_back(vector<string>());
  v[4].push_back(vector<string>());
  v[4][0].push_back("....");
  v[4][1].push_back("*...");
  v[4][1].push_back(".*..");
  v[4][1].push_back("..*.");
  v[4][1].push_back("...*");
  v[4][1].push_back("**..");
  v[4][1].push_back(".**.");
  v[4][1].push_back("..**");
  v[4][1].push_back("***.");
  v[4][1].push_back(".***");
  v[4][1].push_back("****");
  v[4][2].push_back("*.*.");
  v[4][2].push_back("*..*");
  v[4][2].push_back(".*.*");
  
  //initializing n = 5
  v[5].push_back(vector<string>());
  v[5].push_back(vector<string>());
  v[5].push_back(vector<string>());
  v[5].push_back(vector<string>());
  v[5][0].push_back(".....");
  v[5][1].push_back("*....");
  v[5][1].push_back(".*...");
  v[5][1].push_back("..*..");
  v[5][1].push_back("...*.");
  v[5][1].push_back("....*");
  v[5][1].push_back("...**");
  v[5][1].push_back("..**.");
  v[5][1].push_back(".**..");
  v[5][1].push_back("**...");
  v[5][1].push_back("..***");
  v[5][1].push_back(".***.");
  v[5][1].push_back("***..");
  v[5][1].push_back(".****");
  v[5][1].push_back("****.");
  v[5][1].push_back("*****");
  v[5][2].push_back("*.*..");
  v[5][2].push_back("*..*.");
  v[5][2].push_back("*...*");
  v[5][2].push_back(".*.*.");
  v[5][2].push_back(".*..*");
  v[5][2].push_back("*.**.");
  v[5][2].push_back("*..**");
  v[5][2].push_back("**..*");
  v[5][2].push_back(".**.*");
  v[5][2].push_back(".*.**");
  v[5][2].push_back("**.*.");
  v[5][2].push_back("***.*");
  v[5][2].push_back("*.***");
  v[5][2].push_back("**.**");
  v[5][3].push_back("*.*.*");
   
  for(int i=0; i<n; i++) cur[i] = 0;
  for(int i=0; i<n; i++) cin >> ho[i];
  for(int i=0; i<m; i++) cin >> ve[i]; 
  string init;
  for(int i=0; i<n; i++){
    init += '.';
    cur[i] = 0;
  }
  
  solve(init, 0); 
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << mat[i][j];
    }
    cout << endl;
  }
  
}