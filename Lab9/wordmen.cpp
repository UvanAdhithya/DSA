#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> a(3, vector<string>(n));

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        vector<int> scores(3, 0);

        map<string, int> wordCounts;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                wordCounts[a[i][j]]++;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (wordCounts[a[i][j]] == 1) {
                    scores[i] += 3;
                } else if (wordCounts[a[i][j]] == 2) {
                    scores[i] += 1;
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            cout << scores[i] << (i == 2 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
