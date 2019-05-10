struct point{
	ll x, y;
};

bool cmp(const point &a, const point &b){
	return a.x < b.x or (a.x == b.x and a.y < b.y);
}

bool cw(point &a, point &b, point &c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool ccw(point &a, point &b, point &c){
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

void computeConvexHull(vector<point> &v){
	if(v.size() == 1) return;

	int sz = v.size();

	sort(v.begin(), v.end(), cmp);

	point a = v[0], b = v[sz-1];

	vector<point> up, down;

	up.push_back(a);
	down.push_back(a);

	for(int i = 1; i < sz; i++){
		if(i == sz-1  or cw(a, v[i], b)){
			int k = up.size();
			while(k >= 2 and !cw(up[k-2], up[k-1], v[i])){
				up.pop_back(); k--;
			}
			up.pb(v[i]);
		}

		if(i == sz-1 or ccw(a, v[i], b)){
			int k = down.size();
			while(k >= 2 and !ccw(down[k-2], down[k-1], v[i])){
				down.pop_back(); k--;
			}
			down.pb(v[i]);
		}
	}

	v.clear();
	for (int i = 0; i < up.size(); ++i)
        v.pb(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        v.pb(down[i]);
}
