#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

struct Trie{
	struct node{
		node *e[26];

		node(){
			for(int i = 0; i < 26; i++) e[i] = NULL;
		}
	};

	node *ROOT;

	trie(){
		ROOT = new node();
	}

	~trie(){
		queue<node *> q;
		node *cur = ROOT;
		q.push(cur);
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int i = 0; i < 26; i++) if(cur->e[i] != NULL) q.push(cur->e[i]);
			delete cur;
		}
	}

	void insert(string &s){
		int l = s.length();
		node *cur = ROOT, *next = NULL;

		for(int i = 0; i < l; i++){
			if(cur->e[s[i]-'a'] == NULL) cur->e[s[i]-'a'] = new node();
			cur = cur->e[s[i]-'a'];
		}
		return;
	}
};


int main(){
  return 0;
}
