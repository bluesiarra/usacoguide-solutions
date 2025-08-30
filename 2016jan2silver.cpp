#include <iostream>
#include <climits>

using namespace std;
//P(x) = a[0] + a[1] + ... a[x-1]
//a[n] + a[n+1] .. a[k] is P(k+1)-P(n)
int main() {

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int N;
    cin >> N;
    int maxDiff = -1;

    int prefixes[N+1];
    int leftPf[N+1];
    int rightPf[N+1];

    fill_n(leftPf, N+1, INT_MAX);
    fill_n(rightPf, N+1,-1);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        prefixes[i] = cnt;

        if (i < leftPf[cnt])
        {
            leftPf[cnt] = i;
        }
        if (i > rightPf[cnt]) {
            rightPf[cnt] = i;
        }

        int next;
        cin >> next;
        cnt=(cnt+next)%7;
       
    }

    for (int i = 1; i < N+1;i++) {
        //cout << "i = " << i << " Left side: " << leftPf[i] << " Right side: " << rightPf[i] << endl;
        int diff = rightPf[i] - leftPf[i];
        if (diff > maxDiff)
        {
            maxDiff = diff;
        }
    }



    cout << maxDiff;
}