#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int continu = 0;
    int attack_time = 0;
    int full_hp = health;
    int fs = attacks.size();
    for (int i = 1; i <= attacks[fs - 1][0]; i++) {
        if (attacks[attack_time][0] == i) {
            health -= attacks[attack_time][1];
            continu = 0;
            continu++;
            attack_time++;
            if (health <= 0) return -1;
        }
        else if (health >= full_hp) {
            if (continu == bandage[0]) continu = 0;
            continu++;
        }
        else if (health < full_hp) {
            health += bandage[1];
            if (health >= full_hp) health = full_hp;
            if (continu == bandage[0]) {
                continu = 0;
                health += bandage[2];
                if (health >= full_hp) health = full_hp;
            }
            continu++;
        }
    }
    return health;
}