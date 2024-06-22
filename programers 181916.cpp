#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d) {
    int check[7] = {};
    int answer = 0;
    int e = 0, f = 0, g = 0, h = 0;
    check[a]++;
    check[b]++;
    check[c]++;
    check[d]++;
    for (int i = 1; i < 7; i++) {
        if (check[i] == 4) {
            answer = 1111 * i;
        }
        else if (check[i] == 3) {
            for (int j = 1; j < 7; j++) {
                if (check[j] == 1) answer = (10 * i + j) * (10 * i + j);
            }
        }
        else if (check[i] == 2) {
            int f = 0;
            int s = 0;
            for (int j = 1; j < 7; j++) {
                if (check[j] == 2 && j != i) {
                    int tmp = j - i;
                    if (tmp < 0) tmp = i - j;
                    answer = (j + i) * tmp;
                }
                if (check[j] == 1) {
                    if (f == 0) f = j;
                    else if (f != 0) s = j;
                }
            }
            if (f != 0 || s != 0) answer = f * s;
        }
        else if (check[i] == 1) {
            if (e == 0) e = i;
            else if (f == 0) f = i;
            else if (g == 0) g = i;
            else if (h == 0) answer = e;
        }
    }
    return answer;
}