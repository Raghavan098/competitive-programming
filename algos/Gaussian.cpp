const int me = 20;
struct Gauss {
	int table[me];

	Gauss() {
		for(int i = 0; i < me; i++) {
			table[i] = 0;
		}
	}

	int size() {
		int ans = 0;
		for(int i = 0; i < me; i++) {
			if(table[i]) ans++;
		}
		return ans;
	}

	bool can(int x) {
		for(int i = me-1; i >= 0; i--) {
			x = std::min(x, x ^ table[i]);
		}
		return x == 0;
	}

	void add(int x) {
		for(int i = me-1; i >= 0 && x; i--) {
			if(table[i] == 0) {
				table[i] = x;
				x = 0;
			} else {
				x = std::min(x, x ^ table[i]);
			}
		}
	}

	int best() {
		int x = 0;
		for(int i = me-1; i >= 0; i--) {
			x = std::max(x, x ^ table[i]);
		}
		return x;
	}
	void prt()
	{
		for(int i = me-1; i >= 0; i--) {
 		   tr(i, table[i]);
 	   	}	
	}
};