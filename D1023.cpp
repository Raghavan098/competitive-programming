// g++ -std=c++14

// 5 4 
// 1 1 2 4 1

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

const int N = 2e5 + 9;
int fin[N], str[N];
int n, q;
int arr[N];
set<int> m[N];

bool check(){
    int s = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i-1]){
            m[arr[i-1]].insert(s);
            fin[s] = i-1;
            str[i-1] = s;
            s = i;
        }
    }
    m[arr[n-1]].insert(s);
    fin[s] = n-1;
    str[n-1] = s;
    if( (int)m[q].size() != 1){
        return false;
    }
    for(int i = q; i >= 1; i--){
        // tr((int)m[i].size(), i);
        // for(auto j: m[i]){
        //     tr(j);
        // }
        if((int)m[i].size() == 0)continue;
        if((int)m[i].size() > 1)return false;
        int s = *m[i].begin();
        int e = fin[s];
        if(s != 0 and e != n-1 and arr[s-1] == arr[e + 1]){
            fin[str[s - 1]] = fin[e + 1];
            str[fin[e + 1]] = str[s - 1];
            m[arr[s-1]].erase(e+1);
            continue;
        }
        if(e != n-1){
            m[arr[e + 1]].erase(e+1);
            m[arr[e + 1]].insert(s);
            fin[s] = fin[e+1];
            str[fin[e+1]] = str[s];
        }
        else if(s != 0){
            fin[str[s-1]] = fin[s];
            str[fin[s]] = str[s-1];
        }
        else{
            return true;
        }
    }
    return true;
}

int main(){ _
    cin >> n >> q;
    int done = 0;
    int d2 = 0;
    int ind = -1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] != 0){
            done = 1;
        }
        if(arr[i] == q){
            d2 = 1;
        }
        if(arr[i] == 0){
            ind = i;
        }
    }
    if(done == 0){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << q << " ";
        }cout << endl;
        return 0;
    }
    if(d2 == 0 and ind == -1){
        cout << "NO\n";
        return 0;
    }
    if(d2 == 0){
        arr[ind] = q;
    }
    int curr = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            arr[i] = curr;
        }
        else{
            curr = arr[i];
        }
    }
    curr = arr[n-1];
    for(int i = n-1; i >= 0; i--){
        if(arr[i] == 0){
            arr[i] = curr;
        }
        else{
            curr = arr[i];
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << " ";
    // }cout << endl;
    if(check()){
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
