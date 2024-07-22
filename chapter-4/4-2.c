#include <stdio.h>
#include <ctype.h>

/* Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6 */

// ctype contains functions for string manipulation
teなに
double atof(char s[]) {
    double val, power;
    int i, sign;

    // skip whitespace
    for (i = 0; isspace(s[i]); i++);

    // ternary check for negative sign
    sign = (s[i] == '-') ? -1 : 1;

    // if prefix sign, skip it
    if (s[i] == "+" || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10; 
    }

    if (s[i] == 'e' || s[i] == 'E') {
        // first we grab the sign
        i++;
        // ternary check for negative sign
        int e_sign = (s[i] == '-') ? -1 : 1;

        // if prefix sign, skip it
        if (s[i] == "+" || s[i] == '-') {
            i++;
        }
        int e_power;
        for (e_power = 0.0; isdigit(s[i]); i++) {
            e_power = 10.0 * e_power + s[i] - '0';
        }
        double res = sign * val / power;
        if (e_sign == -1) {
            int j;
            for (j = 0; j < e_power; j++) {
                res = res / 10;
            }
        } else {
            int j;
            for (j = 0; j < e_power; j++) {
                res *= 10.0;
            }
        }
        return res;
    }
    return sign * val / power;
}

int main() {
    printf("%.10f\n", atof("123.45e-6"));
    printf("%f\n", atof("124.55"));
    return 0;
}