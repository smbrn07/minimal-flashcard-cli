// tao thẻ mới, sửa thẻ đã tạo
#include <iostream>
#include <vector>
#include "create_and_edit_flashcards.h"
using namespace std;

string state;
string frontSide, backSide;

void printOption1() {
    cout << "[1]: tạo thẻ mới" << endl;
    cout << "[2]: sửa thẻ đã tạo" << endl;
    cout << "[3]: thoát" << endl;
}

void printOption2() {
    cout << "[1]: tiếp tục chỉnh sửa" << endl;
    cout << "[2]: thoát" << endl;
}

void editCard(vector<pair<string, string>> &file) {
    while (true) {
        for (int i = 1; i <= file.size(); ++i) {
            cout <<'['<<i<<']'<<file[i - 1].first<<": "<<file[i-1].second<<endl;
        }
        cout << "Nhập số thứ tự của thẻ cần sửa: " << endl;
        int index; cin >> index;
        cout << "Mặt trước của thẻ: " << endl;
        cin >> file[index-1].first;
        cout << "Mặt sau của thẻ: " << endl;
        cin >> file[index-1].second;
        cout << "Thẻ đã được sửa: "<< file[index-1].first << ": " << file[index-1].second << endl;
        printOption2();
        cin >> state;
        while (state!="1" && state!="2") {
            cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại: " << endl;
            cin >> state;
        }
        if (state == "2") {
            break;
        }
    }
}

void runCreateNewDeck(vector<pair<string, string>> &file) {

    while (true) {
        printOption1();
        cin >> state;
        while (state!="1" && state!="2" && state!="3") {
            cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại: ";
            cin >> state;
        }
        if (state == "3") {
            break;
            //Return to the homepage
        }
        else if (state == "2") {
            editCard(file);
        }
        else {
            cout << "Mặt trước của thẻ: ";
            cin >> frontSide;
            cout << "Mặt sau của thẻ: ";
            cin >> backSide;
            cout << "Thẻ mới đã được tạo: " << frontSide << ": " << backSide << endl;
            file.push_back({frontSide, backSide});
        }
    }
}