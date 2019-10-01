#include <bits/stdc++.h>
#define ii pair<int,int>
#define w first
#define h second
 
using namespace std;
 
int main(){
  vector< ii > v(3);
  sort(v.begin(), v.end());
  for(int i=0; i<3; i++) cin >> v[i].w >> v[i].h;
  sort(v.begin(), v.end());
  //permutate
  do {
    //do rotation masks
    for(int msk = 0; msk < (1<<3); msk++){
      //rotate
      for(int i=0; i<3; i++){
        if(msk & (1<<i)) swap(v[i].w, v[i].h);
      }
      
      //case 1
      if(v[0].w + v[1].w + v[2].w == v[0].h and v[0].h == v[1].h and v[0].h == v[2].h){
        cout << "YES" << endl;
        return 0;
      }
      
      //case 2
      if(v[0].h + v[1].h + v[2].h == v[0].w and v[0].w == v[1].w and v[0].w == v[2].w){
        cout << "YES" << endl;
        return 0;
      }
      
      //case 3
      if(v[0].h + v[1].h == v[2].h and v[2].h == v[2].w + v[0].w and v[0].w == v[1].w){
        cout << "YES" << endl;
        return 0;
      }
      
      //case 4
      if(v[0].h == v[1].h + v[2].h and v[1].w == v[2].w and v[0].h == v[1].w + v[0].w){
        cout << "YES" << endl;
        return 0;
      }
      
      //back to normal
      for(int i=0; i<3; i++){
        if(msk & (1<<i)) swap(v[i].w, v[i].h);
      }  
    }
  } while(next_permutation(v.begin(), v.end()));
  
  cout << "NO" << endl;
}
