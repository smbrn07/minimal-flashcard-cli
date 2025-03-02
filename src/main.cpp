#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "show.cpp"
#include "decks.cpp"
#include "flashcards.cpp"
#include "settings.cpp"

using namespace std;

vector<pair<string, string>> file;

int main() {
    while (true) {
      showWelcomePage();
      string state; cin >> state;
      if (state == "1") {

        showGetStarted();

        cin >> state;
        if (state == "1") {
          // Học thẻ
          string deckName = showAllDecks();
          cout << deckName << endl;
          if (deckName == "0") continue;
        }
        else if (state == "2") {
          // Xem bộ thẻ đã tạo
          string deckName = showAllDecks();
          cout << deckName << endl;
          if (deckName == "0") continue;

          vector<pair<string,string>> previous_file = readDeck(deckName);
          manageFlashcards(previous_file);
          writeDeck(deckName, previous_file);
        }
        else if (state == "3") {
          // Tạo bộ thẻ mới
          cout << "Nhập tên bộ thẻ: ";

          string deckName;
          cin >> deckName;

          createNewDeck(deckName);
          vector<pair<string, string>> file;
          manageFlashcards(file);
          // writeDeck(deckName, file);
        }
        else if (state == "4") {
          // Nhap the tu file
        }
      } else if (state == "3") {
        settingsMenu();
      } 
      else if (state == "4") break;
    }
}