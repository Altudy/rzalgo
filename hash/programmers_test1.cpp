#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> split(string in, char del) {
    vector<string> ret;
    stringstream ss(in);
    string temp;
    while (getline(ss, temp, del)) {
        ret.push_back(temp);
    }
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nicknames;
    vector<pair<string, int>> arr;
    for (string row : record) {
        vector<string> temp = split(row, ' ');
        string command = temp[0];
        string uid = temp[1];
        string nick = "";
        if (temp.size() > 2)
            nick = temp[2];
        if (command == "Enter") {
            nicknames[uid] = nick;
            arr.push_back(make_pair(uid, 1));
        }
        else if (command == "Leave") {
            arr.push_back(make_pair(uid, 0));
        }
        else if (command == "Change") {
            nicknames[uid] = nick;
        }
    }
    for (auto res : arr) {
        string uid = res.first;
        int chk = res.second;
        if (chk == 1) {
            answer.push_back(nicknames[uid] + "님이 들어왔습니다.");
        }
        else if (chk == 0) {
            answer.push_back(nicknames[uid] + "님이 나갔습니다.");
        }
    }

    return answer;
}