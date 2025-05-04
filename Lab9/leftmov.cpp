#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = n;
        set<int> seen;
        for (int i = n - 1; i >= 0; i--) {
            if (seen.find(a[i]) != seen.end()) {
                ans = i+1;
                break;
            }
            seen.insert(a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}