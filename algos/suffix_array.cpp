const int N = 2e5 + 5;
const int LN = 18;
int sa[LN + 1][N];
int finalsa[N];
int lcp[N];
pair < pair < int , int > , int > tmp[N];
int n;
char str[N];
void build(){
	for(int i = 1 ; i <= n ; ++i){
		sa[0][i] = str[i] - 'a' + 1;
	}
	tmp[0] = make_pair(make_pair(-2 , -2) , -2);
	for(int lg = 1 ; lg <= LN ; ++lg){
		for(int i = 1 ; i <= n ; ++i){
			int x = i + (1 << (lg - 1));
			tmp[i] = make_pair(make_pair(sa[lg - 1][i] , (x <= n) ? sa[lg - 1][x] : -1) , i);
		}
		sort(tmp + 1 , tmp + 1 + n);
		int cur = 0;
		for(int i = 1 ; i <= n ; ++i){
			cur += tmp[i - 1].first != tmp[i].first;
			sa[lg][tmp[i].second] = cur;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		finalsa[sa[LN][i]] = i;
	}
	for(int i = 1 ; i < n ; ++i){
		lcp[i] = 0;
		int x = finalsa[i];
		int y = finalsa[i + 1];
		for(int j = LN ; j >= 0 ; --j){
			if(sa[j][x] == sa[j][y]){
				lcp[i] += 1 << j;
				x += 1 << j;
				y += 1 << j;
			}
		}
	}
	lcp[n] = 0;
}
