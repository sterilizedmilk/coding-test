/**
 *  야근 지수
 * 회사원 Demi는 가끔은 야근을 하는데요, 야근을 하면 야근 피로도가 쌓입니다. 야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한 값입니다.
 * Demi는 N시간 동안 야근 피로도를 최소화하도록 일할 겁니다.
 * Demi가 1시간 동안 작업량 1만큼을 처리할 수 있다고 할 때, 퇴근까지 남은 N 시간과
 * 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 함수 solution을 완성해주세요.
 * 
 * 제한 사항
 *  works는 길이 1 이상, 20,000 이하인 배열입니다.
 *  works의 원소는 50000 이하인 자연수입니다.
 *  n은 1,000,000 이하인 자연수입니다.
 * 
 * https://programmers.co.kr/learn/courses/30/lessons/12927
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    sort(works.begin(), works.end());
    int size = works.size();
    int max = works.back();
    
    while (n > 0 && max)
    {
        for (int i = 0; i < size; ++i)
        {
            if (works[i] == max)
            {
                for (; i < size && n > 0; ++i)
                {
                    --works[i];
                    --n;
                }
                --max;
                break;
            }
        }
    }
    
    for (int w : works)
        answer += w * w;
    return answer;
}
