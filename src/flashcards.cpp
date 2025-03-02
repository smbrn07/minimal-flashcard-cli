#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, string> Flashcard;

void showMainMenu() {
    cout << "[1]: Tạo thẻ mới" << endl;
    cout << "[2]: Sửa thẻ đã tạo" << endl;
    cout << "[3]: Thoát" << endl;
}

void showEditMenu() {
    cout << "[1]: Tiếp tục chỉnh sửa" << endl;
    cout << "[2]: Thoát" << endl;
}

void editFlashcards(vector<Flashcard> &flashcards) {
    if (flashcards.empty()) {
        cout << "Không có thẻ nào để sửa!" << endl;
        return;
    }
    while (true) {
        cout << "Danh sách thẻ:" << endl;
        for (size_t i = 0; i < flashcards.size(); ++i) {
            cout << "[" << i + 1 << "] " << flashcards[i].first << ": " << flashcards[i].second << endl;
        }

        cout << "Nhập số thứ tự của thẻ cần sửa: ";
        int index;
        cin >> index;
        
        if (index < 1 || index > flashcards.size()) {
            cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại." << endl;
            continue;
        }

        cout << "Nhập nội dung mới cho mặt trước: ";
        cin.ignore();
        getline(cin, flashcards[index - 1].first);
        
        cout << "Nhập nội dung mới cho mặt sau: ";
        getline(cin, flashcards[index - 1].second);

        cout << "Thẻ đã được cập nhật: " << flashcards[index - 1].first << ": " << flashcards[index - 1].second << endl;
        
        showEditMenu();
        string choice;
        cin >> choice;
        
        if (choice == "2") break;
    }
}

void manageFlashcards(vector<Flashcard> &flashcards) {
    while (true) {
        showMainMenu();
        string choice;
        cin >> choice;

        if (choice == "3") break;
        else if (choice == "2") {
            editFlashcards(flashcards);
        } else if (choice == "1") {
            Flashcard newCard;
            cout << "Mặt trước của thẻ: ";
            cin.ignore();
            getline(cin, newCard.first);

            cout << "Mặt sau của thẻ: ";
            getline(cin, newCard.second);

            flashcards.push_back(newCard);
            cout << "Thẻ mới đã được tạo: " << newCard.first << ": " << newCard.second << endl;
        } else {
            cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại." << endl;
        }
    }
}
