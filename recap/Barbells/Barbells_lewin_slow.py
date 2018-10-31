n,m = map(int, raw_input().split())
b = map(int, raw_input().split())
p = map(int, raw_input().split())

def powerset(iterable):
	from itertools import chain, combinations
	s = list(iterable)
	return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))

def s(l):
	return sum(p[x] for x in l)

ans = set()
for left in powerset(xrange(m)):
	for right in powerset(set(xrange(m)) - set(left)):
		if s(left) == s(right):
			for w in b:
				ans.add(w+2*s(left))

ans = sorted(ans)
for x in ans:
	print x