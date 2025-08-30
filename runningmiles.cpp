#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    int answers[T];
    for (int test_case = 0; test_case < T; test_case+=1)
    {
        int N;
        cin >> N;

        int left_max[N];
        int right_max[N];
        int beauties[N];

        int maxAns = -1;
        for (int i = 0; i < N; i++)
        {
            int ans;
            cin >> ans;

            beauties[i] = ans;
            left_max[i] = ans + i;
            right_max[i] = ans - i;
        }

        for (int i = 1; i < N-1; i++)
        {
            left_max[i] = max(left_max[i-1], left_max[i]);
        }
        for (int i = N-2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i+1], right_max[i]);
        }

        for (int i = 1; i < N-1; i++)
        {
            int B_m = beauties[i];
            int left_side = left_max[i-1];
            int right_side = right_max[i+1];


            int tot = B_m + left_side + right_side;
            if (tot > maxAns){
                maxAns = tot;
            }
        }

        answers[test_case] = maxAns;
    }

    for (int a : answers)
    {
        cout << a << endl;
    }
    return 0;
}