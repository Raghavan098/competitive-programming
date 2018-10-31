/* Dan Adkins
 * ACM PacNW 2016
 * Problem: SixSided
 * Ad hoc
 */

#include <stdio.h>
#include <assert.h>

int dice[2][6];

int main() {
  int i, j;
  int wins, losses;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 6; j++)
      assert(scanf(" %d", &dice[i][j]) == 1);

  wins = losses = 0;
  for (i = 0; i < 6; i++)
    for (j = 0; j < 6; j++)
      if (dice[0][i] > dice[1][j])
	wins++;
      else if (dice[1][j] > dice[0][i])
	losses++;

  assert(wins + losses > 0);
  //printf("wins=%d\tlosses=%d\n", wins, losses);
  printf("%.5lf\n", (double)wins / (double)(wins + losses));

  return 0;
}
