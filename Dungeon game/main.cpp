#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int healthPotion = 0;
int manaPotion = 0;
int playerHealth = 50, playerMana = 50;

void PrintIntroGame(){
    cout << "------------------------\n";
    cout << "Welcome to Dungeon Game!\n";
    cout << "------------------------\n";
}

void PrintGameOptions(){
    cout << "\nChoose an action:\n";
    cout << "\n1) Show Player Stats\n";
    cout << "2) Show Inventory\n";
    cout << "3) Open Chest\n";
    cout << "4) Use an Item\n";
    cout << "5) Quit Game\n";
}

void PrintPlayerStats(int playerHealth, int playerMana){
    cout << "-------------\n";
    cout << "Player Stats\n";
    cout << "-------------\n";
    cout << "Health: " << playerHealth << endl;
    cout << "  Mana: " << playerMana << endl;
    cout << "-------------\n";
}

void PrintPlayerInventory(int healthPotion, int manaPotion){
    cout << "----------------\n";
    cout << "Player Inventory\n";
    cout << "----------------\n";
    cout << "Health Potion: " << healthPotion << endl;
    cout << "Mana Potion: " << manaPotion << endl;
    cout << "----------------\n";
}

string OpenChestPrintItem(){
    srand(time(0));
    int chest = 1 + rand() % 3;

    if(chest == 1){
        manaPotion++;
        return  "--------------------------------\n"
                "You found a Mana Potion! Hooray!\n"
                "--------------------------------\n";
    }else if(chest == 2){
        healthPotion++;
        return  "--------------------------------\n"
                "You found a Health Potion! Hooray!\n"
                "--------------------------------\n";

    }else{
        return  "-----------------\n"
                "No item found....\n"
                "-----------------\n";
    }
}

string ChooseItemsToUse(){

    int item;
    cout << "\n---------------------\n";
    cout << "Choose an Item to Use\n";
    cout << "---------------------\n";
    cout << "1) Health Potion\n";
    cout << "2) Mana Potion\n";
    cout << "---------------------\n";
    cout << "Enter Item Number: ";
    cin >> item;

    if(item == 1){
        if(healthPotion == 0){
        return  "\n---------------------------------------------------------\n"
                "You don't have enough Health Potions in your Inventory...\n"
                "---------------------------------------------------------\n";
        }else{
            healthPotion--;
            playerHealth += 25;
            return  "\n-----------\n"
                    " +25 Health\n"
                    "-----------\n";
        }
    }else if(item == 2){
        if(manaPotion == 0){
        return  "\n---------------------------------------------------------\n"
                "You don't have enough Mana Potions in your Inventory...\n"
                "---------------------------------------------------------\n";
        }else{
            playerMana += 25;
            manaPotion--;
            return  "\n-----------\n"
                    " +25 Mana\n"
                    "-----------\n";
        }
    }
}



int main(){
    int choice;
    bool isNotDone = true;

    PrintIntroGame();

    while(isNotDone){
        PrintGameOptions();
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                PrintPlayerStats(playerHealth, playerMana);
                break;

            case 2:
                PrintPlayerInventory(healthPotion, manaPotion);
                break;

            case 3:
                cout << OpenChestPrintItem();
                break;

            case 4:
                cout << ChooseItemsToUse();
                break;

            case 5:
                cout << "\n--------------------\n";
                cout << "Thank you goodbye...\n";
                cout << "--------------------\n";
                isNotDone = false;
                break;
        }
    }

    return 0;
}
