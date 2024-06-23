#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    vector<vector<int>> giftcount(50, vector<int>(50, 0));
    vector<int> giftpoint(50, 0);
    vector<int> answer(50, 0);

    for (int i = 0; i < gifts.size(); i++) {
        string input = gifts[i];
        stringstream ss(input);
        string give, take;

        ss >> give >> take;
        int g, t;
        for (int j = 0; j < friends.size(); j++) {
            if (friends[j] == give) g = j;
            if (friends[j] == take) t = j;
        }
        giftcount[g][t]++;
        giftpoint[g]++;
        giftpoint[t]--;
    }
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            if (giftcount[i][j] > giftcount[j][i]) answer[i]++;
            else if (giftcount[i][j] < giftcount[j][i]) answer[j]++;
            else if (giftcount[i][j] == giftcount[j][i]) {
                if (giftpoint[i] > giftpoint[j]) answer[i]++;
                else if (giftpoint[i] < giftpoint[j]) answer[j]++;
            }
        }
    }
    int max = -1;
    for (int i = 0; i < friends.size(); i++) {
        if (answer[i] > max) max = answer[i];
    }
    return max;
}