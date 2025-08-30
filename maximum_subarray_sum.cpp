#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long ans = -1;
    vector<long long> prefix(N+2);
    vector<long long> left(N+2);
    vector<long long> right(N+2);
    prefix[0] = 0;
    prefix[N+1] = 0;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;

        prefix[i+1] = prefix[i] + a;
    }

    left[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        left[i] = min(prefix[i], left[i-1]);
    }

    /*for (int l : left)
    {
        cout << l << " ";
    }*/
    cout << endl;
    right[N+1] = prefix[N];

    for (int i = N; i >= 1; i--)
    {
        right[i] = max(prefix[i], right[i+1]);
    }
/*
    for (int r : right)
    {
        cout << r << " ";
    }
    cout << endl;*/

    ans = right[2]-left[0];
    for (int i = 1; i < N+1; i++)
    {
        ans = max(ans, right[i]-left[i-1] );
    }

    cout << ans;

}