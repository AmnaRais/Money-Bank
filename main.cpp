#include <iostream>
#include <windows.h>
#include <conio.h>
#include "console_utilis.h"
#include <limits>
#include "BST.h"
#include "BSTT.cpp"
#include "Context_Free_Grammar.h"
#include "Context_Free_Grammar.cpp"

using namespace std;

// // Define gotoxy function (Windows only)
// void gotoxy(int x, int y) {
//     COORD coord;
//     coord.X = x;
//     coord.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }

int main() {
    string input;
    int choice;
    int count;
    MenuDriven Menu;
    Menu.Intro();
    BinarySearchTree Tree;
    system("cls");

    do {
        cout << "\n\n\tPlease Select Between The Following Options!\n";
        cout << "\n\t1. Login\n"
             << "\t2. Sign Up\n"
             << "\t3. Exit\n";

        cout << "\n\n\tEnter your choice:\t";

        // Validate input
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\tINVALID ENTRY!\n";
            cout << "\tPLEASE ENTER A VALID NUMBER:\t";
        }

        switch (choice) {
            case 1: {
                // Login
                system("cls");
                cout << "\t\t\t***LOG IN***\n\n";

                if (Tree.Login()) {
                    cout << "\tLOGIN SUCCESSFUL...\n";
                    system("cls");
                    cout << "\t\t\t***GRAMMAR CHECKER!***\n\n";

                    do {
                        cout << "\nEnter sentence to check its grammar:\t";

                        // Use automatic allocation instead of 'new'
                        Context_Free_Grammar Machine;
                        Machine.Start_Program();

                        gotoxy(33, 27);
                        cout << "To re-enter a sentence press 1: ";
                        cin >> count;
                        system("cls");

                    } while (count == 1);

                } else {
                    cout << "\tCAN'T LOGIN!.\n";
                }

                gotoxy(1, 1);
                cout << "\n\nPress any key to go back to the main menu...\n";
                getch();
                break;
            }

            case 2:
                // Sign up
                system("cls");
                cout << "\t\t\t***SIGN UP***\n\n";
                Tree.SignUp();
                cout << "\nPress any key to go back to the main menu...\n";
                getch();
                break;

            case 3:
                // Exit
                exit(0);

            default:
                cout << "\n\tINVALID ENTRY!\n";
                cout << "\tPLEASE ENTER A VALID CHOICE (1-3)...";
                getch();
                break;
        }

        system("cls");
    } while (true);

    return 0;
}
