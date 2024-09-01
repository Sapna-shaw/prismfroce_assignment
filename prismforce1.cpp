 #include <bits/stdc++.h>

using namespace std;

const int max_enemies = 11; 

int power;          


bool canCrossChakrvyuha(vector<int>& enemyPower, int enemy, int cur_power, int behind, int skips, int recharge)
{
    
    if (enemy == max_enemies)
        return true;

    bool flag = false;

    
    if (recharge > 0 && cur_power < power)
        flag |= canCrossChakrvyuha(enemyPower, enemy, power, behind, skips, recharge - 1);

    
    if (cur_power >= behind)
    {
        cur_power -= behind;
        behind = 0;
    }
    else
        return false;


    if (skips > 0)
        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power, behind, skips - 1, recharge);


    
    if (cur_power >= enemyPower[enemy])
    {
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        flag |= canCrossChakrvyuha(enemyPower, enemy + 1, cur_power - enemyPower[enemy], behind, skips, recharge);
    }

    return flag;
}

int main()
{
    vector<int> enemyPower(max_enemies); 

    for (int i = 0; i < max_enemies; i++)
        cin >> enemyPower[i];

    int a, b; 
    cin >> power >> a >> b;
    a = min(a, max_enemies);             
    b = min(b, max_enemies);             

    int behind = 0;             

    if (canCrossChakrvyuha(enemyPower, 0, power, behind, a, b))
        cout << "Abhimanyu can cross the Chakrvyuha" << endl;
    else
        cout << "Abhimanyu cannot cross the Chakrvyuha" << endl;

    return 0;
}

//Test case: 1 

// max_enemies = 11
// enemyPower = {1, 10, 2, 7, 9, 0, 6, 3, 8, 4, 5}
// power = 9
// a = 8 
// b = 5
// Answer: Abhimanyu can cross the Chakrvyuha

// Test case: 2

// max_enemies = 11
// enemyPower = {0, 10, 2, 3, 9, 5, 6, 7, 8, 4, 7}
// power = 5
// a = 5
// b = 3
// Answer: Abhimanyu cannot cross the Chakrvyuha