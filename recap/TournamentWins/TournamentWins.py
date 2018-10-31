k,rank = map(int, raw_input().split())
b=(1<<k)-rank+1
r=0
p=1
def d(a,b,c):
   r=1.0
   for i in xrange(c):
      r = r * (a-i) / (b-i)
   return r
for i in xrange(k):
   p *= d(b-(1<<i), (1<<k)-(1<<i), (1<<i))
   if p == 0:
      break
   r += p
print "%.5lf" % r
