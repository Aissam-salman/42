#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void move(int id, int x, int y) {
	cout << "MOVE " << id << " " << x << " " << y << endl; 
}

void harvest(int id) {
	cout << "harvest " << id  << endl; 
}

void drop(int id) {
	cout << "DROP " << id  << endl; 
}

void wait(void) {
	cout << "WAIT" << endl;
}


int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
    }

    // game loop
    while (1) {
        for (int i = 0; i < 2; i++) {
            int plum;
            int lemon;
            int apple;
            int banana;
            int iron;
            int wood;
            cin >> plum >> lemon >> apple >> banana >> iron >> wood; cin.ignore();
        }
        int trees_count;
        cin >> trees_count; cin.ignore();
        int trees[trees_count][6];
        for (int i = 0; i < trees_count; i++) {
            string type;
            int x;
            int y;
            int size;
            int health;
            int fruits;
            int cooldown;
            cin >> type >> x >> y >> size >> health >> fruits >> cooldown; cin.ignore();
            trees[i][0] = x;
            trees[i][1] = y;
            trees[i][2] = size;
            trees[i][3] = health;
            trees[i][4] = fruits;
            trees[i][5] = cooldown;

        }
        int trolls_count;
        cin >> trolls_count; cin.ignore();
        int troll[trolls_count][14];
        for (int i = 0; i < trolls_count; i++) {
            int id;
            int player;
            int x;
            int y;
            int movement_speed;
            int carry_capacity;
            int harvest_power;
            int chop_power;
            int carry_plum;
            int carry_lemon;
            int carry_apple;
            int carry_banana;
            int carry_iron;
            int carry_wood;
            cin >> id >> player >> x >> y >> movement_speed >> carry_capacity >> harvest_power >> chop_power >> carry_plum >> carry_lemon >> carry_apple >> carry_banana >> carry_iron >> carry_wood; cin.ignore();
            if (player == 0) {
                troll[i][0] = id;
                troll[i][1] = player;
                troll[i][2] = x;
                troll[i][3] = y;
                troll[i][4] = movement_speed;
                troll[i][5] = carry_capacity;
                troll[i][6] = harvest_power;
                troll[i][7] = chop_power;
                troll[i][8] = carry_plum;
                troll[i][9] = carry_lemon;
                troll[i][10] = carry_apple;
                troll[i][11] = carry_iron;
                troll[i][12] = carry_wood;
                troll[i][13] = player;
            }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cerr << "Debug messages..." << trees_count << endl;
        // valid actions:
        // MOVE <id> <x> <y>
        // HARVEST <id> - when you are on the same cell as a tree
        // DROP <id> - when you are next to your shack and carry items
        cout << "MOVE 0 7 7" << endl;

				for(int i = 0; i < trees_count; i++) {
					for(int j = 0; j < trolls_count; j++) {
						if (troll[i][1] == 0)
							goBack(trees[i][0], trees[i][1], troll[j][2], troll[j][2], troll[j][0]);
					}
				}
    }
}
