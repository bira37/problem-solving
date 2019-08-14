#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
  
  int n,c,t=0;
  while(cin >> n >> c, n+c){
    cout << "Teste " << ++t << endl;
    list<int> l;
    for(int i=0; i<n; i++){
      int x;
      cin >> x;
      l.push_back(x);
    }
    for(int i=0; i<c; i++){
      int act, num;
      cin >> num >> act;
      list<int>::iterator it = l.begin();
      for(int j=0; j<num; j++){
        int k;
        cin >> k;
        if(act != k) l.erase(it++);
        else it++;
      }
    }
    cout << *l.begin() << endl;
  }
}
