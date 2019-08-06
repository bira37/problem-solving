#include <bits/stdc++.h>
using namespace std;

int main(){
	string conj[3][6] = {{"o","amos","o","emos","o","imos"}, {"as","Ais","es","Eis","es","Is"}, {"a","an","e","en","e","en"}};
	string palavra, pessoa, pessoa2, inutil, resp;
	while(cin >> palavra >> pessoa >> inutil >> pessoa2 >> resp){
		palavra.erase(palavra.end()-1);
		pessoa2.erase(pessoa2.end()-1);
		string r;
		if(pessoa == "first"){
			if(pessoa2 == "singular"){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[0][0]; 	
			}
			else {
				if(*(palavra.end()-2) == 'a'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[0][1];
				}
				else if(*(palavra.end()-2) == 'e'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[0][3];
				}
				else {
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[0][5];
				}
			}
		}
		else if(pessoa == "second"){
			if(pessoa2 == "singular"){
				if(*(palavra.end()-2) == 'a'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][0];
				}
				else if(*(palavra.end()-2) == 'e'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][2];
				}
				else {
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][4];
				}
			}
			else {
				if(*(palavra.end()-2) == 'a'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][1];
				}
				else if(*(palavra.end()-2) == 'e'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][3];
				}
				else {
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[1][5];
				}
			}
		}
		else {
			if(pessoa2 == "singular"){
				if(*(palavra.end()-2) == 'a'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][0];
				}
				else if(*(palavra.end()-2) == 'e'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][2];
				}
				else {
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][4];
				}
			}
			else {
				if(*(palavra.end()-2) == 'a'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][1];
				}
				else if(*(palavra.end()-2) == 'e'){
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][3];
				}
				else {
					r = string(palavra.begin(), palavra.end()-2);
					r+=conj[2][5];
				}
			}
		}
		if(resp == r) cout << "correct" << endl;
		else cout << "incorrect, should be " << r << endl;
	}
}
		
	
		 

