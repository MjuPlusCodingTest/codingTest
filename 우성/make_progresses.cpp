#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int size = speeds.size();

    vector<int> day;
    for (int i = 0; i < size; i++){
        for (int k = 1; k <= 100; k++){
            if (progresses[i] + (speeds[i] * k) >= 100){
                day.push_back(k);
                break;
            }
        }
    }

    int stan = 0;
    int temp = 0;
    for (int i = 0; i < size; i++){
        if (i == 0){
            temp = 1;
            stan = day[i];
        }else{
            if (day[i] <= stan){
                temp++;
                if(i == size - 1){
                    answer.push_back(temp);
                }
            }else{
                answer.push_back(temp);
                stan = day[i];
                temp = 1;
                if (i == size - 1){
                    answer.push_back(temp);
                }
            }
        }
    }


    return answer;
}