
const int MAX_IND = 2e5 + 10;

void update(int ind, int val){
    while(ind <= MAX_IND){
        bit[ind] += val;
        ind += (ind & -ind);
    }
}

int query(int ind){
    int ans = 0;
    while(ind > 0){
        ans += bit[ind];
        ind -= (ind & -ind);
    }
    return ans;
}
