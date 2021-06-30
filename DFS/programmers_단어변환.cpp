#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<string>* p_words;
string* p_target;
vector<int> v_chk(50,0);
int depth = 0, g_len;

int check(string ori, string tar){
    int count = 0, len = ori.size();
    for(int i = 0; i < len; ++i)
        if(ori[i] != tar[i])
            count++;
    return count;
}

void solve(string now){
    
    queue<pair<string,int>> q;
    q.push(make_pair(now,0));
    
    while(!q.empty()){
        string it = q.front().first;
        depth = q.front().second;
        q.pop();
        if(*p_target == it)
            return;
        for(int i = 0; i < g_len; ++i){
            if(v_chk[i] == 0 && check(it, p_words->at(i)) == 1){
                
                q.push(make_pair(p_words->at(i),depth+1));
                v_chk[i] = 1;
            }
        }
    }
    depth = 0;
    return ;
}

int solution(string begin, string target, vector<string> words) {

    p_words = &words;
    p_target = &target;
    g_len = words.size();
    
    solve(begin);

    return depth;
}