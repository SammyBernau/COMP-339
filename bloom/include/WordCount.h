#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

class WordCount {
public:
    WordCount(){};
    void insert(const string& word);
    int get_size();
    bool contains(const string& word);

private:
    set<int> words;

    int h1(const string& w);
    int h2(const string& w);
};

#endif 