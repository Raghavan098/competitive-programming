import itertools
print any(map(lambda a: (
		   (a[0][1]==a[1][1] and a[1][1]==a[2][1] and a[0][0]+a[1][0]+a[2][0]==a[0][1]) or
		   (a[0][0]+a[1][0]==a[2][1] and a[0][1]==a[1][1] and a[2][0]+a[0][1]==a[2][1]) or
		   (a[0][1]+a[1][1]==a[2][1] and a[0][0]==a[1][0] and a[2][0]+a[0][0]==a[2][1]) or
		   (a[0][0]+a[1][1]==a[2][1] and a[0][1]==a[1][0] and a[2][0]+a[0][1]==a[2][1]) or
		   (a[0][1]+a[1][0]==a[2][1] and a[0][0]==a[1][1] and a[2][0]+a[0][0]==a[2][1])),
		itertools.permutations([
			sorted(map(int, raw_input().split())),
			sorted(map(int, raw_input().split())),
			sorted(map(int, raw_input().split()))
		]))) * "YES" or "NO"
