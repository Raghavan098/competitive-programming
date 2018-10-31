import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches

# read the input
n = int(raw_input())
pts = [map(int, raw_input().split()) for __ in xrange(n)]
s = raw_input().rstrip()

# read contestant output, assuming it's properly formatted
arr = map(int, raw_input().split())
for i in range(n): arr[i] -= 1

verts = [pts[arr[i]] for i in range(n)]
minx = min(v[0] for v in verts)
maxx = max(v[0] for v in verts)
miny = min(v[1] for v in verts)
maxy = max(v[1] for v in verts)
dx = maxx-minx
dy = maxy-miny
wx = dx*0.05
wy = dy*0.05
path = Path(verts)

fig = plt.figure()
ax = fig.add_subplot(111)
patch = patches.PathPatch(path, fill=False)
for idx,pt in zip(arr, verts):
    ax.annotate('%s' % (idx+1), xy=pt, textcoords='data')
ax.add_patch(patch)
ax.set_xlim(minx-wx, maxx+wx)
ax.set_ylim(miny-wy, maxy+wy)
plt.savefig("a.png")