#include <fstream>

int main(void) {
    std::ofstream fo("bigInput");

    int N = 10;
    int M = N * (N - 1) / 2;
    fo << N << " " << M << "\n";
    for(int i = 1; i < N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            fo << i << " " << j << "\n";
        }
    }
}