#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct SongId
{
    int id;
    int play;
    string genre;
    
    SongId(const int i, const int p, const string g) :
        id(i), play(p), genre(g){}
    bool operator<(const SongId& A) const
    { 
        if(play == A.play)
            return id < A.id;
        else
            return play > A.play;
    }
};

bool cmp(const pair<string, long long>& a, const pair<string, long long>& b){
    return a.second > b.second;
}



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, long long> totalPlay;
    vector<SongId> allInfo;
    for(int i = 0; i < genres.size(); i++){
        totalPlay[genres[i]] += plays[i];
        SongId *sid = new SongId(i, plays[i], genres[i]);
        allInfo.push_back(*sid);
    }
    vector<pair<string, long long>> tP(totalPlay.begin(), totalPlay.end());
    sort(tP.begin(), tP.end(), cmp);
    sort(allInfo.begin(), allInfo.end());
    
    for(const auto& g : tP){
        int i = 0;
        for(; i < allInfo.size(); i++){
            if(allInfo[i].genre == g.first){
                answer.push_back(allInfo[i].id);
                break;
            }
        }
        for(int j = i + 1; j < allInfo.size(); j++){
            if(allInfo[j].genre == g.first){
                answer.push_back(allInfo[j].id);
                break;
            }
        }
    }
    
    
    return answer;
}