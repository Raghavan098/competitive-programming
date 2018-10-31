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

const int N = 200;
const int Q = 2e4;
int arr[N][N], n, m, q1;
int q[Q][5];

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}

void rot_row(int r){
    int temp = arr[r][m-1];
    for(int i = m-1; i >= 1; i--){
        arr[r][i] = arr[r][i-1];
    }
    arr[r][0] = temp;
    // print();
}

void rot_col(int c){
    int temp = arr[n-1][c];
    for(int i = n-1; i >= 1; i--){
        arr[i][c] = arr[i-1][c];
    }
    arr[0][c] = temp;
    // print();
}

int32_t main(){
    cin >> n >> m >> q1;
    for(int i = 0; i < q1; i++){
        int temp;
        cin >> temp;
        if(temp == 1 or temp == 2){
            q[i][0] = temp;
            cin >> q[i][1];
        }
        else{
            q[i][0] = temp;
            cin >> q[i][1] >> q[i][2] >> q[i][3];
        }
    }
    for(int i = q1-1; i >= 0; i--){
        if(q[i][0] == 1){
            rot_row(q[i][1] - 1);
        }
        if(q[i][0] == 2){
            rot_col(q[i][1] - 1);
        }
        else{
            int a = q[i][1] - 1;
            int b = q[i][2] - 1;
            arr[a][b] = q[i][3];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }cout << endl;
    }
}
