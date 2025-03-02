#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "decks.cpp"
#include "study.cpp"
#include "flashcards.cpp"

void showGetStarted() {
    cout << "[0]: Quay lại" << endl;
    cout << "[1]: Học" << endl;
    cout << "[2]: Xem bộ thẻ đã tạo" << endl;
    cout << "[3]: Tạo bộ thẻ mới" << endl;
    cout << "[4]: Tạo bộ thẻ từ file" << endl;
}

bool choosingDecksStudy() {
    // Chon bo the de hoc
    string deckName = listAllDecks();
    // state = 1 -> recursion getStarted();
    if (deckName == "") return 1;
    cout << deckName << endl;
    vector<pair<string,string>> file = readDeck(deckName);
    studyCards(file, deckName);
    if (deckName == "") choosingDecksStudy();
    return 0;
}

bool choosingDecksEdit() {
    // Xem bộ thẻ đã tạo
    string deckName = listAllDecks();
    if (deckName == "") return 1;
    cout << deckName << endl;
    vector<pair<string,string>> previous_file = readDeck(deckName);
    manageFlashcards(previous_file);
    writeDeck(deckName, previous_file);
    return 0;
}

bool creatingNewDeck() {
    // Tạo bộ thẻ mới
    cout << "Nhập tên bộ thẻ: ";
    string deckName;
    cin >> deckName;
    createNewDeck(deckName);
    vector<pair<string, string>> file;
    return manageFlashcards(file);
    // writeDeck(deckName, file);
}

void getStarted() {
    showGetStarted();

    string state; cin >> state;
    if (state=="1" && choosingDecksStudy()) getStarted();
    else if (state=="2" && choosingDecksEdit()) getStarted();
    else if (state=="3" && creatingNewDeck()) getStarted();
    else if (state == "4") {
      // Nhap the tu file
    }
}