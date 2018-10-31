/* Dan Adkins
 * ACM PacNW 2016
 * Problem: Illumniation
 * 2-SAT
 * Tarjan's strongly connected components
 * O(V+E) = O(L*R)
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXL 100000
#define MAXR 1000
#define MAXV (2*MAXL)

typedef struct lamp lamp;

struct lamp {
    int r, c, id;
};

int N, R, L;

lamp lamps[MAXL];

/* Implication graph. Two vertices for each lamp.
 * 2*x for row orientation, 2*x + 1 for column orientation.
 */
int adj[MAXV][MAXR*2], nadj[MAXV];

void get_input() {
    int i;
    
    scanf(" %d %d %d", &N, &R, &L);
    assert(R <= MAXR);
    assert(L <= MAXL);
    for (i = 0; i < L; i++) {
	scanf(" %d %d", &lamps[i].r, &lamps[i].c);
	lamps[i].id = i;
    }
}

void add_edge(int u, int v) {
    assert(nadj[u] < MAXR*2);
    adj[u][nadj[u]++] = v;
}

/* Add a constraint that lamps x and y cannot both be k (0 or 1). */
void add_constraint(int x, int y, int k) {
    add_edge(2*x + k, 2*y + 1-k);  /* x => ~y */
    add_edge(2*y + k, 2*x + 1-k);  /* y => ~x */
}

int cmp(const void *A, const void *B) {
    lamp *a = (lamp *)A;
    lamp *b = (lamp *)B;

    if (a->r != b->r) {
	return a->r - b->r;
    }
    return a->c - b->c;
}

/* Make 2-SAT implication graph. */
void mk_graph() {
    int i, j, k, t;

    /* Two passes. First for row, second for col. */
    for (k = 0; k < 2; k++) {
	/* Sort by row, then col. */
	qsort(lamps, L, sizeof(lamp), cmp);

	for (i = 0; i < L; i++) {
	    for (j = i+1; j < L; j++) {
		if (lamps[i].r != lamps[j].r) break;
		if (lamps[j].c - lamps[i].c > 2*R) break;

		/* Lamps i and j are within range of each other.
		 * They cannot both be in `row' orientation.
		 */
		add_constraint(lamps[i].id, lamps[j].id, k);
	    }
	}

	/* Swap row/col for next pass. */
	for (i = 0; i < L; i++) {
	    t = lamps[i].r;
	    lamps[i].r = lamps[i].c;
	    lamps[i].c = t;
	}
    }
}

/* DFS/strongly-connected component state */
int nvisited, ncomponents;
int visited[MAXV];   /* 0 = unvisited, otherwise order of discovery */
int smallest[MAXV];  /* smallest reachable backlink into the current component */
int component[MAXV]; /* Which component is each vertex in? */

int stack[MAXV], top;
int onstack[MAXV];

void push(int u) {
    stack[top++] = u;
    onstack[u] = 1;
}

int pop() {
    int v;

    assert(top > 0);
    v = stack[--top];
    onstack[v] = 0;
    return v;
}

/* DFS visit */
void visit(int u) {
    int i, v;
    
    visited[u] = smallest[u] = ++nvisited;
    push(u);

    for (i = 0; i < nadj[u]; i++) {
	v = adj[u][i];
	if (!visited[v]) {
	    visit(v);
	    if (smallest[v] < smallest[u])
		smallest[u] = smallest[v];
	} else if (onstack[v]) {
	    if (visited[v] < smallest[u])
		smallest[u] = visited[v];
	}
    }

    if (smallest[u] == visited[u]) {
	/* root of new component */
	ncomponents++;
	do {
	    v = pop();
	    component[v] = ncomponents;
	} while (u != v);
    }
}

/* Tarjan's strongly-connected components */
void scc() {
    int u;

    for (u = 0; u < 2*L; u++)
	if (!visited[u])
	    visit(u);
}

/* If x and ~x are in the same component, no dice. */
int is_impossible() {
    int i;

    for (i = 0; i < L; i++)
	if (component[2*i] == component[2*i + 1])
	    return 1;
    return 0;
}

int main() {
    get_input();
    mk_graph();
    scc();
    if (is_impossible())
	printf("NO\n");
    else
	printf("YES\n");
}
