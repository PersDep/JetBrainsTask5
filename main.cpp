#include <iostream>
#include <vector>

using namespace std;

int main() {
    int start = 0;
    int globalLength = 0;
    int n = 1000000;

    vector<int> cachedLengths(n, -1);
    cachedLengths[1] = 1;

    for (int i = 2; i < n; ++i) {
        long long sequence = i;
        int localLength = 0;

        while (sequence != 1 && sequence >= i) {
            localLength++;

            if (!(sequence % 2))
                sequence /= 2;
            else
                (sequence *= 3) += 1;
        }
        cachedLengths[i] = localLength + cachedLengths[sequence];

        if (cachedLengths[i] > globalLength) {
            globalLength = cachedLengths[i];
            start = i;
        }
    }

    cout << start << endl;

    return 0;
}