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

const int N = 4e5 + 100;
const int MAX_IND = 4e5 + 10;
int bit[MAX_IND + 100];

void update(int ind, int val){
    while(ind <= MAX_IND){
        bit[ind] += val;
        ind += (ind & -ind);
    }
}

int query(int ind){
    if(ind == 0) return 0;
    int ans = 0;
    while(ind > 0){
        ans += bit[ind];
        ind -= (ind & -ind);
    }
    return ans;
}

int query_range(int l, int r){
    return query(r) - query(l - 1);
}


struct line{
    int a, b, c, d;
    int ori, mark;
    line(int a, int b, int c, int d){
        if(a == c){
            ori = 1;
            if(b < d){
                swap(b, d);
            }
        }
        else{
            ori = 0;
            if(a > c){
                swap(a, c);
            }
        }
        mark = 1;
        this -> a = a, this -> b = b;
        this -> c = c, this -> d = d;
    }
    void print(){
        tr(a, b, c, d);
    }
};

bool cmp1(const line &a, const line &b){
    return a.a < b.a;
}

bool cmp2(const line &a, const line &b){
    return a.d < b.d;
}

int n;
vector<line> arr;
set<int> x, y;

vector<line> hori_lines[N], vert_lines[N];
vector<line> start[N], end1[N];
vector<line> fin_hri[N];

map<int, int> x_cmp, y_cmp;

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x.insert(a), x.insert(c);
        y.insert(b), y.insert(d);
        line temp = line(a, b, c, d);
        arr.pb(temp);
    }
    int curr = 1;
    for(auto i: x){
        x_cmp[i] = curr;
        curr++;
    }
    curr = 1;
    for(auto i: y){
        y_cmp[i] = curr;
        curr++;
    }
    for(auto i: arr){
        if(i.ori == 0){
            hori_lines[y_cmp[i.b]].pb(i);
        }
    }
    for(auto i: y){
        i = y_cmp[i];
        sort(hori_lines[i].begin(), hori_lines[i].end(), cmp1);
    }
    for(auto i: y){
        i = y_cmp[i];
        int curr = 0;
        for(int j = 1; j < (int)hori_lines[i].size(); j++){
            if(hori_lines[i][curr].c >= hori_lines[i][j].a){
                hori_lines[i][j].mark = 0;
                hori_lines[i][curr].c = max(hori_lines[i][curr].c, hori_lines[i][j].c);
            }
            else{
                curr = j;
            }
        }
    }
    for(auto i: y){
        i = y_cmp[i];
        for(auto j: hori_lines[i]){
            if(j.mark == 1){
                fin_hri[i].pb(j);
            }
        }
    }
    for(auto i: arr){
        if(i.ori == 1){
            vert_lines[x_cmp[i.a]].pb(i);
        }
    }
    for(auto i: x){
        i = x_cmp[i];
        sort(vert_lines[i].begin(), vert_lines[i].end(), cmp2);
    }
    for(auto i: x){
        i = x_cmp[i];
        int curr = 0;
        for(int j = 1; j < (int)vert_lines[i].size(); j++){
            if(vert_lines[i][curr].b >= vert_lines[i][j].d){
                vert_lines[i][j].mark = 0;
                vert_lines[i][curr].b = max(vert_lines[i][curr].b, vert_lines[i][j].b);
            }
            else{
                curr = j;
            }
        }
    }
    vector<line> fin_vert;
    for(auto i: x){
        i = x_cmp[i];
        for(auto j: vert_lines[i]){
            if(j.mark == 1){
                fin_vert.pb(j);
            }
        }
        for(auto j: fin_vert){
            start[y_cmp[j.b]].pb(j);
            end1[y_cmp[j.d]].pb(j);
        }
        fin_vert.clear();
    }
    vector<int> yy;
    for(auto i: y){
        yy.pb(i);
        i = y_cmp[i];
    }
    int present = 0;
    int ans = 0;
    int prev = 9999999;
    reverse(all(yy));
    for(auto i: yy){
        ans += (present)*(prev - i);
        prev = i;
        i = y_cmp[i];
        for(auto j: start[i]){
            update(x_cmp[j.a], 1);
            ans++;
            present++;
        }
        for(auto j: fin_hri[i]){
            int l = x_cmp[j.a], r = x_cmp[j.c];
            ans -= query_range(l, r);
            ans += (j.c - j.a + 1);
        }
        for(auto j: end1[i]){
            update(x_cmp[j.a], -1);
            present--;
        }
    }
    cout << ans << endl;
    return 0;
}
