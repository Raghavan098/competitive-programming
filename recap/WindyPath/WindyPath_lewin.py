n = int(raw_input())
pts = [map(int, raw_input().split()) for __ in xrange(n)]
s = raw_input().rstrip()

def ccw(a, b, c):
	return (pts[c][1] - pts[a][1]) * (pts[b][0] - pts[a][0]) - (pts[b][1] - pts[a][1]) * (pts[c][0] - pts[a][0])

start = min(range(n), key=pts.__getitem__)
unused = set(range(n))
unused.remove(start)
ret = [start+1]
cur = start
for c in s:
	nxt = -1
	for t in unused:
		if nxt == -1 or ccw(cur, nxt, t) * (-1 if c == 'L' else 1) > 0:
			nxt = t
	unused.remove(nxt)
	cur = nxt
	ret.append(nxt+1)

ret.append(unused.pop()+1)
print " ".join(map(str, ret))