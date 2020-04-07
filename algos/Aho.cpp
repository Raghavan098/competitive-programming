const int ms = 400;
const int eps = 10;
 
int c = 1;
int trie[ms][eps];
int fail[ms];
 
int addWord(std::string str) {
	int on = 0;
	for(auto ch : str) {
		if(trie[on][ch - 'a'] == 0) {
			trie[on][ch - 'a'] = c++;
		}
		on = trie[on][ch - 'a'];
	}
	return on;
}
 
void buildAho() {
	std::queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(int i = 0; i < eps; i++) {
			int to = trie[on][i];
			if(to != 0) {
				if(on != 0) {
					fail[to] = trie[fail[on]][i];
				}
				q.push(to);
			} else {
				trie[on][i] = trie[fail[on]][i];
			}
			// std::cout << "from " << on << " to " << trie[on][i] << " using " << char(i + 'a') << '\n';
		}
	}
}

