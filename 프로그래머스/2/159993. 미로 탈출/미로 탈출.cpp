#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int **visit;
int **arr;

int x1[] = {0, 1, 0, -1};
int y1[] = {1, 0, -1, 0};
int n, m;

pair<int, int> bfs1(int x, int y)
{
    queue<pair<int, int>> q;
    visit[x][y] = 0;  // 시작 위치는 거리 0
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        if (arr[xx][yy] == 3)
        {
            return {xx, yy};
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xs = xx + x1[i];
            int ys = yy + y1[i];
            if (xs >= 0 && xs < n && ys >= 0 && ys < m)
            {
                if (visit[xs][ys] == -1 && arr[xs][ys] != 0)
                {
                    q.push(make_pair(xs, ys));
                    visit[xs][ys] = visit[xx][yy] + 1;
                }
            }
        }
    }
    return {-1, -1};
}

pair<int, int> bfs2(int x, int y)
{
    queue<pair<int, int>> q;
    visit[x][y] = 0;  // 시작 위치는 거리 0
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        if (arr[xx][yy] == 4)
        {
            return {xx, yy};
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xs = xx + x1[i];
            int ys = yy + y1[i];
            if (xs >= 0 && xs < n && ys >= 0 && ys < m)
            {
                if (visit[xs][ys] == -1 && arr[xs][ys] != 0)
                {
                    q.push(make_pair(xs, ys));
                    visit[xs][ys] = visit[xx][yy] + 1;
                }
            }
        }
    }
    return {-1, -1};
}

int solution(vector<string> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    visit = new int *[n];
    arr = new int *[n];
    int x, y;

    // 초기화
    for (int i = 0; i < n; i++)
    {
        visit[i] = new int[m];
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            visit[i][j] = -1;  // 거리 측정용이므로 -1 초기화
            if (maps[i][j] == 'S')
            {
                x = i;
                y = j;
                arr[i][j] = 2;
            }
            else if (maps[i][j] == 'E')
            {
                arr[i][j] = 4;
            }
            else if (maps[i][j] == 'L')
            {
                arr[i][j] = 3;
            }
            else if (maps[i][j] == 'O')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }

    // S -> L
    pair<int, int> result = bfs1(x, y);
    if (result.first != -1)
    {
        answer += visit[result.first][result.second];

        // visit 배열 초기화 후 L -> E 탐색
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visit[i][j] = -1;
            }
        }

        pair<int, int> result1 = bfs2(result.first, result.second);
        if (result1.first == -1)
        {
            answer = -1;
        }
        else
        {
            answer += visit[result1.first][result1.second];
        }
    }
    else
    {
        answer = -1;
    }

    // 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] visit[i];
        delete[] arr[i];
    }
    delete[] visit;
    delete[] arr;

    return answer;
}
