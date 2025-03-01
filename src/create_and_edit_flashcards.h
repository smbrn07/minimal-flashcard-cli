#ifndef CREATE_AND_EDIT_FLASHCARDS_H
#define CREATE_AND_EDIT_FLASHCARDS_H

#include <vector>
#include <string>
#include <utility>

using namespace std;

void printOption1();
void printOption2();
void editCard(vector<pair<string,string>> &file);
void runCreateNewDeck(vector<pair<string,string>> &file);
#endif