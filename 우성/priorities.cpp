#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;


    set<int> set_pt(priorities.begin(), priorities.end());
    vector<int> pt;
    pt.assign(set_pt.begin(), set_pt.end());


    vector <pair<int, int>> numPt;
    for (int i = 0; i < pt.size(); i++){
        numPt.push_back({pt[i], count(priorities.begin(), priorities.end(), pt[i])});
    }

    int step = 0;
    while (true){
        int standard = numPt.back().second; //최우선 순위 개수
        int count = 0;
        while(count < standard){
            if (priorities[step] == numPt.back().first){
                if (step == location){
                    return answer + 1;
                }
                answer++;
                step++;
                count++;
                if (step == priorities.size()){
                    step = 0;
                }
            }else{
                step++;
                if (step == priorities.size()){
                    step = 0;
                }
            }
        }
        numPt.pop_back();
    }


    return answer;
}