#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int main() {
    long long N;
    cin >> N;

    vector <long long> nums;
    vector <long long> prefix(N);
    vector <long long> suffix(N);


    for (int i = 0; i < N; i++)
    {
        long long A;
        cin >> A;
        nums.push_back(A);
    }
    long long max_gcd = -1;

    prefix[0] = nums[0];
    suffix[N-1] = nums[N-1];
    for (int i = 1; i < N; i++)
    {
        prefix[i]=gcd(prefix[i-1], nums[i]);
        suffix[N-i-1] = gcd(suffix[N-i], nums[N-i-1]);
    }

    for (int i = 0; i < N; i++)
    {
        long long pre;
        long long suf;
        if (i == 0)
        {
            pre = 0;
        }
        else {
            pre = prefix[i-1];
        }
        if (i == N-1)
        {
            suf = 0;
        }
        else {
            suf = suffix[i+1];
        }

        max_gcd = max(max_gcd, gcd(suf, pre));
    }

    cout << max_gcd;
}