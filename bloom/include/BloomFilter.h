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
    int get_size();
    int get_collisions();

private:
    int m;
    int k;
    vector<int> data;
    int num_of_inserts;
    int collisions;
    
    int sha256(const string& w);
    //int sha384(const string& w);
    int sha512(const string& input_str);
};

#endif // BLOOM_FILTER_H
