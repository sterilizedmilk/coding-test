
/*
 *  길 찾기 게임
 * 전무로 승진한 라이언은 기분이 너무 좋아 프렌즈를 이끌고 특별 휴가를 가기로 했다. 
 * 내친김에 여행 계획까지 구상하던 라이언은 재미있는 게임을 생각해냈고 역시 전무로 승진할만한 인재라고 스스로에게 감탄했다.
 * 
 * 라이언이 구상한(그리고 아마도 라이언만 즐거울만한) 게임은, 카카오 프렌즈를 두 팀으로 나누고,
 * 각 팀이 같은 곳을 다른 순서로 방문하도록 해서 먼저 순회를 마친 팀이 승리하는 것이다.
 * 
 * 그냥 지도를 주고 게임을 시작하면 재미가 덜해지므로, 라이언은 방문할 곳의 2차원 좌표 값을 구하고
 * 각 장소를 이진트리의 노드가 되도록 구성한 후, 순회 방법을 힌트로 주어 각 팀이 스스로 경로를 찾도록 할 계획이다.
 * 
 * 라이언은 아래와 같은 특별한 규칙으로 트리 노드들을 구성한다.
 *  트리를 구성하는 모든 노드의 x, y 좌표 값은 정수이다.
 *  모든 노드는 서로 다른 x값을 가진다.
 *  같은 레벨(level)에 있는 노드는 같은 y 좌표를 가진다.
 *  자식 노드의 y 값은 항상 부모 노드보다 작다.
 *  임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
 *  임의의 노드 V의 오른쪽 서브 트리(right subtree)에 있는 모든 노드의 x값은 V의 x값보다 크다.
 * 
 * 다행히 두 팀 모두 머리를 모아 분석한 끝에 라이언의 의도를 간신히 알아차렸다.
 * 
 * 곤경에 빠진 카카오 프렌즈를 위해 이진트리를 구성하는 노드들의 좌표가 담긴 배열 nodeinfo가 매개변수로 주어질 때, 
 * 노드들로 구성된 이진트리를 전위 순회, 후위 순회한 결과를 2차원 배열에 순서대로 담아 return 하도록 solution 함수를 완성하자.
 * 
 * https://programmers.co.kr/learn/courses/30/lessons/42892
 */

#include <algorithm>
#include <vector>
using namespace std;

class node
{
public:
    int i;
    int x, y;
    node *left = nullptr;
    node *right = nullptr;
    
    node(int i, int x, int y) : i(i), x(x), y (y) {}
    
    void add(node *other)
    {
        if (other->x < x)
        {
            if (left)
                left->add(other);
            else
                left = other;
        }
        else
        {
            if (right)
                right->add(other);
            else
                right = other;
        }
    }
    
    void preorder(vector<int> &ans)
    {
        ans.push_back(i);
        if (left)
            left->preorder(ans);
        if (right)
            right->preorder(ans);
    }
    
    void postorder(vector<int> &ans)
    {
        if (left)
            left->postorder(ans);
        if (right)
            right->postorder(ans);
        ans.push_back(i);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    
    for (int i = 0; i < nodeinfo.size(); ++i)
        nodeinfo[i].push_back(i+1);
    
    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int> &a, const vector<int> &b)
            {
                if (a[1] == b[1])
                    return a[0] < b[0];
                return a[1] > b[1];
            } );
    
    node base(nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]);
    for (int i = 1; i < nodeinfo.size(); ++i)
    {
        node *new_node = new node(nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]);
        base.add(new_node);
    }
    
    base.preorder(answer[0]);
    base.postorder(answer[1]);
    return answer;
}
