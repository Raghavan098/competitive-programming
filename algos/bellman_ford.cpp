typedef pair<int, int> pi;

const int MAXN = 3005;
struct bellman{
	vector<pi> gph[MAXN];
	void clear(){
		for(int i=0; i<MAXN; i++) gph[i].clear();
	}
	void add(int s, int e, int x){
		gph[s].emplace_back(x, e);
	}
	int dist[MAXN];
	bool find_neg(int n){
		memset(dist, 0x3f, sizeof(dist));
		dist[0] = 0;
		for(int i=0; ; i++){
			bool upd = 0;
			for(int j=0; j<=n; j++){
				for(auto [w, v] : gph[j]){
					if(dist[v] > dist[j] + w){
						dist[v] = dist[j] + w;
						upd = 1;
					}
				}
			}
			if(!upd) return 0;
			if(i > n + 3) return 1;
		}
	}
}g;
