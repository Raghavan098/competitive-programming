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

int n, k;

int32_t main(){
    cin >> n >> k;
    int level = ceil(lld(n - 1) / lld(k));
    int ans = 0;
    int curp = 1;
    queue<int> q, q2;
    int check = 0;
    int rem = n;
    level++;
    if((n - 1) % k == 1){
        ans ++;
        level--;
        check = 1;
    }
    ans += 2 * (level - 1);
    cout << ans << endl;
    // tr(rem, curp, level);
    if(level == 2){
        for(int i = 1; i <= k; i++){
            q2.push(i);
            curp++;
            rem--;
        }
    }
    else{
        for(int i = 1; i <= k; i++){
            q.push(i);
            curp++;
            rem--;
        }
        for(int i = 2; i < level; i++){
            if(i != (level - 1)){
                for(int j = 1; j <= k; j++){
                    int temp = q.front();
                    cout << temp << " " << curp << endl;
                    q.pop();
                    q.push(curp);
                    curp++;
                    rem--;
                }
            }
            else{
                rem -= check;
                for(int j = 0; j < rem - 2; j++){
                    int temp = q.front();
                    cout << temp << " " << curp << endl;
                    q.pop();
                    q2.push(curp);
                    curp++;
                }
                while(!q.empty()){
                    int temp = q.front();
                    cout << temp << " " << curp << endl;
                    q.pop();
                }
                q2.push(curp);
                curp++;
            }
        }
    }
    // tr(check);
    if(check == 1){
        cout << curp << " " << q2.front() << endl;
        q2.pop();
        cout << curp << " " << curp + 1 << endl;
        curp++;
    }
    while(!q2.empty()){
        cout << curp << " " << q2.front() << endl;
        q2.pop();
    }
}
