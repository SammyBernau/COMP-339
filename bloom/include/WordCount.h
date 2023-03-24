#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <vector>
#include <string>
#include <cmath>

using namespace std;

class WordCount {
public:
    WordCount(int m, int k);
    void insert(const string& element);
    string search(const string& element);
    void print_data();
    int get_size();
    int get_collisions();

private:
    vector<int> data;
    int num_of_inserts;

    int h1(const string& w);
    int h2(const string& w);
};

#endif // BLOOM_FILTER_H