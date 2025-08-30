#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ifstream in("reststops.in");

	int trail_len;  // not used
	int stop_num;
	int f_rate;
	int b_rate;
	in >> trail_len >> stop_num >> f_rate >> b_rate;

	vector<int> x(stop_num);  // position of each stop
	vector<int> c(stop_num);  // tastiness value of each stop
	for (int i = 0; i < stop_num; i++) { in >> x[i] >> c[i]; }

	// find all the "best" stops
	vector<bool> good(stop_num);
	int max_tastiness = 0;
	for (int i = stop_num - 1; i >= 0; i--) {
		if (c[i] > max_tastiness) {
			// there are no stops after stop i that are "better"
			good[i] = true;
			max_tastiness = c[i];
		}
	}
	int total = 0;
	for (bool i : good) total += i;
	cout << total << endl;

	// simulate the whole trail
	long long prev_stop_pos = 0;
	long long ans = 0;
	for (int i = 0; i < stop_num; i++) {
		if (good[i]) {
			long long travel_dist = x[i] - prev_stop_pos;
			long long f_time = travel_dist * f_rate;
			long long b_time = travel_dist * b_rate;
			long long rest_time = f_time - b_time;
			ans += rest_time * c[i];
			prev_stop_pos = x[i];
		}
	}

	ofstream("reststops.out") << ans << endl;
}