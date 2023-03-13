#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <vector>
#include <string>
#include <cmath>

using namespace std;

class BloomFilter {
public:
    BloomFilter(int m, int k);
    void insert(const string& element);
    string search(const string& element);
    void print_data();

private:
    int m;
    int k;
    vector<int> data;
    int n;

    int h1(const string& w);
    int h2(const string& w);
};

#endif // BLOOM_FILTER_H
