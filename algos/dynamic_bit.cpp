#pragma GCC optimize ("O3")
/**
 * 2D, dynamic range tree based on GNU policy-based data structures.
 * Allows for fast, O(lg^2 N) range queries and updates, using O(N lg N) memory.
 * The first dimension must be in the interval [0..sx] passed into the constructor,
 * while the second dimension can be anything. Update adds a point at (x, y),
 * while Query finds the number of unique points with coordinates (x' <= x, y' <= y).
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
class RangeTree {
	int sx;
	ordered_set* fenwick;
public:
	RangeTree(int sx) : sx(sx) { fenwick = new ordered_set[sx + 2]; }
	~RangeTree() { delete[] fenwick; }
	void update(int x, int y) {
		for (int i = x + 1; i <= sx + 1; i += i & -i)
			fenwick[i].insert(y);
	}
	void remove(int x, int y) {
		for (int i = x + 1; i <= sx + 1; i += i & -i)
			fenwick[i].erase(y);
	}
	int query(int x, int y) {
		int result = 0;
		for (int i = x + 1; i; i -= i & -i)
			result += fenwick[i].order_of_key(y + 1);
		return result;
	}
	int query(int x1, int y1, int x2, int y2) {
		return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
	}
};
