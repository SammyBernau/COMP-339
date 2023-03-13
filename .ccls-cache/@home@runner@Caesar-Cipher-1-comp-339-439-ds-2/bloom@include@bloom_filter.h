#include <string>
using namespace std;

#ifndef BloomFilter_H
#define BloomFilter_H

class BloomFilter;

class BloomFilter {
public:
    void insert(const string&);
    void search(const string&);
};

#endif 
