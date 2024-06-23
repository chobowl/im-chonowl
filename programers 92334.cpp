#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> troll(id_list.size(), 0);
    vector<int> answer(id_list.size(), 0);
    vector<vector<int>> givecheck(id_list.size(), vector<int>(id_list.size(), 0));
    for (int i = 0; i < report.size(); i++) {
        string input = report[i];
        stringstream ss(input);
        string give, take;

        ss >> give >> take;
        int g, t;
        for (int j = 0; j < id_list.size(); j++) {
            if (id_list[j] == give) g = j;
            if (id_list[j] == take) t = j;
        }
        if (givecheck[g][t] == 0) {
            troll[t]++;
            givecheck[g][t] = 1;
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (troll[i] >= k) {
            for (int j = 0; j < id_list.size(); j++) {
                if (givecheck[j][i] == 1) answer[j]++;
            }
        }
    }

    return answer;
}