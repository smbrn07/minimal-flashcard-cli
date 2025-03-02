#include <iostream>
#include <vector>
#include <string>

void frontSideStudy() {
    cout << "[1]. Lật thẻ" << endl;
    cout << "[2]. Quay lại" << endl;
}
  
void backSideStudy() {
    cout << "[1]. Tệ" << endl;
    cout << "[2]. Vừa" << endl;
    cout << "[3]. Tốt" << endl;
    cout << "[4]. Xuất Sắc" << endl;
}

void studyCards(vector<pair<string,string>> &decks, string &deckName) {
    if (decks.empty()) {
        cout << "Không có thẻ nào để học!" << endl;
        return;
    }
    for (auto deck : decks) {
        cout << "[-]  " << deck.first << endl;
        frontSideStudy();
        string state; cin >> state;
        if (state == "2") {
            deckName = "";
            break;
        }
        cout << "[-]  " << deck.second << endl;
        backSideStudy();
        cin >> state;
        // process state

    }
}