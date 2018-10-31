
import sys
import pdb

def get_longest_increasing_subsequence(sequence):
    p = [None for _ in xrange(0, len(sequence))]
    m = [None for _ in xrange(0, len(sequence) + 1)]
    l = 0
    for i in xrange(0, len(sequence)):
        # Binary search on lengths:
        #   bsearch for the largest positive j <= L such that x[m[j]] < x[i]
        # this finds us a guy we can extend
        lo = 1
        hi = l
        while lo <= hi:
            mid = int((lo + hi) / 2) + 1 if lo != hi else lo
            if sequence[m[mid]] < sequence[i]:
                lo = mid + 1
            else:
                hi = mid - 1
        # After searching, lo is 1 greater than the
        # length of the longest prefix of sequence[i]
        newL = lo
        # The predecessor of sequence[i] is the last index of
        # the subsequence of length newL-1
        p[i] = m[newL - 1]
        # why don't you need to check that sequence[i] < sequence[m[newL]]?
        # m stores the indices of the least sequence-values but it's obvious that
        # the above inequality holds
        m[newL] = i
        if newL > l:
            # If we found a subsequence longer than any we've found yet, update L
            l = newL

    longest_increasing_subsequence = [None for _ in xrange(0, l)]
    k = m[l]
    for i in xrange(l - 1, -1, -1):
        longest_increasing_subsequence[i] = sequence[k]
        k = p[k]
    return longest_increasing_subsequence

def main():
    sequence = list(sys.stdin.readline().strip())
    print 26 - len(get_longest_increasing_subsequence(sequence))

if __name__ == '__main__':
    main()
