#include "../include.hpp"
using namespace std;
#include <vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numLands = 0;
        if (grid.size() == 0)
            return numLands;
        std::vector<std::vector<int> >mark(grid.size(), std::vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (mark[i][j] == 0 && grid[i][j] == '1')
                {
                    DFS(mark, grid, i, j);
                    numLands ++;
                }
            }
        }
        return numLands;
    }

    void DFS(std::vector<std::vector<int> >&mark, std::vector<std::vector<char> > &grid,
            int x, int y)
    {
        mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newy < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
            {
                continue;
            }
            if (mark[newx][newy] == 0 && grid[newx][newy] == '1')
                DFS(mark, grid, newx, newy);
        }
    }

    void BFS(std::vector<std::vector<int> > &mark,
            std::vector<std::vector<char> > &grid,
            int x, int y)
    {
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        std::queue<std::pair<int, int> > Q;
        Q.push(std::make_pair(x, y));
        mark[x][y] = 1;
        while (!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
                    continue;
                if (mark[newx][newy] == 0 && grid[newx][newy] == '1')
                {
                    Q.push(make_pair(newx, newy));
                    mark[newx][newy] = 1;
                }
            }
        }



    }




};