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

// 1
// 10 5 4
// 1111
// 1111
// 1111
// 1111
// 1111
// 0000
// 0000
// 0000
// 0000
// 0001
// 0000
// 1000


#define int ll
const int N = 200;
int n, m, p;
string arr[N];
int curr[N];
vector<pair<int,int> > cost;
vector<vector<int> > v;
string forb[N];
set<string> s;
int arr1[N];
int cnt;
void combinationUtil(int data[], int start, int end,
    int index, int r);
void printCombination(int n, int r)
{
    int data[r];
    combinationUtil(data, 0, n-1, 0, r);
}

void combinationUtil(int data[], int start, int end,
    int index, int r)
    {
        if(cnt >= m+1){
            return ;
        }
        if (index == r)
        {
            vector<int> temp;
            for (int j=0; j<r; j++)
                temp.pb(data[j]);
            v.pb(temp);
            cnt++;
            return;
        }
        for (int i=start; i<=end && end-i+1 >= r-index; i++)
        {
            data[index] = arr1[i];
            combinationUtil(data, i+1, end, index+1, r);
            if(cnt >= m+1){
                break;
            }
        }
    }
int solve(int ts){
    cin >> n >> m >> p;
    cost.clear();
    s.clear();
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        cin >> forb[i];
        s.insert(forb[i]);
    }
    for(int i = 0; i <= p; i++){
        arr1[i] = i;
    }
    string ans = "";
    int cur_cost = 0;
    for(int i = 0; i < p; i++){
        int a = 0;
        int b = 0;
        for(int j = 0; j < n; j++){
            if(arr[j][i] == '1'){
                a++;
            }
            else{
                b++;
            }
        }
        if(a > b){
            ans += '1';
            curr[i] = a;
            cur_cost += b;
            // tr(a, b, 1, i);
            cost.pb(mp(a - b, i));
        }
        else{
            ans += '0';
            curr[i] = b;
            cur_cost += a;
            // tr(a, b, 0, i);
            cost.pb(mp(b - a, i));
        }

    }
    sort(cost.begin(), cost.end());
    if(s.find(ans) == s.end()){
        cout << "Case #" << ts << ": " << cur_cost << endl;
        return 0;
    }
    int original = cur_cost;
    string ori_s = ans;
    int final_ans = inf;
    for(int i = 1; i <= p; i++){
        v.clear();
        cnt = 0;
        printCombination(p,i);
        sort(v.begin(), v.end());
        cur_cost = original;
        ans = ori_s;
        for(int q = 0; q < v.size(); q++){
            cur_cost = original;
            ans = ori_s;
            for(int j = 0; j < v[q].size(); j++){
                cur_cost += cost[v[q][j]].fi;
                if(ans[cost[v[q][j]].se] == '1'){
                    ans[cost[v[q][j]].se] = '0';
                }
                else{
                    ans[cost[v[q][j]].se] = '1';
                }

            }
            if(s.find(ans) == s.end()){
                final_ans = min(final_ans, cur_cost);
            }
        }
    }
    cout << "Case #" << ts << ": " << final_ans << endl;
    return 0;
}

int32_t main(){ _
    __
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}
