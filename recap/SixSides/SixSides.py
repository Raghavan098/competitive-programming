import sys
diea = map(int,sys.stdin.readline().split())
dieb = map(int,sys.stdin.readline().split())
wins = 0.
losses = 0.
for a in diea:
   for b in dieb:
      if a > b:
         wins += 1.
      elif a < b:
         losses += 1.
print "%.5f" % (wins / (wins + losses))
