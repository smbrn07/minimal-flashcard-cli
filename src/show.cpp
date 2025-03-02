
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void showWelcomePage() {
    cout << R"(
  ╔═════════════════════════════════════════════════════════════════════════════╗
  ║                                                                             ║
  ║   ███████╗██╗      █████╗ ███████╗██╗  ██╗ ██████╗ █████╗ ██████╗ ██████╗   ║
  ║   ██╔════╝██║     ██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗██╔══██╗██╔══██╗  ║
  ║   █████╗  ██║     ███████║███████╗███████║██║     ███████║██████╔╝██║  ██║  ║
  ║   ██╔══╝  ██║     ██╔══██║╚════██║██╔══██║██║     ██╔══██║██╔══██╗██║  ██║  ║
  ║   ██║     ███████╗██║  ██║███████║██║  ██║╚██████╗██║  ██║██║  ██║██████╔╝  ║
  ║   ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝   ║
  ║                                                                             ║
  ║   [1] Bắt đầu                                                               ║
  ║   [2] Thống kê                                                              ║
  ║   [3] Cài đặt                                                               ║
  ║   [4] Thoát                                                                 ║
  ║                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════╝
)";
}

void showGetStarted() {
    cout << R"(
  ╔═════════════════════════════════════════════════════════════════════════════╗
  ║                                                                             ║
  ║   ███████╗██╗      █████╗ ███████╗██╗  ██╗ ██████╗ █████╗ ██████╗ ██████╗   ║
  ║   ██╔════╝██║     ██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗██╔══██╗██╔══██╗  ║
  ║   █████╗  ██║     ███████║███████╗███████║██║     ███████║██████╔╝██║  ██║  ║
  ║   ██╔══╝  ██║     ██╔══██║╚════██║██╔══██║██║     ██╔══██║██╔══██╗██║  ██║  ║
  ║   ██║     ███████╗██║  ██║███████║██║  ██║╚██████╗██║  ██║██║  ██║██████╔╝  ║
  ║   ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝   ║
  ║                                                                             ║
  ║   [1] Học thẻ                                                               ║
  ║   [2] Xem bộ thẻ đã tạo                                                     ║
  ║   [3] Tạo bộ thẻ mới                                                        ║
  ║   [4] Tạo bộ thẻ từ file                                                    ║
  ║                                                                             ║
  ╚═════════════════════════════════════════════════════════════════════════════╝
)";
}

string showAllDecks()
{
  //temporary list for choosing decks
  vector<string> listchoices;
  
  cout << "Danh sách các bộ thẻ: " << endl;
  // đánh số thứ tự các bộ thẻ
  int cnt = 0;
  string path = "../data/decks";
  // quay lai trang chinh
  cout << '['<<0<<"]. " << "Quay lại" << endl;
  for (const auto & entry : fs::directory_iterator(path)) {
      ++cnt;
      cout <<'['<<cnt<<"]. " << entry.path().filename() << endl;
      // convert entry.path().filename() to string and push to listchoices
      listchoices.push_back(entry.path().filename().string());
  }
  cout << "Nhập số thứ tự của bộ thẻ cần chọn: ";
  int choice; cin >> choice;
  while (choice < 1 || choice > cnt) {
      cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại: ";
      cin >> choice;
  }
  if (choice == 0) return "0";
  return listchoices[--choice];
}