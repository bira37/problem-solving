#include <bits/stdc++.h>

using namespace std;

int main(){
  string board[2];
  cin >> board[0] >> board[1];
  
  int n = board[0].size();
  int ans = 0;
  for(int i=0; i<n-1; i++){
    //try first
    if(board[0][i] == '0' && board[0][i+1] == '0' && board[1][i] == '0'){
      board[0][i] = board[0][i+1] = board[1][i] = 'X';
      ans++;
      continue;
    }
    //try second
    if(board[0][i] == '0' && board[0][i+1] == '0' && board[1][i+1] == '0'){
      board[0][i] = board[0][i+1] = board[1][i+1] = 'X';
      ans++;
      continue;
    }
    //try third
    if(board[0][i+1] == '0' && board[1][i] == '0' && board[1][i+1] == '0'){
      board[0][i+1] = board[1][i] = board[1][i+1] = 'X';
      ans++;
      continue;
    }
    //try fourth
    if(board[0][i] == '0' && board[1][i] == '0' && board[1][i+1] == '0'){
      board[0][i] = board[1][i] = board[1][i+1] = 'X';
      ans++;
      continue;
    }
  }
  cout << ans << endl;
}