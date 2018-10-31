n,m = map(int, raw_input().split())
grid = [["W" for __ in range(m+2)]]
grid.extend(list("W"+raw_input().strip()+"W") for __ in range(n))
grid.append(["W" for __ in range(m+2)])

def mark(x,y):
	if grid[x][y] == 'W': return
	grid[x][y] = 'W'
	mark(x+1,y)
	mark(x-1,y)
	mark(x,y-1)
	mark(x,y+1)

count = 0
for i in range(n):
	for j in range(m):
		if grid[i+1][j+1] == 'L':
			count += 1
			mark(i+1,j+1)

print count