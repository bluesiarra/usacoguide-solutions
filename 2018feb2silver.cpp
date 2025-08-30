//https://usaco.org/index.php?page=viewproblem2&cpid=810

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    int L, N, r_f, r_b;

    cin >> L >> N >> r_f >> r_b;

    vector<vector<long long>> stops(N,vector<long long>(2,0));
    for (int i = 0; i < N; i++)
    {
        int x, c;
        cin >> x >> c;

        stops[i] = {x, c};
    }

    sort(stops.begin(), stops.end());
    
    long long ans = 0;
    int last_stop = 0;

    vector<long long> max_array(N,-1);

    max_array[N-1] = stops[N-1][1];
    for (int i = N-2; i >= 0; i--)
    {
        max_array[i] = max(max_array[i+1], stops[i][1]); 
    }

    for (int i = 0; i < N; i++)
    {
        int pos = stops[i][0];
        int taste = stops[i][1];

        if (taste >= max_array[i+1]){

            long long farmer_time = r_f * (pos-last_stop);
            long long bessie_time = r_b * (pos-last_stop);

            ans += (farmer_time-bessie_time)*taste;

            last_stop = pos;
        }
    }
    cout << ans;
    return 0;

}