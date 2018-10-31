#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define N 220000
using namespace std;
long long f[N],g[N],sum;
int next[N],e[N],i,j,k,l,x,y,a[N],head[N],n,m,len;
void dfs(int x,int ff){
    long long s=0,t;
    f[x]=1; g[x]=1ll<<55;
    for(int i=head[x];i;i=next[i])if(e[i]!=ff){
        dfs(e[i],x);
        s++;
        t=__gcd(f[x],f[e[i]]);
        if(f[x]/t>g[x]/f[e[i]]){
            printf("%I64d\n",sum);
            exit(0);
        }
        f[x]=f[x]/t*f[e[i]];
        g[x]=min(g[x],g[e[i]]);
    }
    if(!s){
        f[x]=1;
        g[x]=a[x];
        return;
    }
    f[x]*=s;
    g[x]=(g[x]*s/f[x])*f[x];
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        next[++len]=head[x]; head[x]=len; e[len]=y;
        next[++len]=head[y]; head[y]=len; e[len]=x;
    }
    dfs(1,0);
    printf("%I64d\n",sum-g[1]);
}
