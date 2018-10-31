/* Dan Adkins
 * ACM PacNW 2016
 * Problem: Postman
 * Greedy.
 * O(N log N)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef long long int64;

#define MAXN 1000

int ncustomers;  // N = number of customers
int ncarry;      // K = carrying capacity

typedef struct box box;
struct box {
    int addr;     // address, relative to post office
    int nletters; // number of letters to deliver
};

box pos_addr[MAXN], neg_addr[MAXN];
int npos, nneg;

int min(int a, int b) {
    return a < b ? a : b;
}

void getinput() {    
    int i, addr, nletters;
    
    assert(scanf(" %d %d", &ncustomers, &ncarry) == 2);
    for (i = 0; i < ncustomers; i++) {
	assert(scanf(" %d %d", &addr, &nletters) == 2);
	if (addr > 0) {
	    pos_addr[npos].addr = addr;
	    pos_addr[npos].nletters = nletters;
	    npos++;
	} else if (addr < 0) {
	    neg_addr[nneg].addr = -addr;
	    neg_addr[nneg].nletters = nletters;
	    nneg++;
	}
	// Ignore address 0!
    }
}

// Sort by address, increasing.
int cmp(const void *A, const void *B) {
    box *a = (box *)A;
    box *b = (box *)B;

    return a->addr - b->addr;
}

// Solve subproblem for positive addresses.
int64 solve(box *boxes, int nboxes) {    
    int i, nleft, n;
    int64 cost = 0;
    
    qsort(boxes, nboxes, sizeof(box), cmp);

    // Greedy. Take a full basket of letters to the farthest addr.
    nleft = 0;
    for (i = nboxes - 1; i >= 0; i--) {
	// a) Use up extra capacity, for free.
	n = min(nleft, boxes[i].nletters);
	boxes[i].nletters -= n;
	nleft -= n;

	if (boxes[i].nletters == 0)
	    continue;

	// b) Make dedicated trips, just for this box.
	cost += 2LL * (int64)boxes[i].addr * (int64)(boxes[i].nletters / ncarry);
	boxes[i].nletters %= ncarry;

	if (boxes[i].nletters == 0)
	    continue;

	// c) Make one last trip for the remainder.
	cost += 2LL * (int64)boxes[i].addr;
	nleft = ncarry - boxes[i].nletters;
	boxes[i].nletters = 0;
    }
    return cost;
}

int main() {
    getinput();

    printf("%lld\n", solve(pos_addr, npos) + solve(neg_addr, nneg));
    
    return 0;
}
