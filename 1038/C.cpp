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

#define int ll
const int N = 1e5 + 100;
int arr[N], brr[N], a, b;
queue<int> ai, bi;
int n;

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cin >> brr[i];
    }
    sort(arr,arr+n);
    sort(brr,brr+n);
    reverse(arr,arr+n);
    reverse(brr,brr+n);
    for(int i = 0; i < n; i++){
        ai.push(arr[i]);
        bi.push(brr[i]);
    }
    for(int i = 0; i < 2*n; i++){
        if(i%2==0){
            if(ai.empty()){
                bi.pop();
            }
            else if(bi.empty()){
                a += ai.front();
                ai.pop();
            }
            else{
                int x = ai.front();
                int y = bi.front();
                if(x > y){
                    a += ai.front();
                    ai.pop();
                }
                else{
                    bi.pop();
                }
            }
        }
        else{
            if(bi.empty()){
                ai.pop();
            }
            else if(ai.empty()){
                b += bi.front();
                bi.pop();
            }
            else{
                int x = ai.front();
                int y = bi.front();
                if(y > x){
                    b += bi.front();
                    bi.pop();
                }
                else{
                    ai.pop();
                }
            }
        }
    }
    cout << a - b << endl;
    return 0;
}
