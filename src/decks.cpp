#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>

using namespace std;

bool fileExists(const string &filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

// Create a new deck file ../data/decks/<deckName>.txt 
void createNewDeck(string deckName) {
    string filePath = "../data/decks/" + deckName + ".txt";

    if (fileExists(filePath)) {
        cout << "Lỗi: Bộ thẻ \"" << deckName << "\" đã tồn tại! Bạn có muốn ghi đè lên file này chứ?" << endl;
        cout << "[y/n]: Để ghi đè/hủy.]" << endl;
        string choice; cin >> choice;
        if (choice == "n") return;
        else if (choice != "y") {
            cout << "Lựa chọn không hợp lệ! Hủy tạo bộ thẻ!" << endl;
            return;
        }
    }

    ofstream file(filePath);
    if (!file) {
        cerr << "Lỗi: Không thể tạo tập tin!" << endl;
        return;
    }

    file.close();
    cout << "Bộ thẻ \"" << deckName << "\" đã tạo xong!" << endl;
}

//Read deck file ../data/decks/<deckName>.txt and store in a vector
vector<pair<string, string>> readDeck(string deckName) {
    vector<pair<string, string>> file;

    // deckName includes ".txt"
    string path = "../data/decks/" + deckName;
    ifstream fin(path);
    
    string frontSide, backSide;
    // Flashcard format: 
    // frontSide: backSide
    while (getline(fin, frontSide, ':') && getline(fin, backSide)) {
        file.push_back({frontSide, backSide});
    }
    fin.close();
    return file;
}

//Write file from vector to ../data/decks/<deckName>.txt
void writeDeck(string deckName, vector<pair<string, string>> &file) {
    string path = "../data/decks/" + deckName;
    ofstream fout(path);
    for (auto i : file) {
        fout << i.first << ":" << i.second << endl;
    }
    fout.close();
}