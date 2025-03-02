#include <iostream>
using namespace std;

void settingsMenu() {
    string choice;
    
    while (true) {
        cout << "[0]: Quay lại" << endl;
        cout << "[1]: Ngôn ngữ" << endl;
        cout << "[2]: Xóa dữ liệu" << " (W.I.P)" << endl; //W.I.P
        cout << "[3]: Đóng góp" << endl;
        
        cout << "Chọn một tùy chọn: ";
        cin >> choice;

        if (choice == "0") {
            break;
        } 
        else if (choice == "1") {
            string langChoice;
            cout << "[1]: English" << endl;
            cout << "[2]: Tiếng Việt" << endl;
            cout << "Chọn ngôn ngữ: ";
            cin >> langChoice;

            if (langChoice == "1") {
                cout << "Language set to English." << endl;
            } 
            else if (langChoice == "2") {
                cout << "Ngôn ngữ đã đặt thành Tiếng Việt." << endl;
            } 
            else {
                cout << "Lựa chọn không hợp lệ!" << endl;
            }
        } 
        else if (choice == "3") {
            cout << "Nguồn: https://github.com/smbrn07/minimal-flashcard-cli" << endl;
            cout << "Thực hiện: Bùi Hoàng Minh, Nguyễn Khánh Vinh" << endl;
            cout << "Kiểm thử: Vũ Minh Hải Đăng, Nguyễn Đức Duy Mạnh" << endl;
        } 
        else {
            cout << "Lựa chọn không hợp lệ!" << endl;
        }
    }
}
