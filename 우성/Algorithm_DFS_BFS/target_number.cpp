#include <string>
#include <vector>

using namespace std;
void dfs(vector<int> numbers, int target, int &answer, int current_sum, int index);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, answer, 0, 0);

    return answer;
}

void dfs(vector<int> numbers, int target, int &answer, int current_sum, int index){

    if (index == numbers.size() - 1){
        if (current_sum + numbers[index] == target){
            answer++;

        }
        if (current_sum - numbers[index] == target){
            answer++;

        }
        return;
    }
    dfs(numbers, target, answer, current_sum + numbers[index], index + 1);
    dfs(numbers, target, answer, current_sum - numbers[index], index + 1);
}
