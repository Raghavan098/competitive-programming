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

const int N = 200;
map<int,vector<char> > g;
vector<int> dd;
int n;
int in[N];
int visited[N];
string arr[N];
vector<string> v;
int mx = -1;
string to = "";

void f(int i,int s1,int e1){
    if(i>=mx){
        return;
    }
    if((e1-s1)==0){
        return;
    }
    string temp = "";
    temp += arr[s1][i];
    int s = s1;
    int e;
    set<char> ss;
    for(int j = s1+1;j <= e1;j++){
        if(arr[j][i]==arr[j-1][i]){continue;}
        else{
            e = j-1;
            if(ss.find(arr[j][i])!=ss.end() or arr[j][i]=='A'){
                cout<<"Impossible\n";
                exit(0);
            }
            ss.insert(arr[j][i]);
            temp += arr[j][i];
            f(i+1,s,e);
            s = j;
        }
    }
    if(s!=e1){
        f(i+1,s,e1);
    }
    if(temp.size()!=1)
        v.pb(temp);
}

void dfs(int v){
    visited[v] = 1;
    if(char(v + 'a')!='A')
        to += char(v + 'a');
    for(auto u:g[v]){
        if(visited[u-'a']==0){
            in[u-'a']--;
            if(in[u-'a']==0){
                dfs(u-'a');
            }
        }
    }
}

void topological_sort(){
    dfs('A'-'a');
}


int main(){ _
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx = max(mx,(int)arr[i].length());
    }
    for(int i=0;i<n;i++){
        if(arr[i].size()<mx){
            for(int j=arr[i].size();j<mx;j++){
                arr[i] += 'A';
            }
        }
    }
    f(0,0,n-1);
    string x = "A";
    for(char i = 'a';i<='z';i++){
        v.pb(x+i);
    }
    for(int i=0;i<v.size();i++){
        string temp = v[i];
        for(int j=0;j<temp.size();j++){
            for(int k=j+1;k<temp.size();k++){
                g[temp[j] - 'a'].pb(temp[k]);
                if(temp[j]!=temp[k]){
                    in[temp[k]-'a']++;
                }
            }
        }
    }
    topological_sort();
    if(to.size()!=26){
        cout<<"Impossible\n";
        return 0;
    }
    cout<<to<<endl;
    return 0;
}
