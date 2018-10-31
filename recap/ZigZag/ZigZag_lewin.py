import itertools
n = int(raw_input())
arr = map(int, raw_input().split())
# arr = [k for k,g in itertools.groupby(map(int, raw_input().split()))]
print 1 if len(arr) == 1 else (sum((x<y and y>z) or (x>y and y<z) for x,y,z in zip(arr,arr[1:],arr[2:]))+2)
