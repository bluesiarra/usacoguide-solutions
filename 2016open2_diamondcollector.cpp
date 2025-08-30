#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
 
    long long ans = 0;

    long long N, K;
    cin >> N >> K;

    vector<int> diamonds(N,0);

    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        diamonds[i] = d;
    }

    sort(diamonds.begin(), diamonds.end());

    vector<long long> intervals(N,0);
    vector<long long> suffix_max(N+1,0);

    int L = 0;
    int R = 0;

    while (L < N)
    {
        while (R < N-1 && diamonds[R+1]<=diamonds[L]+K){R++;}

        intervals[L] = R-L+1;
        L++;
    }

    suffix_max[N-1]=intervals[N-1];
    for (int i = N-2; i>=0;i--)
    {
        suffix_max[i] = max(suffix_max[i+1], intervals[i]);
    }

    for (int start = 0; start < N; start++)
    {
        ans = max(ans, intervals[start] + suffix_max[start + intervals[start]]);
    }
    
    cout << ans;
    return 0;
}