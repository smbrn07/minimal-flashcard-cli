#include <fstream>
#include <iostream>
#include <sys/stat.h> // For checking file existence

using namespace std;

// Function to check if a file exists
bool fileExists(const string &filePath) {
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0);
}

void createNewDeck(string deckName) {
    string filePath = "../data/decks/" + deckName + ".txt";

    if (fileExists(filePath)) {
        cout << "Lỗi: Bộ thẻ \"" << deckName << "\" đã tồn tại!" << endl;
        return;
    }

    ofstream file(filePath);
    if (!file) {
        cerr << "Lỗi: Không thể tạo tập tin!" << endl;
        return;
    }

    file.close();
    cout << "Bộ thẻ \"" << deckName << "\" đã tạo xong!" << endl;
}