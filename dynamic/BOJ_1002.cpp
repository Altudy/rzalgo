#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    vector<pair<int, int>> dp(42, make_pair(0, 0));

    dp[0].first = 1;
    dp[1].second = 1;
    int i = 2;
    while(T--){
        int N;
        cin >> N;

        for(; i <= N; i++){
            dp[i].first = dp[i-1].first + dp[i-2].first;
            dp[i].second = dp[i-1].second + dp[i-2].second;
        }

        cout << dp[N].first << " " << dp[N].second << "\n";

    }
    return 0;
}