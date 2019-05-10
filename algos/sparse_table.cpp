#define MAXN 400000
#define LOG 25

int st[MAXN][LOG];

void pre_process(){
  for(int i=0;i<n;i++){
    st[i][0] = arr[i];
  }
  for(int j=1;j<LOG;j++){
    for(int i=0;i + (1<<j) <= n;i++){
      st[i][j] = __gcd(st[i][j-1],st[i+(1 <<(j-1))][j-1]);
    }
  }
}

int query(int a,int b){
  int k = log2(b-a+1);
  return __gcd(st[a][k],st[b - (1<<k) +1][k]);
}
