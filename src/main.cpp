#include <iostream>
#include "show.cpp"
#include "create_new_deck.cpp"
#include "create_and_edit_flashcards.cpp"

using namespace std;

vector<pair<string, string>> file;

int main() {
    while (true) {
      showWelcomePage();
      string state; cin >> state;
      if (state == "1") {
        // Bat dau
        showGetStarted();
        cin >> state;
        if (state == "1") {
          runCreateNewDeck(file);
        }
        else if (state == "2") {
          // Tao bo the moi
          cout << "Nhập tên bộ thẻ: ";
          string deckName;
          cin >> deckName;
          createNewDeck(deckName);
        }
      }
      if (state == "4") break;
    }
}