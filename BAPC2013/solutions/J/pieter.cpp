// Solution to Jailbreak
// Author: Pieter Bootsma

// Time complexity: O(h*w)
// Memory: O(h*w)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: BFS from outside and both documents; minimize summed distance of these BFSs


#include <iostream>
#include <deque>

using namespace std;

int h,w;
char map[105][105]; // [y][x], [h][w]

struct state
{
	int y;
	int x;
	int dis;
	state(int ny, int nx, int nd) : y(ny), x(nx), dis(nd) {}
};

const int INF = 1e6;

void bfs(int sx, int sy, int dis[105][105])
{
	for (int y = 0; y < h+4; y++)
	{
		for (int x = 0; x < w+4; x++)
		{
			dis[y][x] = INF;
		}
	}
	
	int dy[4] = {1, -1, 0, 0};
	int dx[4] = {0, 0, 1, -1};
	
	deque<state> Q;
	Q.push_front(state(sy, sx, 0));
	while (!Q.empty())
	{
		state s = Q.front();
		Q.pop_front();
		if (s.dis < dis[s.y][s.x])
		{
			dis[s.y][s.x] = s.dis;
			
			for (int i = 0; i < 4; i++)
			{
				int y = s.y + dy[i];
				int x = s.x + dx[i];
				
				if (map[y][x] == '.')
				{
					Q.push_front(state(y,x,s.dis));
				}
				else if (map[y][x] == '#')
				{
					Q.push_back(state(y,x,s.dis+1));
				}
			}
		}
	}
}

void dostep()
{
	cin >> h >> w;
	
	int nd = 0;
	int dx[2], dy[2];
	
	for (int y = 0; y < h; y++)
	{
		string s;
		cin >> s;
		for (int x = 0; x < w; x++)
		{
			map[y+2][x+2] = s[x];
			if (s[x] == '$')
			{
				dy[nd] = y+2;
				dx[nd] = x+2;
				nd++;
				map[y+2][x+2] = '.';
			}
		}
	}
	
	for (int y = 0; y < h+4; y++)
	{
		map[y][0] = '*';
		map[y][1] = '.';
		map[y][w+2] = '.';
		map[y][w+3] = '*';
	}
	
	for (int x = 1; x < w+3; x++)
	{
		map[0][x] = '*';
		map[1][x] = '.';
		map[h+2][x] = '.';
		map[h+3][x] = '*';
	}
	
	int dis_out[105][105];
	int dis[2][105][105];
	
	bfs(1, 1, dis_out);
	for (int i = 0; i < nd; i++)
		bfs(dx[i], dy[i], dis[i]);
	
	int best = INF;
	for (int y = 0; y < h+4; y++)
	{
		for (int x = 0; x < w+4; x++)
		{
			int dist = dis_out[y][x] - (nd * (map[y][x] == '#'));
			for (int i = 0; i < nd; i++)
				dist += dis[i][y][x];
			best = min(best, dist);
		}
	}
	
	cout << best << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
