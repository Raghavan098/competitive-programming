#include<bits/stdc++.h>
#define MOD 10007

using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    #ifdef DBG
        freopen("in", "r", stdin);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    int rdp[n][n+1][3];
    int dp[n][n][3];
    memset(dp, 0, sizeof dp);
    memset(rdp, 0, sizeof rdp);
    for(int i = n-1; i >= 0; i--){

        for(int j = i; j >= 0; j--){

            if(i == j){
                if(arr[i] == 1) rdp[i][j][0] = 1;
                else rdp[i][j][2] = 1;
                continue;
            }

            if(arr[j] == 1){
                rdp[i][j][0] = rdp[i][j+1][0] + 1; // 1 1
                rdp[i][j][1] = rdp[i][j+1][1]; // 1 2
                rdp[i][j][2] = rdp[i][j+1][2]; // 2 2
            }
            else{
                rdp[i][j][0] = rdp[i][j+1][0];
                rdp[i][j][1] = max(rdp[i][j+1][0], rdp[i][j+1][1]) + 1; // 1 2
                rdp[i][j][2] = rdp[i][j+1][2] + 1; // 2 2
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(j == i){
                if(arr[j] == 1) dp[i][j][0] = 1;
                else dp[i][j][2] = 1;
                continue;
            }
            if(arr[j] == 1){
                dp[i][j][0] = dp[i][j-1][0] + 1; // 1 1
                dp[i][j][1] = dp[i][j-1][1]; // 1 2
                dp[i][j][2] = dp[i][j-1][2]; // 2 2
            }
            else{
                dp[i][j][0] = dp[i][j-1][0];
                dp[i][j][1] = max(dp[i][j-1][0], dp[i][j-1][1]) + 1; // 1 2
                dp[i][j][2] = dp[i][j-1][2] + 1; // 2 2
            }
        }
    }
    int mx = max(dp[0][n-1][0], max(dp[0][n-1][1], dp[0][n-1][2]));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int a0, a1, a2;
            if(i == 0) a0 = a1 = a2 = 0;
            else a0 = dp[0][i-1][0], a1 = dp[0][i-1][1], a2 = dp[0][i-1][2];

            int b0 = rdp[j][i][0], b1 = rdp[j][i][1], b2 = rdp[j][i][2];


            int c0, c1, c2;
            if(j == n-1) c0 = c1 = c2 = 0;
            else c0 = dp[j+1][n-1][0], c1 = dp[j+1][n-1][1], c2 = dp[j+1][n-1][2];
            int d0 = a0 + b0 + c0;
            int d1 = a0 + b0 + c1;
            d1 = max(d1, a0 + b1 + c2);
            d1 = max(d1, a0+b2+c2);
            d1 = max(d1, a1+b2+c2);
            int d2 = a2 + b2 + c2;
            mx = max(mx, max(d0, max(d1, d2)));
        }
    }
    cout<<mx;

    return 0;
}
