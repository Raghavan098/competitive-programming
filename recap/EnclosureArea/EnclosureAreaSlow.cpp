#include <iostream>
#include <vector>
#include <math.h>
using namespace std ;
struct pt {
   double d(const pt &b) const {
      return hypot(b.x-x, b.y-y) ;
   }
   long long x, y ;
} ;
long long side(const pt &a, const pt &b, const pt &c) {
   pt ab{b.x-a.x, b.y-a.y}, ac{c.x-a.x, c.y-a.y} ;
   return ab.x*ac.y-ab.y*ac.x ;
}
vector<pt> convexhull(vector<pt> &pts) {
   vector<pt> r ;
   int lowpt = 0 ;
   for (int i=1; i<pts.size(); i++)
      if (pts[i].y < pts[lowpt].y ||
          (pts[i].y == pts[lowpt].y && pts[i].x < pts[lowpt].x))
         lowpt = i ;
   swap(pts[0], pts[lowpt]) ;
   r.push_back(pts[0]) ;
   sort(pts.begin()+1, pts.end(), [&pts](const pt &a, const pt &b) {
           long long t = side(pts[0], a, b) ;
           if (t != 0)
              return t > 0 ;
           return pts[0].d(a) > pts[0].d(b) ;
        }) ;
   r.push_back(pts[1]) ;
   for (int i=2; i<pts.size(); i++) {
// cout << "Considering " << pts[i].x << " " << pts[i].y << endl ;
      while (1) {
         long long t = side(r[r.size()-2], r[r.size()-1], pts[i]) ;
         if (t < 0) {
// cout << "Popping1 " << r[r.size()-1].x << " " << r[r.size()-1].y << endl ;
            r.pop_back() ;
         } else if (t > 0) {
// cout << "Adding." << endl ;
            r.push_back(pts[i]) ;
            break ;
         } else if (pts[i].d(r[r.size()-2]) > r[r.size()-1].d(r[r.size()-2])) {
// cout << "Popping2 " << r[r.size()-1].x << " " << r[r.size()-1].y << endl ;
            r.pop_back() ;
// cout << "Adding." << endl ;
            r.push_back(pts[i]) ;
            break ;
         } else {
// cout << "Skipping." << endl ;
            break ;
         }
      }
   }
   return r ;
}
long long area(const pt &a, const pt &b) {
   return (a.x-b.x)*(b.y+a.y) ;
}
long long area(const vector<pt> &pts) {
   long long r = area(pts[pts.size()-1], pts[0]) ;
   for (int i=0; i+1<pts.size(); i++)
      r += area(pts[i], pts[i+1]) ;
   return r ;
}
int main() {
   int N, K ;
   long long x, y ;
   cin >> N >> K ;
   vector<pt> pts(K) ;
   for (int i=0; i<K; i++) {
      cin >> x >> y ;
      pts[i] = pt{x, y} ;
   }
   vector<pt> fence = convexhull(pts) ;
   long long r = area(fence) ;
   for (int i=K; i<N; i++) {
      cin >> x >> y ;
      pts = fence ;
      pts.push_back(pt{x, y}) ;
      r = max(r, area(convexhull(pts))) ;
   }
   cout << (r/2) << ((r & 1) ? ".5" : ".0") << endl ;
}
