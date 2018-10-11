/**
 *  가장 긴 팰린드롬
 * 앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.
 * 문자열 s가 주어질 때, s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.
 * 예를들면, 문자열 s가 abcdcba이면 7을 return하고 abacde이면 3을 return합니다.
 * 
 * https://programmers.co.kr/learn/courses/30/lessons/12904
 */

#include <string>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int i, j;
    for (i = 0; i < s.size(); ++i)
    {
        for (j = 1; i - j >= 0 && i + j < s.size(); ++j) // odd
        {
            if (s[i - j] != s[i + j])
                break;
        }

        if (answer < j * 2 - 1)
            answer = j * 2 - 1;
        
        if (i > 0 && s[i] == s[i-1])
        {
            for (j = 1; i - j > 0 && i + j < s.size(); ++j) // even
            {
                if (s[i - j - 1] != s[i + j])
                    break;
            }

            if (answer < j * 2)
                answer = j * 2;
        }
    }

    return answer;
}