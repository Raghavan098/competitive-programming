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

const int N = 405;
int n, m;
vector<string> arr;
vector<vector<int> > cumu;

bool check(int a, int b){
    return (a >= 0 and a < n and b >= 0 and b < m);
}

bool one(int a, int b, int c){
    int temp = cumu[a][c];
    if(b != 0){
        temp -= cumu[a][b-1];
    }
    return (temp > 0);
}

void printmat(){
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}

void rotate(){
    string temp = "";
    for(int i = 0; i < n; i++){
        temp += "*";
    }
    vector<string> b(m, temp);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[j][n - 1 - i] = arr[i][j];
        }
    }
    arr = b;
    n = arr.size();
    m = arr[0].size();
    cumu.clear();
    cumu.resize(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cumu[i][j] = (arr[i][j] == '1');
            if(j != 0){
                cumu[i][j] += cumu[i][j-1];
            }
        }
    }
}

int get(){
    n = arr.size();
    m = arr[0].size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int ans = 0;
            if(arr[i][j] == '1') continue;
            for(int k = 1; k < n; k++){
                if(check(i + k, j + k)){
                    if(arr[i + k][j] == '1' or arr[i + k][j + k] == '1'){
                        break;
                    }
                    if(one(i + k, j, j + k)){
                        continue;
                    }
                    ans++;
                }
                else{
                    break;
                }
            }
            // tr(i, j, ans);
            cnt += ans;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '1')continue;
            int ans = 0;
            for(int k = 1; k < max(n ,m); k++){
                if(check(i + k, j + k) and check(i + k, j - k)){
                    if(arr[i + k][j - k] == '1' or arr[i + k][j + k] == '1'){
                        break;
                    }
                    if(one(i + k, j - k, j + k)){
                        continue;
                    }
                    ans++;
                }
                else{
                    break;
                }
            }
            // tr(i, j, ans);
            cnt += ans;
        }
    }
    return cnt;
}

int32_t main(){ _
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        arr.pb(temp);
    }
    cumu.clear();
    cumu.resize(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cumu[i][j] = (arr[i][j] == '1');
            if(j != 0){
                cumu[i][j] += cumu[i][j-1];
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        int temp = get();
        ans += temp;
        rotate();
    }
    cout << ans << endl;
    return 0;
}
