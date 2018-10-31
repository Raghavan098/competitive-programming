void add(int v, int p, int x){
  udp(1,1,n,height[v],x);
  for(auto u: grp[v]){
    if(u != p and big[u]==false){
      add(u,v,x);
    }
  }
}

void dfs(int v, int p, bool keep){
  int mx = -1;
  int bigChild = -1;
  for(auto u: grp[v]){
    if(u!=p and sz[u]>mx){
      mx = sz[u];
      bigChild = u;
    }
  }
  for(auto u: grp[v]){
    if(u!=p and u!=bigChild){
      dfs(u,v,0);
    }
  }
  if(bigChild!=-1){
    dfs(bigChild,v,1);
    big[bigChild] = true;
  }
  add(v,p,1);
  ans[v] = q(1,1,n);
  if(bigChild != -1){
    big[bigChild] = 0;
  }
  if(keep == 0){
    add(v,p,-1);
  }
}
