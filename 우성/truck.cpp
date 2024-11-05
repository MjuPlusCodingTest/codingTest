#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pair<int, int>> truck;     //무게, 올라가있는 시간
    for (int t : truck_weights){
        truck.push({t, 0});
    }

    int current_truck = 0; //현재 올라와있는 트럭 수
    int current_weight = 0;   //현재 올라와있는 트럭 무게합
    vector<pair<int, int>> temp;

    while(1){   //루프 한번당 1초로

        if (!temp.empty()){
            for (int i = 0; i < current_truck; i++){
                temp[i].second++;
            }
            if (temp.front().second == bridge_length){
                current_truck--;
                current_weight -= temp.front().first;
                temp.erase(temp.begin());
            }
            if (temp.empty() && truck.empty()){
                answer++;
                break;
            }
        }

        if (!truck.empty()){  //대기 중인 트럭이 있으면 실행
            if ((current_truck + 1 <= bridge_length) && (current_weight + truck.front().first <= weight)){
                current_truck++;  // 트럭올라옴
                current_weight += truck.front().first;  //무게 증가
                temp.push_back(truck.front());  //temp에 넣음
                truck.pop();   //truck에서 삭제
            }
        }
        answer++;
    }

    return answer;
}