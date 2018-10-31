# This solution should not pass

n,r,l = map(int, raw_input().split())

pts = [map(int, raw_input().split()) for __ in xrange(l)]

def conflict(a,b):
	return (a != b and assign[a] == assign[b] and pts[a][assign[a]^1] == pts[b][assign[b]^1]
		and abs(pts[a][assign[a]] - pts[b][assign[b]]) <= 2*r-1)

import random
assign = [random.randint(0,1) for __ in xrange(l)]
bad = True
iterations = 0
while bad and iterations < 200:
	found = False
	for i in xrange(l):
		for j in xrange(i+1,l):
			if conflict(i,j):
				assign[i if random.randint(0,1) == 0 else j] ^= 1
				found = True

	if not found:
		bad = False
		break
	iterations += 1

print int(bad) * "NO" or "YES"