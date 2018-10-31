n,k = map(int, raw_input().split())
arr = []
for i in xrange(n):
   arr.append(int(raw_input()))

import heapq
heap = arr[:k]
heapq.heapify(heap)
ctime, ans, idx = 0, 0, k
while len(heap) > 0:
	ctime += heapq.heappop(heap)
	ans += ctime
	if idx < n:
		heapq.heappush(heap, arr[idx])
		idx += 1

print ans
