//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main() {


    int N,K;
    cin >> N >> K;

    vector<vector<int>> grid(10, vector<int>(N, 0));

    vector<vector<int>> ans(10, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;

        int index = 0;
        for (char c : line)
        {
            grid[index][i] = c-'0';
        }
    }
    vector<vector<int>> original = grid;
    bool process_done = false;

    while (!process_done)
    {
        bool filled_smth = false;
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (grid[x][y] != 0){
                    int color = grid[x][y];

                    filled_smth = true;
                    

                    queue<array<int, 2>> q;
                    q.push({x,y});
                    grid[x][y] = 0;

                    int cnt = 0;

                    while (!q.empty())
                    {
                        cnt += 1;

                        int qX = q.front()[0];
                        int qY = q.front()[1];
                        q.pop();

                        vector<array<int, 2>> dirs = {{0,1}, {0,-1},{1,0},{-1,0}};

                        for (array<int, 2> direction : dirs)
                        {
                            int xx = qX + direction[0];
                            int yy = qY + direction[1];

                            if (xx < 0 || xx >= 10) {
                                continue;
                            }

                            if (yy < 0 || yy >= N)
                            {
                                continue;
                            }


                            if (grid[xx][yy] == color)
                            {
                                grid[xx][yy] = 0;
                                q.push({xx, yy});
                            }
                        }
                    }
               
                    if (cnt < K)
                    {
                        grid = original;
                    }
                    else {
                        original = grid;
                    }

                    /*
                    for (int i = 0; i < 10; i++)
                    {
                        int write_row = N-1;
                        for (int j = N-1; j >= 0; j--)
                        {
                            original[i][write_row] = grid[i][j];
                            if (grid[i][j] != 0) {

                                write_row -= 1;
                            }
                        }
                    }
                    grid = original;
                    */
                }


            }
        }

        process_done = true;//!filled_smth;

    }

    for (int i = 0; i < N; i++)
    {
        for (int x = 0; x < 10; x++)
        {
            cout << grid[x][i];
        }
        cout << endl;
    }


}