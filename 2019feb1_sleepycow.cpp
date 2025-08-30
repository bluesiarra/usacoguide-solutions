#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
   freopen("herding.in", "r", stdin);
freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums;
    
    int min_size = INT_MAX;
    int max_size = -1;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());
    int p2 = 0;

    if (nums[n-2]-nums[0] == n-2 && nums[n-1]-nums[n-2] > 2)
    {
        min_size = 2;
    }
    else if (nums[n-1]-nums[1] == n-2 && nums[1]-nums[0] > 2)
    {
        min_size = 2;
    }
    else {
    for (int p1 = 0; p1 < n; p1++)
    {
        while (nums[p2+1]-nums[p1]+1<= n && p2+1 < n) {p2+=1;}
        int cows_in_window = p2 - p1 + 1;
        min_size = min(n-cows_in_window, min_size);

    }
}
    max_size = max(nums[n-1]-nums[1]-(n-2), nums[n-2]-nums[0]-(n-2));
    cout << min_size << endl;
    cout << max_size;
}