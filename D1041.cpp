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

const int N = 2e5 + 100;
int n, h;
int arr[N][2], cumulative[N];

int find(int c){
    int l = 0;
    int r = n - 1;
    int mid, ans = -1;
    while(l <= r){
        mid = (l + r)/2;
        if(arr[mid][1] <= c){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}

int get(int i){
    int l = arr[i][0];
    int r = 2e9 + 1;
    int mid, ans;
    while(l <= r){
        mid = (l + r)/2;
        int ind = find(mid);
        int fall = h - mid + arr[i][0];
        if(ind != -1){
            fall += cumulative[ind];
            if(i != 0){
                fall -= cumulative[i-1];
            }
            if(ind < (n - 1) and mid > arr[ind + 1][0]){
                fall += (mid - arr[ind + 1][0]);
            }
        }
        // tr(mid, fall, mid, l, r);
        if(fall > 0){
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int32_t main(){
    cin >> n >> h;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        if(i == 0){
            cumulative[i] = arr[i][1] - arr[i][0];
        }
        else{
            cumulative[i] = cumulative[i-1] + (arr[i][1] - arr[i][0]);
        }
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        int x1 = arr[i][0];
        int x2 = get(i);
        // tr(x1, x2);
        if((x2 - x1) > ans){
            ans = x2 - x1;
        }
    }
    cout << ans << endl;
}
