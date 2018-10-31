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

const int N = 2005;

int n, k, p;
int arr[N], b[N];
vector<int> before, after;

int get(int a, int b){
    return  (abs(a - b) + abs(a - p));
}

bool check(int t){
    deque<int> q;
    for(int i = 0; i < k; i++){
        q.push_back(b[i]);
    }
    for(int i = 0; i < (int)before.size(); i++){
        if(q.empty()){
            return false;
        }
        int temp = q.front();
        while(get(temp, before[i]) > t){
            q.pop_front();
            if(q.empty()){
                return false;
            }
            temp = q.front();
        }
        q.pop_front();
    }

    for(int i = (int)after.size() - 1; i >= 0; i--){
        if(q.empty()){
            return false;
        }
        int temp = q.back();
        while(get(temp, after[i]) > t){
            q.pop_back();
            if(q.empty()){
                return false;
            }
            temp = q.back();
        }
        q.pop_back();
    }
    return true;
}

int32_t main(){ _
    cin >> n >> k >> p;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }
    sort(b, b + k);
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        if(arr[i] < p){
            before.pb(arr[i]);
        }
        else{
            after.pb(arr[i]);
        }
    }
    // tr(before, after);
    int l = 0, r = 1e18;
    int mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
