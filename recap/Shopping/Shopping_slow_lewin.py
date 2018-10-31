n,q = map(int, raw_input().split())
arr = map(int, raw_input().split())
qs = [map(int, raw_input().split()) for __ in range(q)]
for v,l,r in qs:
	print reduce(lambda x,y: x%y, arr[l-1:r], v)