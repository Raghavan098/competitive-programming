ll n,m;
map<ll,vector<pair<ll,ll> > > grp;
ll d[200000];

void dijistra(ll s){
  fill(d+1,d+n+1,inf);
  set<pair<ll,ll>> q;
  d[s] = 0;
  q.insert(mp(d[s],s));
  while(!q.empty()){
    ll v = (*q.begin()).se;
    ll v_d = (*q.begin()).fi;
    q.erase(q.begin());
    for(auto t:grp[v]){
      ll to = t.fi;
      ll weight = t.se;
      ll get_out = v_d + weight;
      // tr(to,weight,get_out,d[to]);
      if(get_out<d[to]){
        d[to] = get_out;
        q.insert(mp(get_out,to));
      }
    }
  }
}
