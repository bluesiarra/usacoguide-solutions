#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<vector <long long>> grid(N+1, vector<long long>(M+1, 0));
    vector<vector <int>> queries(Q, vector<int>(4,0));
    vector<vector <long long>> prefixes(N+1, vector<long long>(M+1,0)); //prefixes[i][j] = # of distinct groups from grid[0][0] to grid[i][j]
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < M; j++) {
            char c = row[j];
            grid[i+1][j+1] = c - '0';
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries[i] = {x1, y1, x2, y2};
    }


    //Make prefix sum array

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            prefixes[i][j] += prefixes[i-1][j] + prefixes[i][j-1] - prefixes[i-1][j-1];
            if (grid[i][j] == 1)
            {
                if (grid[i-1][j] == 1 && grid[i][j-1] == 1)
                {
                    prefixes[i][j] -= 1;
                }
                else if (grid[i-1][j] == 0 && grid[i][j-1] == 0)
                {
                    prefixes[i][j] += 1;
                }
                else {
                    prefixes[i][j] += 0;
                }
            }
        }
    }

    vector<vector<int>> horpref(N+1, vector<int>(M+1));
    vector<vector<int>> vertpref(N+1, vector<int>(M+1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            horpref[i][j] = horpref[i][j-1];
            vertpref[i][j] = vertpref[i-1][j];

            if (grid[i][j] == 1)
            {
                horpref[i][j] += 1 - grid[i][j-1];
                vertpref[i][j] += 1 - grid[i-1][j];
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        vector<int> query = queries[i];
        int x1 = query[0];
        int y1 = query[1];
        int x2 = query[2];
        int y2 = query[3];

        int ans = 0;
        ans += prefixes[x1][y1];
        ans += grid[x1][y1];
        ans += horpref[x1][y2]-horpref[x1][y1];
        ans += vertpref[x2][y1]-vertpref[x1][y1];
        ans += prefixes[x2][y2] - prefixes[x2][y1] - prefixes[x1][y2];

        cout << ans<< endl;
    }
/*
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            cout << prefixes[i][j] << " ";
        }
        cout << endl;
    }*/

    //1 1 0 1
    //0 1 1 0
    //1 1 0 1

    //1 1 1 2
    //1 1 1 2
    //2 1 1 3
}