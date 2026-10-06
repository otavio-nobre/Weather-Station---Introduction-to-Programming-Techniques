#include <stdio.h>

int main() {
    int n, b;

    if (scanf("%d %d", &n, &b) != 2) return 0;

    long long min_temp = 0;
    long long max_temp = 0;

    for (int i = 0; i < n; i++) {
        char bits[65];
        scanf("%s", bits);

        long long value = 0;
        for (int j = 0; j < b; j++) {
            if (bits[j] == '1') {
                if (j == 0) {
                    value -= (1LL << (b - 1));
                } else {
                    value += (1LL << (b - 1 - j));
                }
            }
        }

        printf("%lld\n", value);

        if (i == 0) {
            min_temp = value;
            max_temp = value;
        } else {
            if (value < min_temp) {
                min_temp = value;
            }
            if (value > max_temp) {
                max_temp = value;
            }
        }
    }

    printf("Minima: %lld\n", min_temp);
    printf("Maxima: %lld\n", max_temp);

    return 0;
}
