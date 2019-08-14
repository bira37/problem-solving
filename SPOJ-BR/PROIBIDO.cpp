#include <bits/stdc++.h>

using namespace std;

struct node{
	int key, val;
	node * l, * r;
	node(){}
	node(int k, int v, node * l, node * r) : key(k), val(v), l(l), r(r) {}
};

void split(node * root, node *& l, node *& r, int val){
	if(root == NULL){
		l = NULL;
		r = NULL;
		return;
	}
	if(val <= root->val){
		r = root;
		split(root->l, l, root->l, val);
	}
	else if(root->val < val){
		l = root;
		split(root->r, root->r, r, val);
	}
}

node* join(node * l , node * r){
	if(l == NULL) return r;
	if(r == NULL) return l;
	if(l->key >= r->key){
		l->r = join(l->r, r);
		return l;
	}
	else {
		r->l = join(l, r->l);
		return r;
	}
}

void insert(node *& root, int val, int key){
	if(!root){
		root = new node(key, val, NULL, NULL);
		return;
	}
	else if(root->key <= key){
		node * aux = new node(key, val, NULL, NULL);
		split(root, aux->l, aux->r, val);
		root = aux;
		return;
	}
	if(val <= root->val) insert(root->l, val, key);
	else insert(root->r, val, key);
}

void remove(node*& root, int val){
	if(!root) return;
	if(root->val == val){
		node *old = root;
		root = join(root->l, root->r);
		delete old;
	}
	else if(root->val < val) remove(root->r, val);
	else remove(root->l, val);
}

bool contains(node * root, int val){
	if(!root) return false;
	if(root->val == val) return true;
	else if(root->val < val) return contains(root->r, val);
	else return contains(root->l,val);
}

int main(){
	int n;
	cin >> n;
	node * root = NULL;
	
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		insert(root, x, rand()%((int)1e9+7));
	}
	int x;
	while(cin >> x){
		if(contains(root, x)) cout << "sim" << endl;
		else cout << "nao" << endl;
	}
}
		
