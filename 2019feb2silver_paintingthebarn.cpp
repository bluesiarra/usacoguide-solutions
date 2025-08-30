#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    int ans = 0;

    vector<vector<long long>> grid(1002, vector<long long>(1002,0));
    vector<vector<long long>> PSA(1002, vector<long long>(1002,0));
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1;
        y1 += 1;
        x2 += 1;
        y2 += 1;

        grid[x1][y1] += 1;
        grid[x2][y2] += 1;
        grid[x2][y1] -= 1;
        grid[x1][y2] -= 1;


    }


    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            PSA[i][j] += grid[i][j] + PSA[i-1][j] + PSA[i][j-1] - PSA[i-1][j-1];
            if (PSA[i][j] == K)
            {
                ans += 1;

            }
        }
    }




    cout << ans;

    return 0;
}