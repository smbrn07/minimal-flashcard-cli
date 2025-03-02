#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, string> Flashcard;

string Back = "3", Edit = "1", Remove = "2", EditorRemove = "2", Create = "1";

void showMainMenu() {
    cout << "[1]: Tạo thẻ mới" << endl;
    cout << "[2]: Sửa/Xóa thẻ đã tạo" << endl;
    cout << "[3]: Quay lại" << endl;
}

void showEditorRemoveMenuOptions() {
    cout << "[1]: Sửa thẻ" << endl;
    cout << "[2]: Xóa thẻ" << endl;
    cout << "[3]: Quay lại" << endl;
}

void listAllFlashcards(vector<Flashcard> flashcards) {
    cout << "Danh sách thẻ:" << endl;
        cout << "[0]. Quay lại" << endl;
        for (size_t i = 0; i < flashcards.size(); ++i) {
            cout << "[" << i + 1 << "]. " << flashcards[i].first << ": " << flashcards[i].second << endl;
        }
}

string editFlashcards(vector<Flashcard> &flashcards) {
    cout << "Nhập số thứ tự của thẻ cần sửa: ";
    int index;
    cin >> index;

    if (index == 0) return Back;
    
    while (index < 0 || index > flashcards.size()) {
        cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại." << endl;
        cin >> index;
    }

    cout << "Nhập nội dung mới cho mặt trước: ";
    cin.ignore();
    getline(cin, flashcards[index - 1].first);
    
    cout << "Nhập nội dung mới cho mặt sau: ";
    getline(cin, flashcards[index - 1].second);

    cout << "Thẻ đã được cập nhật: " << flashcards[index - 1].first << ": " << flashcards[index - 1].second << endl;

    return Edit;
}

string removeFlashcards(vector<Flashcard> &flashcards) {
    cout << "Nhập số thứ tự của thẻ cần xóa: ";
    int index;
    cin >> index;
    if (index == 0) return Back;
    while (index < 0 || index > flashcards.size()) {
        cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại." << endl;
        continue;
    }

    cout << "Thẻ đã được xóa: " << flashcards[index - 1].first << ": " << flashcards[index - 1].second << endl;
    flashcards.erase(flashcards.begin() + index - 1);
    return Remove;
}

void edit_removeFlashcards(vector<Flashcard> &flashcards, string state) {
    if (flashcards.empty()) {
        cout << "Không có thẻ nào để sửa!" << endl;
        return;
    }

    while (state != Back) {
        listAllFlashcards(flashcards);
        state == Edit ? state=editFlashcards(flashcards) : state=removeFlashcards(flashcards);
    }
}


bool manageFlashcards(vector<Flashcard> &flashcards) {
    while (true) {
        showMainMenu();
        string choice;
        cin >> choice;
        // Quay lại
        if (choice == Back) return 1;
        else if (choice == EditorRemove) {
            showEditorRemoveMenuOptions();
            cin >> choice;
            edit_removeFlashcards(flashcards, choice == Edit ? Edit : Remove);
        } else if (choice == Create) {
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
    return 0;
}
