#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "show.cpp"
#include "settings.cpp"
#include "getstarted.cpp"

using namespace std;

int main() {
  while (true) {
    showWelcomePage();

    string state; cin >> state;
    if (state == "1") {
      getStarted();
    } 
    else if (state == "2") {
      break;
      //Thống kê
    } 
    else if (state == "3") {
      settingsMenu();
    } 
    else if (state == "4") break;
  }
}