#include <iostream>
#include <vector>
using namespace std;

int state; string frontSide, backSide;
vector<pair<string, string>> p;

void printOption() {
    cout << "[1]: tiếp tục" << endl;
    cout << "[2]: sửa thẻ đã tạo" << endl;
    cout << "[3]: thoát" << endl;
}

void EditCard() {
    for (int i = 1; i <= p.size(); ++i) {
        cout <<'['<<i<<']'<<p[i - 1].first<<": "<<p[i-1].second<<endl;
    }
    cout << "Nhập số thứ tự của thẻ cần sửa: " << endl;
    int index; cin >> index;
    cout << "Mặt trước của thẻ: " << endl;
    cin >> p[index-1].first;
    cout << "Mặt sau của thẻ: " << endl;
    cin >> p[index-1].second;
    printOption();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (true) {
        printOption();
        cin >> state;
        if (state == 3) {
            break;
            //Return to the homepage
        }

        if (state == 2) {
            EditCard();

        }

        cout << "Mặt trước của thẻ: " << endl;
        cin >> frontSide;
        cout << "Mặt sau của thẻ: " << endl;
        cin >> backSide;
        
        p.push_back({frontSide, backSide});
    }
}