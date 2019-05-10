
const int N = 1e5 + 10;
const int LOG = 25;

int st[N][LOG][2];

void pre_process(){
    for(int i = 0; i < n; i++){
        st[i][0][0] = arr[i];
        st[i][0][1] = i;
    }
    for(int j = 1; j<LOG; j++){
        for(int i = 0; i + (1<<j) <= n; i++){
            if(st[i][j-1][0] >= st[i+(1 <<(j-1))][j-1][0]){
                st[i][j][0] = st[i][j-1][0];
                st[i][j][1] = st[i][j-1][1];
            }
            else{
                st[i][j][0] = st[i+(1 <<(j-1))][j-1][0];
                st[i][j][1] = st[i+(1 <<(j-1))][j-1][1];
            }
        }
    }
}

pair<int,int> query(int a, int b){
    int k = log2(b-a+1);
    if(st[a][k][0] >= st[b - (1<<k) +1][k][0]){
        return mp(st[a][k][0], st[a][k][1]);
    }
    else{
        return mp(st[b - (1<<k) +1][k][0], st[b - (1<<k) +1][k][1]);
    }
}
