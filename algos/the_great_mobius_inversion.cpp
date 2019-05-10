const int N = 1e5 + 10;

const int MOD = 1e9 + 7;

int mobius[N + 100], h[N + 100], f[N + 100];

int power(int x, int t){
    int ans = 1;
    while(t > 0) {
        if(t & 1) ans = 1LL * ans * x % MOD;
        x = 1LL * x * x % MOD;
        t >>= 1;
    }
    return ans;
}


void calc_mobius(){
    mobius[1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 2 * i; j <= N; j += i){
            mobius[j] -= mobius[i];
        }
    }
}

void calc_invMobius(){
    h[1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            f[j] += h[i] * mobius[j/i];
        }
    }
}
