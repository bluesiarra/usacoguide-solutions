#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<long long> ans(n+1,0);
    vector<long long> arr(n+1);
    vector<vector<long long>> ops(m);
    vector<long long> queries(m+1, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        l -= 1;
        r -= 1;
        ops[i] = {l, r, d};

    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;
        queries[x] += 1;
        queries[y+1] -= 1;
    }

    for (int i = 1; i < m; i++)
    {
        queries[i] = queries[i-1] + queries[i];
    }


    for (int i = 0; i < m; i++)
    {
        vector<long long> cur = ops[i];
        int ops_needed = queries[i];
        
        ans[cur[0]] += ops_needed * cur[2];
        ans[cur[1]+1] -= ops_needed * cur[2];

    }



    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i-1] + ans[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] + ans[i] << " ";
    }

    return 0;
}