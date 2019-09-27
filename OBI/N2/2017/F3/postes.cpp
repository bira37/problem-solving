#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int s=0,c=0;
	int aux;
	for(int i=0;i<n;i++){
		cin>>aux;
		if(aux<50){
			s++;
		}else if(aux<85)c++;
	}
	cout<<s<<" "<<c<<endl;
}