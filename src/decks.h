#ifndef DECKS_H
#define DECKS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <filesystem>

using namespace std;

bool fileExists(const string &filePath);
void createNewDeck(string deckName);
vector<pair<string, string>> readDeck(string deckName);
void writeDeck(string deckName, vector<pair<string, string>> &file);
string listAllDecks();

#endif
