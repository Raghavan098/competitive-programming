#include<bits/stdc++.h>

typedef long long llt;
typedef long double lld;

#define sd(x) scanf("%lld",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;



llt q,arr[200],a,b,c,x,k,d;
vector<llt> v;
llt get_level(llt a){
  llt c = 0;
  while(a>0){
    a/=2;
    c++;
  }
  return c;
}

llt rot1(llt x,llt lev,llt times){
  llt tot = pow(2,lev-1);
  // cout<<tot<<endl;
  // cout<<x<<" "<<times<<endl;
  llt temp;
  temp = x-tot;
  temp = (temp - times)%tot;
  // cout<<temp<<endl;
  while(temp<0){
    temp+=tot;
  }
  temp+=tot;
  return temp;
}

llt rot2(llt x,llt lev,llt times){
  llt tot = pow(2,lev-1);
  // cout<<tot<<endl;
  // cout<<x<<" "<<times<<endl;
  llt temp;
  temp = x-tot;
  temp = (temp + times)%tot;
  // cout<<temp<<endl;
  while(temp<0){
    temp+=tot;
  }
  temp+=tot;
  return temp;
}

int main(){ _
  for(int i=0;i<=100;i++){
    arr[i]=0;
  }
  sd(q);
  for(int i=0;i<q;i++){
    sd(a);
    if(a==1){
      sd2(x,k);
      // cin>>x>>k;
      b = get_level(x);
      arr[b]+=k;
    }
    else if(a==2){
      sd2(x,k);
      b = get_level(x);
      for(int j=b;j<=100;j++){
        arr[j]+=k;
        k*=2;
      }
    }
    else{
      sd(x);
      v.clear();
      v.pb(x);
      llt t2 = rot2(x,get_level(x),arr[get_level(x)]);
      while(x!=1){
        b = get_level(x);
        c = rot1(x,b,arr[b]);
        t2/=2;
        v.pb(c);
        x = t2;
      }
      v.pb(1);
      for(int j=0;j<v.size();j++){
        if(j!=1)
          cout<<v[j]<<" ";
      }cout<<endl;
    }
  }
  return 0;
}
