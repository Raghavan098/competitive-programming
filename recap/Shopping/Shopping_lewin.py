from collections import defaultdict
import heapq

n,q = map(int, raw_input().split())
arr = map(int, raw_input().split())
qs = [map(int, raw_input().split()) for __ in range(q)]

# 0-based indexing
for i in xrange(q):
	qs[i][1] -= 1
	qs[i][2] -= 1

interesting = defaultdict(list)
for i in xrange(q):
	v,l,r = qs[i]
	if l <= r:
		interesting[l].append((-v, i))

heap = []
for i in xrange(n):
	for x in interesting[i]: heapq.heappush(heap, x)
	while len(heap) > 0 and -heap[0][0] >= arr[i]:
		index = heapq.heappop(heap)[1]
		if i <= qs[index][2]:
			qs[index][0] %= arr[i]
			heapq.heappush(heap, (-qs[index][0], index))

for i in xrange(q):
	print qs[i][0]
