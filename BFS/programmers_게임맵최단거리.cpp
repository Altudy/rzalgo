#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    int deltaY[] = {-1, 0, 1, 0};
    int deltaX[] = {0, -1, 0, 1};

    vector<vector<int>> found(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push(make_pair(0,0));
    found[0][0] = 1;

    while(!q.empty()){
        pair<int, int> nowPos = q.front();
        q.pop();
        int nowY = nowPos.first;
        int nowX = nowPos.second;

        for(int i = 0; i < 4; i++){
            int nextY = nowY + deltaY[i];
            int nextX = nowX + deltaX[i];

            if(nextX < 0 || m <= nextX || nextY < 0 || n <= nextY)
                continue;

            if(maps[nextY][nextX] == 0 || found[nextY][nextX] > 0)
                continue;

            q.push(make_pair(nextY, nextX));
            found[nextY][nextX] = found[nowY][nowX] + 1;
        }
        
    }
    

    answer = found[n-1][m-1];



    return answer;
}