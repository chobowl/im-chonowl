#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char same_st;
    while (1) {
        if (s.length() == 0) break;
        same_st = s.front();
        int same_count = 1;
        int dif_count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == same_st) same_count++;
            else dif_count++;
            if (same_count == dif_count) break;
        }
        answer++;
        s.erase(0, dif_count + same_count);
    }
    return answer;
}