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
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}\


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int n;
map<string,string> m;

string strip(string s){
  int ind = 0;
  string ans = "";
  while(s[ind]=='&'){
    ind++;
  }
  while(s[ind]!='*' and ind<s.size()){
    ans+=s[ind];
    ind++;
  }
  return ans;
}

string get_type(string s){
  string k = strip(s);
  // tr(k,s);
  for(auto it = m.begin();it!=m.end();it++){
    auto temp = *it;
    if(k==temp.fi){
      return temp.fi;
    }
  }
  if("void"==k){
    return "void";
  }
  return "errtype";
}

string simplify(string s){
  if(s.find("errtype")!=string::npos){
    return "errtype";
  }
  else{
    int a = 0;
    int b = 0;
    int curp = 0;
    while(s[curp]=='&'){
      a++;
      curp++;
    }
    curp = s.size()-1;
    while(s[curp]=='*'){
      b++;
      curp--;
    }
    if(a>b){
      return "errtype";
    }
    else if(a==b){
      return "void";
    }
    else{
      string temp = "void";
      for(int i=0;i<b-a;i++){
        temp+='*';
      }
      return temp;
    }
  }
}

string replace(string a,string b,int ind,string typ){
  string pre = "";
  for(int i=0;i<ind;i++){
    pre+=a[i];
  }
  string sux = "";
  for(int i=ind+typ.size();i<a.size();i++){
    sux+=a[i];
  }
  return pre+b+sux;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    if(temp=="typedef"){
      string a,b;
      cin>>a>>b;
      vector<string> v;
      v.pb(temp);
      v.pb(a);
      v.pb(b);
      string typ = get_type(v[1]);
      // tr(typ);
      if(typ=="void"){
        m[v[2]] = simplify(v[1]);
        // tr(m[v[2]],v[2]);
      }
      else if(typ=="errtype"){
        if(strip(v[1])=="errtype"){
          m[v[2]] = "errtype";
        }
        continue;
      }
      else{
        int ind = v[1].find(typ);
        string tt = m[typ];
        v[1] = replace(v[1],tt,ind,typ);
        m[v[2]] = simplify(v[1]);
        // tr(v[1],m[v[2]],tt,ind,typ);
      }
    }
    else{
      string a;
      cin>>a;
      string typ = get_type(a);
      // tr(typ);
      if(typ=="errtype"){
        cout<<"errtype"<<endl;
        continue;
      }
      int ind = a.find(typ);
      string tt = m[typ];
      // tr(typ,ind,tt,a);
      if(ind==string::npos){
        a = tt;
      }
      else
        a = replace(a,tt,ind,typ);
      cout<<simplify(a)<<endl;
    }
  }
  return 0;
}
