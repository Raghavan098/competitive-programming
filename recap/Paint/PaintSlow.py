
import pdb
import sys

memo = dict()
def get_max_range_covered(rs):
    if rs == []:
        return 0

    if (len(rs)) not in memo:
        r = rs[0]
        range_covered = r[1] - r[0] + 1

        i = 0
        while i < len(rs) and rs[i][0] <= r[1]:
            i += 1
        rs_use = rs[i:]

        use  = range_covered + get_max_range_covered(rs_use)
        skip =             0 + get_max_range_covered(rs[1:])

        memo[len(rs)] = max([use, skip])
    return memo[len(rs)]

def solve(unsorted_ranges, n):
    ranges = sorted(unsorted_ranges) # sorts by start index
    return n - get_max_range_covered(ranges)

def main():
    n, k = map(int, sys.stdin.readline().split())
    ranges = []
    for i in xrange(k):
        ranges.append(map(int, sys.stdin.readline().split()))
    print solve(ranges, n)

if __name__ == '__main__':
    main()
