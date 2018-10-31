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
const int M = 1e17 + 100;
const int LOG = 45;

int n, q, m, max_height, curr_rem;
int sum[12][LOG], len[12][LOG], cumu[N], cumu_len[N];
string start, connection[12];

void print_all(){
    for(int i = 0; i < 10; i++){
        tr(i);
        for(int j = 0; j < LOG; j++){
            cout << sum[i][j] << " ";
        }cout << endl;
    }
    for(int i = 0; i < 10; i++){
        tr(i);
        for(int j = 0; j < LOG; j++){
            cout << len[i][j] << " ";
        }cout << endl;
    }
    tr(max_height);
}

void calc(int num){
    vector<int> cnt(10), temp(10);
    cnt[num]++;
    sum[num][0] = num;
    len[num][0] = 1;
    for(int i = 1; i < LOG; i++){
        int curr_sum = 0;
        int curr_len = 0;
        for(int j = 0; j < 10; j++){
            int pre = cnt[j];
            for(int k = 0; k < (int)connection[j].size(); k++){
                int no = connection[j][k] - '0';
                temp[no] += pre;
                curr_len += pre;
                curr_sum += pre*no;
            }
        }
        sum[num][i] = curr_sum;
        len[num][i] = curr_len;
        swap(cnt, temp);
        temp.clear();
        temp.resize(10);
    }
}

void get_length(){
    int curr_len = start.size();
    max_height = 0;
    vector<int> cnt(10), temp(10);
    for(auto i: start){
        int no = i  - '0';
        cnt[no]++;
    }
    while(curr_len < m){
        max_height++;
        curr_len = 0;
        for(int j = 0; j < 10; j++){
            int pre = cnt[j];
            for(int k = 0; k < (int)connection[j].size(); k++){
                int no = connection[j][k] - '0';
                temp[no] += pre;
                curr_len += pre;
            }
        }
        swap(cnt, temp);
        temp.clear();
        temp.resize(10);
    }
}

void pre_process(){
    for(int i = 0; i < 10; i++){
        calc(i);
    }
    get_length();
    cumu[0] = sum[start[0] - '0'][max_height];
    cumu_len[0] = len[start[0] - '0'][max_height];
    for(int i = 1; i < n; i++){
        cumu[i] = sum[start[i] - '0'][max_height];
        cumu_len[i] = len[start[i] - '0'][max_height];
        cumu[i] += cumu[i-1];
        cumu_len[i] += cumu_len[i-1];
    }
}

int dfs(int no, int h){
    if(curr_rem <= 0){
        return 0;
    }
    int down = max_height - h;
    if(len[no][down] <= curr_rem){
        curr_rem -= len[no][down];
        return sum[no][down];
    }
    int ans = 0;
    for(int i = 0; i < (int)connection[no].size(); i++){
        int temp = connection[no][i] - '0';
        ans += dfs(temp, h + 1);
    }
    return ans;
}

int get(int p){
    if(p == 0){
        return 0;
    }
    if(max_height == 0){
        return cumu[p-1];
    }
    curr_rem = p;
    int ans = 0, ans_tot = 0;
    int ind = -1;
    int l = 0, r = n-1;
    int mid;
    while(l <= r){
        mid = (l + r)/2;
        if(cumu_len[mid] <= p){
            ans_tot = cumu_len[mid];
            ans = cumu[mid];
            ind = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    curr_rem -= ans_tot;
    if(curr_rem == 0){
        return ans;
    }
    ans += dfs(int(start[ind + 1] - '0'), 0);
    return ans;
}

int32_t main(){
    cin >> n >> m >> q;
    cin >> start;
    for(int i = 0; i < 10; i++){
        cin >> connection[i];
    }
    pre_process();
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << get(r) - get(l-1) << endl;
    }
    return 0;
}
