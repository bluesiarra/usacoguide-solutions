#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> hoofSum(N+1), paperSum(N+1), scissorSum(N+1);

    
    hoofSum[0] = 0;
    paperSum[0] = 0;
    scissorSum[0] = 0;

    int ans = -1;

    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;


        hoofSum[i+1] = hoofSum[i];
        paperSum[i+1] = paperSum[i];
        scissorSum[i+1] = scissorSum[i];
        if (c == 'H')
            hoofSum[i+1]+=1;
        else if (c == 'P')
            paperSum[i+1]+=1;
        else
            scissorSum[i+1]+=1;
    }
    //P(i) = a[0]+a[1]+...a[i-1]
    //a[b] + ... a[c] = a[c+1]-a[b]
    for (int mid = 0; mid <= N; mid++)
    {
        //[0, mid) => first one
        //[mid, N) => second one

        int hoof_before = hoofSum[mid] - hoofSum[0];
        int paper_before = paperSum[mid] - paperSum[0];
        int scissor_before = scissorSum[mid] - scissorSum[0];

        int hoof_after = hoofSum[N] - hoofSum[mid];
        int paper_after = paperSum[N] - paperSum[mid];
        int scissor_after = scissorSum[N] - scissorSum[mid];

        int beforeMax = max(hoof_before, max(paper_before, scissor_before));
        int afterMax = max(hoof_after, max(paper_after, scissor_after));

        ans = max(beforeMax+afterMax, ans);

    }

    cout << ans;

}