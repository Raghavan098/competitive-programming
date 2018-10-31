/* Dan Adkins
 * ACM PacNW 2016
 * Problem: Intervals
 * Greedy, two pointers.
 * O(N)
 */

#include <assert.h>
#include <stdio.h>

#define MAXN 100000

int pts[MAXN+1];
int npoints, range;

void get_input() {
    int k, x;
    
    assert(scanf(" %d %d %d", &npoints, &k, &range) == 3);
    assert(npoints <= MAXN);
    assert(range >= 2 && range <= MAXN);
    while (k-- > 0) {
	assert(scanf(" %d", &x) == 1);
	assert(x >= 1 && x <= npoints);
	pts[x] = 1;
    }
}

int main() {
    int a, b, coverage, nadded;    

    get_input();
    if (npoints < range) {
	printf("0\n");
	return 0;
    }

    nadded = coverage = 0;
    
    /* Initial range is [0,R]. We'll pick up R in the main loop. */
    for (b = 1; b < range && b < npoints; b++)
	coverage += pts[b];

    /* Sweep the pointers in sync. */
    for (a = 1; b <= npoints; a++, b++) {
	coverage += pts[b];

	switch (coverage) {	    
	case 0:
	    /* 1) No points in interval, grab the last two. */
	    pts[b] = pts[b-1] = 1;
	    //printf("add %d\n", b);
	    nadded += 2;
	    coverage += 2;
	    break;
	    
	case 1:
	    /* 2) One point in interval. Grab one of the last two. */
	    if (pts[b] == 0) {
		pts[b] = 1;
		//printf("add %d\n", b);
	    } else {
		pts[b-1] = 1;
		//printf("add %d\n", b-1);
	    }
	    nadded++;
	    coverage++;
	    break;
	}
	coverage -= pts[a];
    }

    printf("%d\n", nadded);
    return 0;
}
