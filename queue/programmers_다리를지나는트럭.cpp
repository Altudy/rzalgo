#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int num_trucks = truck_weights.size();
    vector<int> truck_progresses(num_trucks, 0);
    int next_truck = 0;
    int tracked_weight = 0;
    int num_passed = 0;

    while (num_passed < num_trucks) {
        if (next_truck < num_trucks) {
            if (tracked_weight + truck_weights[next_truck] <= weight ||
                (truck_progresses[num_passed] + 1 > bridge_length
                    && tracked_weight - truck_weights[num_passed] + truck_weights[next_truck] <= weight)) {
                tracked_weight += truck_weights[next_truck++];
            }
        }
        for (int i = num_passed; i < next_truck; i++) {
            truck_progresses[i]++;
            if (truck_progresses[i] > bridge_length) {
                tracked_weight -= truck_weights[num_passed++];
            }
        }
        answer++;
    }


    return answer;
}
