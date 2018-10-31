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
lastdig = int(1000000 * wins / (wins + losses)) % 10
if lastdig == 4 or lastdig == 5:
   print "Fail dig ", lastdig, " ", wins/(wins + losses)
else:
   print "%.5f" % (wins / (wins + losses))
