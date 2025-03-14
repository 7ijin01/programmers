#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len=board[0].size();
    stack <int> s[len];
    stack<int> total;

    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j >= 0; j--) {
            if (board[j][i] != 0) {
                s[i].push(board[j][i]);
            }
        }
    }
    for(int i=0;i<moves.size();i++)
    {
        if(!s[moves[i]-1].empty())
        {
            if(!total.empty())
            {
                if(total.top()==s[moves[i]-1].top())
                {
                    total.pop();
                    s[moves[i]-1].pop();
                    answer+=2;
                    continue;
                }
                
            }
            total.push(s[moves[i]-1].top());
            s[moves[i]-1].pop();
        }
    }
    return answer;
}