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

const long long M = 1e9 + 7;

long long pow(long long a, long long p) {
	if (!p) return 1;
	long long ret = pow(a, p >> 1);
	ret = (ret * ret) % M;
	if (p & 1LL) ret = (ret * a) % M;
	return ret;
}

long long mod_of_lcm(vector<long long> &a,long long n)
{
	long long ans=1;
	for(long long i=0;i<n;i++)
 	{
 		if(a[i]!=1)
 		{
 			for(long long j=i+1;j<n;j++)
 			{
 				a[j]/=__gcd(a[i],a[j]);
				//reducing along long remaining numbers by thier gcd with currebt number
			}
			ans=(ans*a[i])%M;//mod
		}
	}
	return ans;
}

vector<long long> z;
long long n;
string s;
const long long mod = 1e9+7;

void z_function(){
  long long L = 0;
  long long R = 0;
  for(long long i=1;i<n;i++){
    if(i>R){
      L = R = i;
      while(R<n and s[R-L]==s[R]){
        R++;
      }
      z[i] = R - L;
      R--;
    }
    else{
      long long k = i-L;
      if(z[k]<R-i+1){
        z[i] = z[k];
      }
      else{
        L = i;
        while(R<n and s[R-L]==s[R]){
          R++;
        }
        z[i] = R - L;
        R--;
      }
    }
  }
}

long long solve(vector<string> v){
    vector<long long> fin;
    cout<<v<<endl;
    for(long long i=0;i<v.size();i++){
        long long n1 = v[i].size();
        string temp = v[i];
        temp = temp + temp + temp;
        n = temp.size();
        s = temp;
        z.clear();
        z.resize(n);
        z_function();
        vector<bool> can;
        can.resize(n1,false);
        tr(temp,n1);
        tr(z);
        for(long long i=n1;i<2*n1;i++){
            if(z[i]>=n1){
                can[i%n1] = true;
            }
        }
        temp = v[i];
        long long curr = 0;
        for(long long i=1;i<=2*n1;i++){
            curr += i;
            curr %= n1;
            if(can[curr]==true){
                fin.pb(i);
                break;
            }
        }
    }
    cout<<fin<<endl;
    if(v.size()==1){
        return fin[0];
    }
    else{
        return mod_of_lcm(fin,fin.size());
    }
}

int main(){ _
    long long n;
    vector<string> s;
    cin>>n;
    for(long long i=0;i<n;i++){
        string t;
        cin>>t;
        s.pb(t);
    }
    cout<<solve(s)<<endl;
}
