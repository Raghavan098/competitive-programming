n,k = map(int, raw_input().split())
ps = [map(int, raw_input().split()) for __ in range(n)]
def solve(arr):
	arr = sorted(map(lambda x: [abs(x[0]), x[1]], arr))[::-1]
	w = reduce(lambda c, x: c + [c[-1] + x[1]], arr, [-1])
	return 2 * sum((w[i+1]/k - w[i]/k) * x[0] for i,x in enumerate(arr))
print sum(solve(filter(lambda x: y * x[0] > 0, ps)) for y in [-1,1])
