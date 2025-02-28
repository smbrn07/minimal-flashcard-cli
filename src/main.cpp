#include <iostream>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void showFlashcardWithBorder() {
    cout << CYAN << BOLD << R"(
  +-----------------------------------------------------------------------------+
  |                                                                             |
  |                        Welcome to Minimal Flashcard.                        |
  |                                                                             |
  +-----------------------------------------------------------------------------+
  |   [1] ...                                                                   |
  |   [2] ...                                                                   |
  |   [3] ...                                                                   |
  |   [4] ...                                                                   |
  |   [5] ...                                                                   |
  |   [6] ...                                                                   |
  |                                                                             |
  +-----------------------------------------------------------------------------+
)" << RESET << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    showFlashcardWithBorder();

    // while (true) {
    //     cout << "\nCommands: add, list, study, exit\n";
    //     cout << "Enter command: ";
    //     string command;
    //     cin >> command;

    //     if (command == "add") {
    //         manager.addFlashcard();
    //     } else if (command == "list") {
    //         manager.listFlashcards();
    //     } else if (command == "study") {
    //         session.start();
    //     } else if (command == "exit") {
    //         cout << "Goodbye!\n";
    //         break;
    //     } else {
    //         cout << "Unknown command.\n";
    //     }
    // }
    int n;
    cin >> n;
}