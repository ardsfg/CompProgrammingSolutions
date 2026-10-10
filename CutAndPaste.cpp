// Problem: Cut and Paste
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2072
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
using namespace std;

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct node{
	char val;
	int weight, size;
	node *l,*r;
	node(char val) : val(val), weight(rng()), size(1), l(NULL), r(NULL) {}
}*root;

inline int size(node *k){
	return (k == NULL) ? 0 : k->size;
}

void split(node *t, node *&l, node *&r, int key){
	if(!t){
		l = r = NULL;
		return;
	}
	if(size(t->l) < key){
		split(t->r, t->r, r, key - size(t->l) - 1);
		l = t;
	}else{
		split(t->l, l, t->l, key);
		r = t;
	}
	t->size = size(t->l) + size(t->r) + 1;
}

void merge(node *&t, node *l, node *r){
	if(l == NULL){
		t = r;
		return;
	}
	if(r == NULL){
		t = l;
		return;
	}
	if(l->weight >= r->weight){
		merge(l->r, l->r, r);
		t = l;
	}else{
		merge(r->l, l, r->l);
		t = r;
	}
	t->size = size(t->l) + size(t->r) + 1;
}

ostream &operator<<(ostream &os, node* p){
	if(!p){
		return os;
	}
	os<<p->l;
	os<<p->val;
	os<<p->r;
	return os;
}


int main(){
	int n,m; cin>>n>>m;
	string s; cin>>s;
	for(int i = 0; i<n; i++){
		node *c = new node(s[i]);
		merge(root, root, c);
	}
	
	for(int i = 0; i<m; i++){
		int l, r; cin>>l>>r;
		node *a; node *b; node *c; node *d;
		split(root, a, b, l-1);
		split(b, c, d, r-l+1);
		merge(root, a,d);
		// cout<<root<<endl;
		merge(root, root, c);
		// cout<<root<<endl;
	}
	cout<<root<<endl;
}