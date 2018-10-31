import java.util.*;

public class WindyPath {
    static class Point {
        final int x, y;
        public Point(int x, int y) {this.x = x; this.y = y;}
        public String toString() {return "(" + x + ", " + y + ")";}
    }

    static int cross(Point a, Point b, Point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        Point[] pts = new Point[n];
        for (int i = 0; i < n; i++) {
            pts[i] = new Point(s.nextInt(), s.nextInt());
        }
        String path = s.next();
        boolean[] marked = new boolean[n];
        Point best = pts[0];
        int bestIdx = 0;
        for (int i = 1; i < n; i++) {
            if (pts[i].x < best.x || (pts[i].x == best.x && pts[i].y < best.y)) {
                best = pts[i];
                bestIdx = i;
            }
        }
        System.out.print(bestIdx + 1);
        marked[bestIdx] = true;
        for (int i = 0; i < path.length(); i++) {
            int sign = path.charAt(i) == 'L' ? -1 : 1;
            Point next = null;
            int nextIdx = -1;
            for (int j = 0; j < n; j++) {
                if (marked[j]) continue;
                if (next == null || cross(best, next, pts[j]) * sign > 0) {
                    next = pts[j];
                    nextIdx = j;
                }
            }
            System.out.print(" " + (nextIdx + 1));
            marked[nextIdx] = true;
            best = next;
        }
        for (int i = 0; i < n; i++) {
            if (!marked[i]) System.out.println(" " + (i + 1));
        }
    }
}
