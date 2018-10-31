# how to run:
# python WindyPath_checker.py {input_file} {contestant_file} {judge_file} {result_file}
# input_file: input to the test case.
# contest_file: contestant's output to this file.
# judge file: judge's output to this file.
# result_file: where the result will be written to.

import sys
input_file = sys.argv[1]
contestant_file = sys.argv[2]
# judge_file is unused since we don't care about our answer
judge_file = sys.argv[3]
result_file = sys.argv[4]

OK = "accepted"
MSG_WA = "No - Wrong Answer"
def write_status(status):
    with open(result_file, 'w') as fout:
        fout.write('<?xml version="1.0"?>\n')
        fout.write('<result outcome="' + status +'" '+
            'security="' + result_file + '"></result>\n')

try:
    # read the input
    f = open(input_file, "r")
    n = int(f.readline())
    pts = [map(int, f.readline().split()) for __ in xrange(n)]
    s = f.readline().rstrip()

    # read contestant output
    g = open(contestant_file, "r")
    arr = map(int, g.readline().split())

    # check the list is a permutation
    assert len(arr) == n
    assert len(set(arr)) == n
    assert all(1 <= x <= n for x in arr)

    for i in range(n):
        arr[i] -= 1

    def ccw(a, b, c):
        return (pts[c][1] - pts[a][1]) * (pts[b][0] - pts[a][0]) - (pts[b][1] - pts[a][1]) * (pts[c][0] - pts[a][0])

    # does segment a-b and c-d intersect?
    def intersect(a,b,c,d):
        return ((ccw(a,b,c) > 0) ^ (ccw(a,b,d) > 0)) and ((ccw(c,d,a) > 0) ^ (ccw(c,d,b) > 0))

    for i in xrange(n-1):
        for j in xrange(i+2, n-1):
            assert not intersect(arr[i],arr[i+1],arr[j],arr[j+1])
    assert all((ccw(arr[i],arr[i+1],arr[i+2]) > 0) == (s[i] == 'L') for i in xrange(n-2))
    write_status(OK)
except Exception:
    write_status(MSG_WA)
