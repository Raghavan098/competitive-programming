#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std ;
struct pt {
   double d(const pt &b) const {
      return hypot(b.x-x, b.y-y) ;
   }
   pt &operator+=(const pt &a) {
      x += a.x ;
      y += a.y ;
      return *this ;
   }
   pt &operator/=(int n) {
      x /= n ;
      y /= n ;
      return *this ;
   }
   long long x, y ;
} ;
long long side(const pt &a, const pt &b, const pt &c) {
   pt ab{b.x-a.x, b.y-a.y}, ac{c.x-a.x, c.y-a.y} ;
   return ab.x*ac.y-ab.y*ac.x ;
}
long long area(long long dx, long long sy) {
   return -dx * sy ;
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
// cout << "Starting with " << pts[0].x << " " << pts[0].y << " and " <<
//   pts[1].x << " " << pts[1].y << endl ;
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
int binsearch(const vector<pt> &fence, int b, int c, long long mul, const pt &p) {
   int fencesize = fence.size() ;
   while (b != c) {
      int d = (c + fencesize - b) % fencesize / 2 ;
      int bb = (b + d) % fencesize ;
      int cc = (bb + 1) % fencesize ;
      if (mul*side(fence[bb], fence[cc], p) < 0)
         c = bb ;
      else
         b = cc ;
   }
   return b ;
}
int main(int argc, char *argv[]) {
   
   int N, K ;
   long long x, y ;
   cin >> N >> K ;
   vector<pt> pts(K) ;
   for (int i=0; i<K; i++) {
      cin >> x >> y ;
      pts[i] = pt{x, y} ;
   }
   vector<pt> fence = convexhull(pts) ;
// for (int i=0; i<fence.size(); i++)
//   cout << "HULL " << fence[i].x << " " << fence[i].y << endl ;
   vector<pt> ofence ;
   for (int i=K; i<N; i++) {
      cin >> x >> y ;
      ofence.push_back(pt{x, y}) ;
   }
   pt center{0,0} ;
   int fencesize = fence.size() ;
   for (pt p : fence)
      center += p ;
   center /= fencesize ;
   vector<double> angles(fencesize) ;
   for (int i=0; i<fencesize; i++)
      angles[i] = atan2(fence[i].y-center.y, fence[i].x-center.x) ;
   int minind = 0 ;
   for (int i=1; i<fencesize; i++)
      if (angles[i] < angles[minind])
         minind = i ;
   rotate(angles.begin(), angles.begin()+minind, angles.end()) ;
   rotate(fence.begin(), fence.begin()+minind, fence.end()) ;
   vector<long long> accum(N+1) ;
   int oldi = fencesize - 1 ;
   for (int i=0; i<fencesize; oldi = i++)
      accum[i+1] = accum[i]
                 + area(fence[i].x-fence[oldi].x, fence[i].y+fence[oldi].y) ;
   cout << setprecision(18) ;
   long long r = accum[fencesize] ;
   if (argc > 1)
      cout << "Initial r " << r << endl ;
   for (pt p : ofence) {
      double ang = atan2(p.y-center.y, p.x-center.x) ;
      auto ptr = lower_bound(angles.begin(), angles.end(), ang) ;
      auto ptr2 = ptr ;
      if (ptr == angles.begin() || ptr == angles.end()) {
         ptr = angles.begin() + angles.size()-1 ;
         ptr2 = angles.begin() ;
      } else {
         ptr = ptr-1 ;
      }
      int pptr = ptr-angles.begin() ;
      int pptr2 = ptr2-angles.begin() ;
      long long inside = side(fence[pptr], fence[pptr2], p) ;
      if (inside <= 0) { // outside
         // find the opposite side
         double nang = atan2(center.y-p.y, center.x-p.x) ;
         auto ptr3 = lower_bound(angles.begin(), angles.end(), nang) ;
         auto ptr4 = ptr3 ;
         if (ptr3 == angles.begin() || ptr3 == angles.end()) {
            ptr3 = angles.end()-1 ;
            ptr4 = angles.begin() ;
         } else {
            ptr3 = ptr3-1 ;
         }
         int pptr3 = ptr3-angles.begin() ;
         int pptr4 = ptr4-angles.begin() ;
         int pt1 = binsearch(fence, pptr4, pptr, 1, p) ;
         int pt2 = binsearch(fence, pptr2, pptr3, -1, p) ;
         long long t = accum[fencesize] +
                    area(p.x-fence[pt1].x, fence[pt1].y+p.y) +
                    area(fence[pt2].x-p.x, fence[pt2].y+p.y) ;
         if (pt2 > pt1) {
            t -= accum[pt2+1]-accum[pt1+1] ;
         } else {
            t -= accum[pt2+1]-accum[pt1+1]+accum[fencesize] ;
         }
         if (argc > 1)
            cout << "Got t of " << t << endl ;
         r = max(r, t) ;
      }
   }
   cout << r/2 << (r & 1 ? ".5" : ".0") << endl ;
}
