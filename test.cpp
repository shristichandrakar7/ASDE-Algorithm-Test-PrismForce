#include <bits/stdc++.h>

using namespace std;

bool canCrossChakravyuha(int k[], int n, int p, int a, int b, bool enemiesPassed[], int cur, int power, vector<int>& recharge) {
    if (cur == n) {
        return true;
    }
    if (p < k[cur] && a == 0 && b == 0) {
        return false;
    }

    for (int i = cur; i < n; i++) {

        if (p < k[i] && a == 0 && b == 0) break;

        if (i >= 3 && recharge[0] == 0) {
            k[i] += k[2] / 2;
            recharge[0] = i;
        }

        if (i >= 7 && recharge[1] == 0) {
            k[i] += k[6] / 2;
            recharge[1] = i;
        }

        //cout << "i " << i << " k[i] " << k[i] << " n " << n << " p " << p << " a " << a  << " b " << b << " enemiesPassed " << enemiesPassed[i] << " cur " << cur << " power " << power << " recharge " << recharge[0] << " " << recharge[1] << endl;

        enemiesPassed[i] = true;
        if (p >= k[i]) {
            bool canFight = canCrossChakravyuha(k, n , p - k[i], a, b, enemiesPassed, i + 1, power, recharge);
            if (canFight) {
                return true;
            }
        }


        if (a > 0) {
            bool canSkip = canCrossChakravyuha(k, n, p, a - 1, b, enemiesPassed, i + 1, power, recharge);
            if (canSkip) {
                return true;
            }
        }

        if (b > 0) {
            bool canRecharge = canCrossChakravyuha(k, n, p + power , a, b - 1, enemiesPassed, i + 1, power, recharge);
            if (canRecharge) {
                return true;
            }
        }

        enemiesPassed[i] = false;
        if (i == recharge[0]) {
            k[recharge[0]] -= k[2] / 2;
            recharge[0] = 0;
        }
        if (i == recharge[1]) {
            k[recharge[1]] -= k[6] / 2;
            recharge[1] = 0;
        }
    }

    return false;
}

int main() {
    //Test case 1
    int k[] = {3, 2, 5, 1, 4, 7, 6, 8, 9, 2, 10};
    int n = sizeof(k) / sizeof(k[0]);

    int p = 4;
    int a = 0;
    int b = 0;
    int power = p;
    bool enemiesPassed[n];
    vector<int>recharge(2, 0);
    fill(enemiesPassed, enemiesPassed + n, false);
    if (canCrossChakravyuha(k, n, p, a, b, enemiesPassed, 0, power, recharge)) {
        cout << "Abhimanyu can cross the Chakravyuha!" << endl;
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuha." << endl;
    }


    //Test Case 2
    int k1[] = {3, 2, 5, 1, 4, 7, 6, 8, 9, 2, 10};
    int n1 = sizeof(k1) / sizeof(k1[0]);

    int p1 = 4;
    int a1 = 1;
    int b1 = 1;
    int power1 = p1;
    bool enemiesPassed1[n1];
    vector<int>recharge1(2, 0);
    fill(enemiesPassed1, enemiesPassed1 + n1, false);
    if (canCrossChakravyuha(k1, n1, p1, a1, b1, enemiesPassed1, 0, power1, recharge1)) {
        cout << "Abhimanyu can cross the Chakravyuha!" << endl;
    } else {
        cout << "Abhimanyu cannot cross the Chakravyuha." << endl;
    }

    return 0;
}
