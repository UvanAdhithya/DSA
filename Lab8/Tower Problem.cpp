// Tower Of Hanoi
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cout << "Enter test cases: ";
    cin >> t;
    
    while (t--){
        int n;
        cout << "Enter number of towers: ";
        cin >> n;

        vector <int> a(n);
        for( int i = 0; i < n; i++){
            cin >> a[i];
        }
        // Sort towers 2 to n
        int max = a[0];
        vector <int> b(a.begin()+1, a.end());
        sort(b.begin(), b.end());

        // Maximising formula if y > max
        for (int y : b){
            if (y > max){
                max += ((y-max) + 1)/2;
            }
        }
        cout << "The maximum blocks in tower 1 is " << max << endl;
    }
}