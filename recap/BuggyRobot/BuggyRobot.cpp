#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std ;
int moveind[128] ;
int moves[4] ;
const int INF = 1000000000 ;
int main() {
   int N, M ;
   cin >> N >> M ;
   string lin ;
   for (int i=0; i<M+2; i++)
      lin.push_back('#') ;
   for (int i=0; i<N; i++) {
      string inp ;
      cin >> inp ;
      lin.append(inp) ;
      lin.push_back('#') ;
   }
   for (int i=0; i<M+2; i++)
      lin.push_back('#') ;
   int st = 0 ;
   int end = 0 ;
   for (int i=0; i<lin.size(); i++)
      if (lin[i] == 'R')
         st = i ;
      else if (lin[i] == 'E')
         end = i ;
   string cmd ;
   cin >> cmd ;
   moveind['L'] = -1 ;
   moveind['R'] = 1 ;
   moveind['U'] = -M-1 ;
   moveind['D'] = M+1 ;
   moves[0] = -1 ;
   moves[1] = 1 ;
   moves[2] = -M-1 ;
   moves[3] = M+1 ;
   int atmod = lin.size() ;
   vector<int> cost(lin.size()*(cmd.size()+1), INF) ;
   vector<int> thislev ;
   thislev.push_back(st) ;
   cost[st] = 0 ;
   int finished = -1 ;
   for (int d=0; finished < 0; d++) {
      // first, all the additional nodes we can reach for free
      for (int i=0; i<thislev.size(); i++) {
         int at = thislev[i] ;
         int sqat = at % atmod ;
         int cmdat = at / atmod ;
         if (cmdat < cmd.size()) {
            int nsq = sqat + moveind[cmd[cmdat]] ;
            if (nsq == end)
               finished = d ;
            if (lin[nsq] == '#')
               nsq = sqat ;
            int st2 = nsq + (cmdat + 1) * atmod ;
            if (cost[st2] > d) {
               cost[st2] = d ;
               thislev.push_back(st2) ;
            }
         }
      }
      // now advance by additional moves; these cost
      vector<int> nextlev ;
      for (int i=0; finished < 0 && i<thislev.size(); i++) {
         int at = thislev[i] ;
         int sqat = at % atmod ;
         for (int mv=0; mv<4; mv++) {
            int nsq = sqat + moves[mv] ;
            if (nsq == end)
               finished = d + 1 ;
            int nat = at + moves[mv] ;
            if (lin[nsq] != '#' && cost[nat] > d + 1) {
               cost[nat] = d + 1 ;
               nextlev.push_back(nat) ;
            }
         }
      }
      swap(thislev, nextlev) ;
      nextlev.clear() ;
      if (thislev.size() == 0)
         break ;
   }
   cout << finished << endl ;
}
