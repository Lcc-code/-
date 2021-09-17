#include <stdio.h>
#include <vecotr>
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int city_num = isConnected.size();
        if (city_num == 0)
            return 0;
        int provence = 0;
        vector<int> visit(city_num, 0);
        for (int i = 0; i < city_num; i++)
        {
            if (visit[i] == 0)
            {
                visit[i] = 1;
                _DFS(i, city_num, visit, isConnected);
                provence++;
            }
        }
        return provence;
    }
private:
    void _DFS(int i, int city_num, vector<int> &visit, vector<vector<int> > isConnected)
    {
        for (int j = 0; j < city_num; j ++)
        {
            if (isConnected[i][j] == 1 && visit[j] == 0)
            {
                visit[j] = 1;
                _DFS(j, city_num, visit, isConnected);
            }
        }

    }

    int findCircleNum_2(vector<vector<int>>& isConnected) {
        int city_num = isConnected.size();
        if (city_num == 0)
            return city_num;
        int province = 0;
        std::queue<int> Q;
        
        vector<int> visit(city_num, 0);
        
        for (int i = 0; i < city_num; i++)
        {
            if (visit[i] == 0)
            {
                Q.push(i);
                while (!Q.empty())
                {
                    int tmp = Q.front();
                    Q.pop();
                    visit[tmp] = 1;
                    for (int j = 0; j < city_num; j++)
                    {
                        if (isConnected[tmp][j] == 1 && visit[j] == 0)
                        {
                            Q.push(j);
                        }
                    }
                    
                }
                province++;
            }
        }
        return province;


    }

};