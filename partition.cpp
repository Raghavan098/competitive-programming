#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

int n;

int main(){_
	cin>>n;
	if(n%4==0){
		cout<<0<<endl;
		cout<<n/2<<" ";
		for(int i=1;i<=n/2;i+=2){
			cout<<i<<" "<<n+1-i<<" ";
		}
		cout<<endl;
	}
	else if(n%4==1){
		cout<<1<<endl;
		cout<<n/2+1<<" "<<1<<" ";
		for(int i=1;i<=n/2;i+=2){
			cout<<i+1<<" "<<n+1-i<<" ";
		}
		cout<<endl;
	}
	else if(n%4==2){
		cout<<1<<endl;
		cout<<n/2<<" "<<1<<" ";
		for(int i=1;i<n/2;i+=2){
			cout<<i+2<<" "<<n+1-i<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<0<<endl;
		cout<<n/2+1<<" "<<1<<" "<<2<<" ";
		for(int i=1;i<n/2;i+=2){
			cout<<i+3<<" "<<n+1-i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
