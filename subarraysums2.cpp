#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    long long N;
    long long X;
    cin >> N;
    cin >> X;

    map<long long, long long> vst;
    vst[0] = 1;
    long long ans = 0;
    long long cnt = 0;
    for (long long i = 0; i < N; i++)
    {
        long long a;
        cin >> a;

        cnt += a;

        

        long long subtracted = cnt - X;

        ans += vst[subtracted];

        vst[cnt] += 1;
    }

    cout << ans;

}