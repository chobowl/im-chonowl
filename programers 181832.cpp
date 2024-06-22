#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    int direction = 0; // right = 0, down = 1, left = 2, up = 3
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    int put = 1;

    while (put <= n * n) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                answer[top][i] = put;
                put++;
                if (put > n * n) return answer;
            }
            top++;
            direction = 1;
        }
        else if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                answer[i][right] = put;
                put++;
                if (put > n * n) return answer;
            }
            right--;
            direction = 2;
        }
        else if (direction == 2) {
            for (int i = right; i >= left; i--) {
                answer[bottom][i] = put;
                put++;
                if (put > n * n) return answer;
            }
            bottom--;
            direction = 3;
        }
        else if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                answer[i][left] = put;
                put++;
                if (put > n * n) return answer;
            }
            left++;
            direction = 0;
        }
    }

    return answer;
}
