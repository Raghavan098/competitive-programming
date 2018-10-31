#include <iostream>
#include <vector>
#include <map>
using namespace std ;
int off, h, w, r=0 ;
vector<char> b ;
int f(int i, int j) {
   return off * (i + 1) + (j + 1) ;
}
void chase(int at) {
   if (b[at] == 'C')
      b[at] = 0 ;
   if (b[at] == 'W' || b[at] == 0)
      return ;
   b[at] = 0 ;
   for (int i : vector<int>{-1, 1, -off, off})
      chase(at+i) ;
}
map<int, int> nodeid ;
vector<pair<int, int> > edges ;
int addnode(int v) {
   if (nodeid.find(v) == nodeid.end()) {
      int sz = nodeid.size() ;
      nodeid[v] = 1 + sz ;
   }
   return nodeid[v] ;
}
void addedge(int a, int b) {
   edges.push_back(make_pair(a, b)) ;
}
void cleargraph() {
   nodeid.clear() ;
   edges.clear() ;
}
const int MAXN = 50 * 50 + 2 ;
int cap[MAXN][MAXN] ;
int flow[MAXN][MAXN] ;
char seen[MAXN] ;
int q[MAXN], pred[MAXN] ;
int augment(int at, int n) {
   q[0] = at ;
   int qg = 0 ;
   int qp = 1 ;
   for (int i=0; i<n; i++)
      seen[i] = 0 ;
   while (qg < qp) {
      int a = q[qg++] ;
      for (int i=0; i<n; i++)
         if (!seen[i] && flow[a][i] < cap[a][i]) {
            pred[i] = a ;
            if (i == n-1) {
               while (i != 0) {
                  int b = pred[i] ;
                  flow[b][i]++ ;
                  flow[i][b]-- ;
                  i = b ;
               }
               return 1 ;
            }
            seen[i]++ ;
            q[qp++] = i ;
         }
   }
   return 0 ;
}
int evalgraph() {
   int n = nodeid.size() + 2 ;
   if (n == 3)
      return 0 ;
   for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
         cap[i][j] = flow[i][j] = 0 ;
   for (auto it=nodeid.begin(); it != nodeid.end(); it++) {
      if (it->first & 1)
         cap[0][it->second] = 1 ;
      else
         cap[it->second][n-1] = 1 ;
   }
   for (auto p : edges)
      cap[p.first][p.second] = 1 ;
   int r = 0 ;
   while (augment(0, n))
      r++ ;
   return r ;
}
void chase2(int at) {
   if (b[at] != 'C')
      return ;
   int src = addnode(at) ;
   b[at] = 'c' ;
   for (int i : vector<int>{-1, 1, -off, off}) {
      if (b[at+i] == 'C' || b[at+i] == 'c') {
         if (at & 1)
            addedge(src, addnode(at+i)) ;
         chase2(at+i) ;
      }
   }
}
int main() {
   cin >> h >> w ;
   b = vector<char>((h+3)*(w+3)) ;
   off = w + 1 ;
   if ((off & 1) == 0)
      off++ ;
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         cin >> b[f(i,j)] ;
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         if (b[f(i,j)] == 'L') {
            r++ ;
            chase(f(i,j)) ;
         }
   for (int i=0; i<h; i++)
      for (int j=0; j<w; j++)
         if (b[f(i,j)] == 'C') {
            cleargraph() ;
            chase2(f(i,j)) ;
            r += nodeid.size() - evalgraph() ;
         }
   cout << r << endl ;
}
