#include <vector>
#include <queue>

using namespace std;
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};

bool canGo(int w, int h, int x, int y){
    if (x < 0 || x >= w || y < 0 || y >= h){
        return false;
    }


    return true;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;

    int w = maps.size();
    int h = maps[0].size();



    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    q1.push(make_pair(0, 0)); //start
    pair<int, int> temp;
    maps[0][0] = 0;

    while (1){
        if (q1.empty() && q2.empty()){
            return -1;
        }
        if (q2.empty()){
            //q1 ON
            while(!q1.empty()){
                temp = q1.front();



                for (int i = 0; i < 4; i++){
                    int nx = temp.first + x[i];
                    int ny = temp.second + y[i];
                    if (canGo(w, h, nx, ny)){
                        if (nx == w - 1 && ny == h - 1){
                            return ++answer + 1;
                        }
                        if (maps[nx][ny] == 1){
                            q2.push({nx, ny});
                            maps[nx][ny] = 0;
                        }
                    }
                }
                q1.pop();
            }
            answer++;
        }else if(q1.empty()){
            //q2 ON
            while(!q2.empty()){
                temp = q2.front();


                for (int i = 0; i < 4; i++){
                    int nx = temp.first + x[i];
                    int ny = temp.second + y[i];
                    if (canGo(w, h, nx, ny)){
                        if (nx == w - 1 && ny == h - 1){
                            return ++answer + 1;
                        }
                        if (maps[nx][ny] == 1){
                            q1.push({nx, ny});
                            maps[nx][ny] = 0;
                        }
                    }

                }
                q2.pop();
            }
            answer++;
        }
    }

    return answer;
}

