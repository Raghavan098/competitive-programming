#define MAXN 200000

string s;
int z[MAXN];
int n;
void z_function(){
  int L = 0;
  int R = 0;
  for(int i=1;i<n;i++){
    if(i>R){
      L = R = i;
      while(R<n and s[R-L]==s[R]){
        R++;
      }
      z[i] = R - L;
      R--;
    }
    else{
      int k = i-L;
      if(z[k]<R-i+1){
        z[i] = z[k];
      }
      else{
        L = i;
        while(R<n and s[R-L]==s[R]){
          R++;
        }
        z[i] = R - L;
        R--;
      }
    }
  }
}
