/** 
 *  하노이의 탑
 * 하노이 탑(Tower of Hanoi)은 퍼즐의 일종입니다. 세 개의 기둥과 이 기동에 꽂을 수 있는 크기가 다양한 원판들이 있고,
 * 퍼즐을 시작하기 전에는 한 기둥에 원판들이 작은 것이 위에 있도록 순서대로 쌓여 있습니다.
 * 게임의 목적은 다음 두 가지 조건을 만족시키면서, 한 기둥에 꽂힌 원판들을 그 순서 그대로 다른 기둥으로 옮겨서 다시 쌓는 것입니다.
 * 
 * 한 번에 하나의 원판만 옮길 수 있습니다.
 * 큰 원판이 작은 원판 위에 있어서는 안됩니다.
 * 하노이 탑의 세 개의 기둥을 왼쪽 부터 1번, 2번, 3번이라고 하겠습니다. 1번에는 n개의 원판이 있고 이 n개의 원판을 3번 원판으로 최소 횟수로 옮기려고 합니다.
 * 
 * 1번 기둥에 있는 원판의 개수 n이 매개변수로 주어질 때, n개의 원판을 3번 원판으로 최소로 옮기는 방법을 return하는 solution를 완성해주세요.
 * 
 * 제한사항
 *  n은 15이하의 자연수 입니다.
 * 
 * https://programmers.co.kr/learn/courses/30/lessons/12946
 */

#include <vector>

using namespace std;

vector<int> plus1(const vector<int> &vec)
{
    vector<int> plus;
    
    if (vec[0] == 3)
        plus.push_back(1);
    else
        plus.push_back(vec[0] + 1);
    
    if (vec[1] == 3)
        plus.push_back(1);
    else
        plus.push_back(vec[1] + 1);
    
    return plus;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    bool even;
    if (n & 1)
        even = false;
    else
        even = true;
    
    answer.push_back({1, 3});
    int size = 1;
    for (int i = 0; i < n-1; ++i)
    {
        for (auto &vec : answer)
        {
            switch (vec[0])
            {
                case 2:
                    vec[0] = 3;
                    break;
                case 3:
                    vec[0] = 2;
                    break;
                default:
                    break;
            }
            
            switch (vec[1])
            {
                case 2:
                    vec[1] = 3;
                    break;
                case 3:
                    vec[1] = 2;
                    break;
                default:
                    break;
            }
        }
        size = answer.size();
        answer.push_back({1, 3});
        
        for (int j = 0; j < size; ++j)
        {
            answer.push_back(plus1(answer[j]));
        }
    }
    
    return answer;
}
