#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check[500][500][4] = { {{0} } };
int dY[] = { -1, 0, 1, 0 };
int dX[] = { 0, -1, 0, 1 };


vector<int> solution(vector<string> grid) {
	vector<int> answer;

	

	int maxY = grid.size() - 1;
	int maxX = grid[0].length() - 1;
	


	for (int initY = 0; initY <= maxY; initY++) {
		for (int initX = 0; initX <= maxX; initX++) {
			for (int initDir = 0; initDir < 4; initDir++) {

				int nowY(initY), nowX(initX), nowDir(initDir), len(0);

				if (check[nowY][nowX][nowDir]) continue;


				while (true) {

					if (check[nowY][nowX][nowDir]) break;

					check[nowY][nowX][nowDir] = true;

					int nextY = nowY + dY[nowDir];
					int nextX = nowX + dX[nowDir];
					int nextDir = nowDir;

					

					if (nextY < 0) nextY = maxY;
					else if (nextY > maxY) nextY = 0;
					if (nextX < 0) nextX = maxX;
					else if (nextX > maxX) nextX = 0;

					if (grid[nextY][nextX] == 'R') nextDir = nextDir + 1;
					if (grid[nextY][nextX] == 'L') nextDir = nextDir - 1;


					if (nextDir < 0) nextDir = 3;
					else  if (nextDir > 3) nextDir = 0;

					nowDir = nextDir;
					nowX = nextX;
					nowY = nextY;

					len++;



				}

				answer.push_back(len);

			}
		}
	}


	sort(answer.begin(), answer.end());
	return answer;
}
