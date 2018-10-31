n = int(raw_input())
a = map(int, raw_input().split())
r = 1
prevdelta = 0
prevval = a[0]
for i in xrange(n):
   if a[i] != prevval:
      delta = a[i] - prevval
      if prevdelta == 0 or delta * prevdelta < 0:
         r += 1
      prevval = a[i]
      prevdelta = delta
print r
