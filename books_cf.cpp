#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<long long> books(N, 0);

    int ans = -1;
    
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        
        books[i] = a;
    }

    int p1 = 0;
    int p2 = 0;

    int total = 0;
    while (p2 < N)
    {

        if (total + books[p2] > T)
        {
            total -= books[p1];
            p1 += 1;

            ans = max(p2 - p1 + 1, ans);

        }
        else {
            total += books[p2];
            p2 += 1;
        }
        //cout << "TOTAL: " << total << " from " << p1 << " to " << p2 << endl;
    }
    ans = max(p2-p1, ans);
    cout << ans;
}