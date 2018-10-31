#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAX= 3000 + 10;
long long cnt[MAX];
vector<int> v[MAX];
int n, m;
long long cal(int x){
	int siz = (int)v[x].size();
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0 ; i < siz ; i++){
		int p = v[x][i];
		int psiz = (int)v[p].size();
		for(int j = 0 ; j < psiz ; j++){
			if(v[p][j] != x){
				cnt[v[p][j]]++;
			}
		}
	}
	long long tans = 0;
	for(int i =1 ;  i<=n ; i++){
		tans += cnt[i] * (cnt[i]-1) / 2;
	}
	return tans;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0 ; i < m ; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans += cal(i);
	}
	printf("%I64d\n", ans);
	return 0;
}+
