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
