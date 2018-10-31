// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


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
#define all(c) c.begin(),c.end()
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

int n, arr[N];

int solve(){
    cin >> n;
    int check = 0;
    int st;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] != -1 and check == 0){
            check = 1;
        }
        if(arr[i] != -1 and check == 1){
            check = 2;
        }
        if(arr[i] != -1){
            v.pb(i);
        }
    }
    if(check <= 1){
        cout << "inf\n";
        return 0;
    }
    st = arr[v[0]];
    int done = 0;
    int k;
    for(int i = v[0] + 1; i < n; i++){
        st++;
        if(arr[i] != -1){
            if(arr[i] != st){
                done = 1;
                k = (st - arr[i]);
                break;
            }
        }
    }
    if(k < 0){
        cout << "impossible\n";
        return 0;
    }
    if(done == 0){
        cout << "inf" << endl;
        return 0;
    }
    vector<int> fact;
    for(int i = 1; i*i <= k; i++){
        if(k % i == 0){
            fact.pb(i);
            if(k/i != i){
                fact.pb(k/i);
            }
        }
    }
    sort(all(fact));
    st = v[0];
    for(int i = (int)fact.size() - 1; i >= 0; i--){
        int curr = arr[st];
        int no = 0;
        for(int j = st; j < n; j++){
            if(arr[j] != -1 and arr[j] != curr){
                no = 1;
                break;
            }
            curr++;
            if(curr == fact[i] + 1){
                curr = 1;
            }
        }
        curr = arr[st] - 1;
        if(curr == 0){
            curr = fact[i];
        }
        for(int j = st - 1; j >= 0; j--){
            if(arr[j] != -1 and arr[j] != curr){
                no = 1;
                break;
            }
            curr--;
            if(curr == 0){
                curr = fact[i];
            }
        }
        if(no == 0){
            cout << fact[i] << endl;
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}

int32_t main(){ _
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
