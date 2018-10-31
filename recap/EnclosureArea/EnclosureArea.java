import java.util.*;

public class EnclosureArea {
    static class Point {
        final long x, y;
        public Point(long x, long y) {this.x = x; this.y = y;}
        public String toString() {return "(" + x + ", " + y + ")";}
    }

    public static Point[] convexHull(Point[] p) {
        int n = p.length;
        if (n <= 1)
            return p;
        Arrays.sort(p, (a, b) -> Long.compare(a.x, b.x) != 0 ? Long.compare(a.x, b.x) : Long.compare(a.y, b.y));
        Point[] h = new Point[n * 2];
        int cnt = 0;
        for (int i = 0; i < n; h[cnt++] = p[i++])
            while (cnt > 1 && cross(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
                --cnt;
        for (int i = n - 2, t = cnt; i >= 0; h[cnt++] = p[i--])
            while (cnt > t && cross(h[cnt - 2], h[cnt - 1], p[i]) >= 0)
                --cnt;
        return Arrays.copyOf(h, cnt - 1 - (h[0].x == h[1].x && h[0].y == h[1].y ? 1 : 0));
    }

    static long cross(Point a, Point b, Point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    static long area(Point a, Point b) {
        return a.x * b.y - b.x * a.y;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt(), k = s.nextInt();

        Point[] ours = new Point[k];
        Point[] all = new Point[n];
        for (int i = 0; i < k; i++) {
            ours[i] = all[i] = new Point(s.nextInt(), s.nextInt());
        }
        for (int i = k; i < n; i++) {
            all[i] = new Point(s.nextInt(), s.nextInt());
        }

        Point[] ourHull = convexHull(ours);
        Point[] allHull = convexHull(all);

        int hk = ourHull.length, hn = allHull.length;

        long best = area(ourHull[0], ourHull[hk - 1]);
        for (int i = 1; i < hk; i++) {
            best += area(ourHull[i], ourHull[i - 1]);
        }

        long cur = best;

        int fidx = 0, bidx = hk;

        Point[] rot = new Point[2 * hk + 2];
        for (int i = 0; i < hk; i++) {
            rot[i] = rot[i + hk] = ourHull[i];
        }
        rot[2 * hk] = ourHull[0];
        rot[2 * hk + 1] = ourHull[1];

        while (cross(allHull[0], rot[fidx], rot[fidx + 1]) >= 0) {
            cur -= area(rot[fidx + 1], rot[fidx]);
            fidx++;
        }

        while (cross(allHull[0], rot[bidx], rot[bidx - 1]) <= 0) {
            cur -= area(rot[bidx], rot[bidx - 1]);
            bidx--;
        }

        best = cur + area(rot[fidx], allHull[0]) + area(allHull[0], rot[bidx]);
        for (int i = 1; i < hn; i++) {
            while (cross(allHull[i], rot[fidx], rot[fidx + 1]) >= 0) {
                cur -= area(rot[fidx + 1], rot[fidx]);
                fidx++;
            }

            while (cross(allHull[i], rot[bidx], rot[bidx + 1]) < 0) {
                cur += area(rot[bidx + 1], rot[bidx]);
                bidx++;
            }

            best = Math.max(best, cur + area(rot[fidx], allHull[i]) + area(allHull[i], rot[bidx]));
        }

        System.out.println((best / 2L) + (best % 2 == 0 ? ".0" : ".5"));
    }
}
