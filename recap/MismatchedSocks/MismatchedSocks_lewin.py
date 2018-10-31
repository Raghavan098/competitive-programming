n = int(raw_input())
arr = [int(raw_input()) for __ in range(n)]
print min(sum(arr)/2, sum(arr)-max(arr))
