// solved

// simple iteration

#include <iostream>
using namespace std;

int H[105];

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        for (int j = 1; j <= N; j++)
            cin >> H[j];
        int peaks = 0;
        for (int j = 2; j <= N-1; j++)
            if (H[j] > H[j-1] && H[j] > H[j+1])
                peaks++;
        cout << "Case #" << i << ": " << peaks << '\n';
    }
    return 0;
}