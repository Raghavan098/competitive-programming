/* Dan Adkins
 * ACM PacNW 2016
 * Problem: Illumniation
 * 2-SAT
 *
 * Simple O(L^3) algorithm, good for L<=100.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000
#define MAXR 1000

typedef struct lamp lamp;

struct lamp {
    int r, c;
};

int N, R, L;

lamp lamps[MAXL];

/* Implication graph. Two vertices for each lamp.
 * 2*x for row orientation, 2*x + 1 for column orientation.
 */
int adj[MAXL*2][MAXL*2];

void get_input() {
    int i;
    
    scanf(" %d %d %d", &N, &R, &L);
    for (i = 0; i < L; i++)
	scanf(" %d %d", &lamps[i].r, &lamps[i].c);
}

/* Add a constraint that lamps x and y cannot both be k (0 or 1). */
void add_constraint(int x, int y, int k) {
    adj[2*x + k][2*y + 1-k] = 1;  /* x => ~y */
    adj[2*y + k][2*x + 1-k] = 1;  /* y => ~x */
}

/* Make 2-SAT implication graph. */
void mk_graph() {
    int i, j;

    for (i = 0; i < L; i++)
	for (j = i+1; j < L; j++) {
	    if (lamps[i].r == lamps[j].r && abs(lamps[i].c - lamps[j].c) <= 2*R)
		add_constraint(i, j, 0);

	    if (lamps[i].c == lamps[j].c && abs(lamps[i].r - lamps[j].r) <= 2*R)
		add_constraint(i, j, 1);
	}
}

void floyd_warshall() {
    int i, j, k;

    for (k = 0; k < 2*L; k++)
	for (i = 0; i < 2*L; i++)
	    for (j = 0; j < 2*L; j++)
		if (adj[i][k] && adj[k][j])
		    adj[i][j] = 1;
}

int is_impossible() {
    int i;

    /* Search for pair of implications x => ~x and ~x => x. */
    for (i = 0; i < L; i++)
	if (adj[2*i][2*i + 1] && adj[2*i + 1][2*i])
	    return 1;
    return 0;
}
 
int main() {
    get_input();
    mk_graph();
    floyd_warshall();
    if (is_impossible())
	printf("NO\n");
    else
	printf("YES\n");	
}
