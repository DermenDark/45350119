#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<char> results;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        vector<long double> a(n), b(n);
        long double sum_a = 0, sum_b = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sum_a=a[n-1];
        sum_b=b[n-1];
        if (sum_a < sum_b) {
            results.push_back('<');
        } else if (sum_a > sum_b) {
            results.push_back('>');
        } else if(sum_a==sum_b){
            results.push_back('=');
        }
    }

    for (char result : results) {
        cout << result;
    }

    return 0;
}