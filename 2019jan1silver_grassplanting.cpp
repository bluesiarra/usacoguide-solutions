#include <bits/stdc++.h>


#include <iostream>
#include <iostream>


using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> edges(N, 0);

    int ans = -1;

    for (int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a] += 1;
        edges[b] += 1;
    }

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, edges[i]);
    }
    cout << ans+1;
}