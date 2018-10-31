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

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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


const unsigned PRIME_BASE = 257;
const unsigned PRIME_MOD = 1000000007;



void computeLPSArray(string pat, int M,int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j  = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            return true;
            j = lps[j-1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
    return false;
}


string s;
int n;

string get_string(int a){
  string ans = "";
  for(int i=0;i<=a;i++){
    ans+=s[i];
  }
  return ans;
}


int  main(){
  cin>>s;
  n = s.size();
  ll prefix = 0;
  ll sufix = 0;
  ll curp = 1;
  vector<int> brs;
  for(int i=0;i<n-1;i++){
    prefix+=s[i]*curp;
    sufix*=PRIME_BASE;
    sufix%=PRIME_MOD;
    sufix+=s[n-i-1];
    prefix%=PRIME_MOD;
    sufix%=PRIME_MOD;
    curp*=PRIME_BASE;
    curp%=PRIME_MOD;
    // tr(prefix,sufix);
    if(prefix==sufix){
      // tr(i,prefix,sufix);
      brs.pb(i);
    }
  }
  int l = 0;
  int r = brs.size()-1;
  int mid;
  string s1;
  string final_ans;
  int done =0;
  string to_check = "";
  for(int i=1;i<n-1;i++){
    to_check+=s[i];
  }
  // tr(to_check);
  while(l<=r){
    mid = (l+r)/2;
    s1 = get_string(brs[mid]);
    // tr(s1);
    if(KMPSearch(s1,to_check)==true){
      final_ans = s1;
      done = 1;
      l = mid+1;
    }
    else{
      r = mid-1;
    }
  }
  if(done==0){
    cout<<"Just a legend\n";
    return 0;
  }
  else{
    cout<<final_ans<<endl;
  }
  return 0;
}
