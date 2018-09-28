/**
 *   이중우선순위큐
 * 이중 우선순위 큐는 다음 연산을 할 수 있는 자료구조를 말합니다.
 * 
 *   명령어 | 수신 탑(높이)
 *   I     | 숫자큐에 주어진 숫자를 삽입합니다.
 *   D 1   | 큐에서 최댓값을 삭제합니다.
 *   D -1  | 큐에서 최솟값을 삭제합니다.
 * 이중 우선순위 큐가 할 연산 operations가 매개변수로 주어질 때,
 * 모든 연산을 처리한 후 큐가 비어있으면 [0,0] 비어있지 않으면 [최댓값, 최솟값]을 return 하도록 solution 함수를 구현해주세요.
 * 
 * 제한사항
 *  operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.
 *  operations의 원소는 큐가 수행할 연산을 나타냅니다.
 *  원소는 “명령어 데이터” 형식으로 주어집니다.- 최댓값/최솟값을 삭제하는 연산에서 최댓값/최솟값이 둘 이상인 경우, 하나만 삭제합니다.
 *  빈 큐에 데이터를 삭제하라는 연산이 주어질 경우, 해당 연산은 무시합니다.
 * 
 * https://programmers.co.kr/learn/courses/30/lessons/42628
 */

#include <string>
#include <vector>

using namespace std;

template<typename T>
class node
{
public:
    T value;
    node<T> *before;
    node<T> *next;

    node(T t, node<T>* before, node<T>* next)
    {
        value = t;
        this->before = before;
        this->next = next;

        if (before)
            before->next = this;
        if (next)
            next->before = this;
    }
};

template<typename T>
class double_queue
{
public:
    node<T> *min;
    node<T> *max;

    double_queue()
    {
        min = nullptr;
        max = nullptr;
    }
    
    ~double_queue()
    {
        // stuff
    }

    void push(T t)
    {
        node<T> *new_node;

        if (empty())
        {
            new_node = new node<T>(t, nullptr, nullptr);
            min = new_node;
            max = new_node;
        }
        else if (t <= min->value)
        {
            new_node = new node<T>(t, nullptr, min);
            min = new_node;
        }
        else if (t >= max->value)
        {
            new_node = new node<T>(t, max, nullptr);
            max = new_node;
        }
        else
        {
            node<T>* n = min;
            for (; t > n->value; n = n->next);
            new node<T>(t, n, n->next);
        }
    }

    void pop_front()
    {
        if (!min)
            return;

        if (min == max)
        {
            delete min;
            min = nullptr;
            max = nullptr;
            return;
        }

        node<T> *new_min = min->next;
        new_min->before = nullptr;
        delete min;
        min = new_min;
    }

    void pop_back()
    {
        if (!max)
            return;

        if (min == max)
        {
            delete max;
            min = nullptr;
            max = nullptr;
            return;
        }

        node<T> *new_max = max->before;
        new_max->next = nullptr;
        delete max;
        max = new_max;
    }

    T top() const
    {
        return max->value;
    }

    T bottom() const
    {
        return min->value;
    }

    bool empty() const
    {
        return min == nullptr;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    double_queue<int> que;
    for (string oper : operations)
    {
        switch(oper[0])
        {
            case 'I':
                que.push(stoi(oper.substr(2)));
                break;
            case 'D':
                if (oper[2] == '1')
                    que.pop_back();
                else
                    que.pop_front();
                break;
            default:
                break;
        }
    }

    if (que.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(que.top());
        answer.push_back(que.bottom());
    }
    return answer;
}
