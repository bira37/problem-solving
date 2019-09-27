#include <iostream>
#include <string>
using namespace std;
 
int main(){
	string str;
	cin>>str;
	int maxi=0;
	int atual=0;
	char antigo='B';
	for(int i=0;i<(int)str.size();i++){
		if(str[i]==antigo){
			atual++;
		} else{
			antigo=str[i];
			atual=1;
		}
		
		
		maxi=max(maxi,atual);
	}
cout<<maxi<<endl;
 