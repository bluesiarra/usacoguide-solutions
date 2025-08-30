#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
    
    long long ans = -1;

    int N, K;
    cin >> N >> K;
    vector<long long> diamonds;

    for (int i = 0; i < N; i++){
        int a;
        cin >> a;

        diamonds.push_back(a);
    }

    sort(diamonds.begin(), diamonds.end());
    
    vector<long long> max_in_case(N);
    vector<long long> suffix_max(N+1);


    int r = 0;

    for (int l = 0; l < N; l++)
    {
        while(r < N && diamonds[r]-diamonds[l]<=K){r+=1;}

        max_in_case[l] = r-l;
    }

    suffix_max[N-1] = max_in_case[N-1];
    suffix_max[N] = 0;
    for (int i = N-2; i >= 0; i--)
    {
        suffix_max[i] = max(max_in_case[i], suffix_max[i+1]);
    }

    for (int l = 0; l < N; l++)
    {
        ans = max(ans, max_in_case[l] + suffix_max[l + max_in_case[l]]);
    }

    cout << ans;
    
}
// 1 5 5 9 10 12 14