// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int N = 3e5 + 5;

string s;
int n;
ll a[N], p[N];

class Trie{
private:
	struct Node{
		int count;
		Node *child[2];
	}*root;
public:
	Trie(){
		root = new Node;
		root -> count = 0;
		memset(root -> child, NULL, sizeof(root -> child));
	}

	void insert(ll x){
		Node * temp = root;
		s = "";
		while(x != 0){
			s += (x%2 ? '1' : '0');
			x /= 2;
		}
		while(s.length() < 32)
			s += '0';
		reverse(s.begin(), s.end());
		for(int i = 0; i < s.length(); i++){
			if(temp -> child[s[i] - '0'] == NULL){
				temp -> child[s[i] - '0'] = new Node;
				temp -> child[s[i] - '0'] -> count = 0;
				memset(temp -> child[s[i] - '0'] -> child, NULL, sizeof(temp -> child[s[i] - '0'] -> child));
			}
			temp = temp -> child[s[i] - '0'];
		}
		temp -> count = temp -> count + 1;
	}

	ll search(ll x){
		Node * temp = root;
		s = "";
		ll ans = 0;
		while(x != 0){
			s += (x%2 ? '1' : '0');
			x /= 2;
		}
		while(s.length() < 32)
			s += '0';
		reverse(s.begin(), s.end());
		for(int i = 0; i < s.length(); i++){
			if(temp -> child[(s[i] - '0')] != NULL){
				ans = 2 * ans + (s[i] - '0');
				temp = temp -> child[s[i] - '0'];
			}
			else{
				ans = 2 * ans + 1 - (s[i] - '0');
				temp = temp -> child[1 - (s[i] - '0')];
			}
		}
		return ans;
	}

	void delhelp(Node* root, int i){
		if(i == s.length() - 1){
			if(root -> child[s[i] - '0'] -> count == 1)
				root -> child[s[i] - '0'] = NULL;
			else
				root -> child[s[i] - '0'] -> count = root -> child[s[i] - '0'] -> count - 1;
			return;
		}
		delhelp(root -> child[s[i] - '0'], i + 1);
		if(root -> child[s[i] - '0'] -> child[0] == NULL and root -> child[s[i] - '0'] -> child[1] == NULL)
			root -> child[s[i] - '0'] = NULL;
	}

	void del(ll x){
		s = "";
		ll ans = 0;
		while(x != 0){
			s += (x%2 ? '1' : '0');
			x /= 2;
		}
		while(s.length() < 32)
			s += '0';
		reverse(s.begin(), s.end());
		delhelp(root, 0);
	}
};

int main(){
  Trie *tr = new Trie;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		tr -> insert(p[i]);
	}
	for(int i = 1; i <= n; i++){
		ll val = tr -> search(a[i]);
		cout << (val ^ a[i]) << ' ';
		tr -> del(val);
	}
	cout << '\n';
	return 0;
}
