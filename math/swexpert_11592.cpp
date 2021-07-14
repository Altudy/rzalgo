#include <iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    cout << fixed;
    cout.precision(7);
    for(int i = 0; i < t; i++){
        long long dist; int numOfHorse;
        cin >> dist >> numOfHorse;
        long double longestTime = 0;
        for(int i = 0; i < numOfHorse; i++){
            long long src, speed;
            cin >> src >> speed;
            long double timeSpent = (dist - src) / (long double)speed;
            if(longestTime < timeSpent)
                longestTime = timeSpent;
        }
        cout << '#' << i+1 << ' ' << dist / longestTime << '\n';
    }

}