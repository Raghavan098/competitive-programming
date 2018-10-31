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

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, _VA_ARGS_)

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

// #define int ll
int main(){ _
	int T,i,j,k,x,ans=0;
	cin>>T;
	bool check=true;
	multiset<char> m1,m2;
	for(int t=1;t<=T;t++){
			int l;
			cin>>l;
			ans=0;
			string a,b;
			cin>>a>>b;
			for(i=0;i<l;i++){
				for(j=i;j<l;j++){
					int n=j-i+1;
					x=0;
					for(k=0;k<l-n + 1;k++){
						m1.clear();
						m2.clear();
						x=0;
						while(x<n){
							m1.insert(a[i+x]);
							m2.insert(b[k+x]);
							x++;
						}
                        // for(auto qq: m1){
                        //     cout << qq << " " ;
                        // }cout << endl;
                        // for(auto qq: m2){
                        //     cout << qq << " " ;
                        // }cout << endl;
						multiset<char>::iterator itr1,itr2;
						check = false;
                        if(m1 == m2){
                            check = true;
                        }
						if(check==true)
							break;
					}
					if(check==true){
						cout<<i<<" "<<j<<endl;
						ans++;
					}
				}
			}
			cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
