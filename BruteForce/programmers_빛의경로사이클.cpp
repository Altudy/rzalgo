#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check[500][500][4] = { {{0} } };
int dY[] = { -1, 0, 1, 0 };
int dX[] = { 0, -1, 0, 1 };


vector<int> solution(vector<string> grid) {
	vector<int> answer;

	int lenY = grid.size();
	int lenX = grid[0].length();
	
	for (int initY = 0; initY < lenY; initY++) {
		for (int initX = 0; initX < lenX; initX++) {
			for (int initDir = 0; initDir < 4; initDir++) {
                
				int nowY(initY), nowX(initX), nowDir(initDir), len(0);

				if (check[nowY][nowX][nowDir]) continue;

				while (true) {
					if (check[nowY][nowX][nowDir]) break;

					check[nowY][nowX][nowDir] = true;

					nowY += dY[nowDir];
					nowX += dX[nowDir];

					nowY = (nowY + lenY) % (lenY);
                    			nowX = (nowX + lenX) % (lenX);

					if (grid[nowY][nowX] == 'R') nextDir++;
					if (grid[nowY][nowX] == 'L') nextDir--;
                    
					nowDir = (nowDir + 4) % 4
					len++;
				}
				answer.push_back(len);
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
