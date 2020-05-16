#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int curPos = 0;
    int numRefills = 0;
    int n = stops.size();
    while(curPos < n - 1) {
        int lastPos = curPos;
        while(curPos < n - 1 && stops[curPos+1] -stops[lastPos] <= tank) curPos++;
        if(curPos == lastPos) return -1;
        if(curPos < n - 1) numRefills++;
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);
    stops[0] = 0;
    stops[n+1] = d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
