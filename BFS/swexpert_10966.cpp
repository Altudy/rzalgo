#include <queue>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int deltaY[] = {-1, 0, 1, 0};
    int deltaX[] = {0, -1, 0, 1};

    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int n, m;
        int answer = 0;
        cin >> n >> m;
        vector<vector<int>> map(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char input;
                cin >> input;
                if(input == 'W'){
                    map[i][j] = -1;
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()){
            int nowY = q.front().first;
            int nowX = q.front().second;
            q.pop();
            if(map[nowY][nowX] != -1)
                answer += map[nowY][nowX];

            for(int i = 0; i < 4; i++){
                int nextY = nowY + deltaY[i];
                int nextX = nowX + deltaX[i];

                if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                    continue;
                if(map[nextY][nextX] != 0)
                    continue;

                if(map[nowY][nowX] == -1)
                    map[nextY][nextX] = 1;
                else
                    map[nextY][nextX] = map[nowY][nowX] + 1;
                q.push(make_pair(nextY, nextX));
            }
            
        }

        cout << '#' << k << ' ' << answer << '\n';
    }
    return 0;
}