#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class BloomFilter {
public:
  BloomFilter(int m, int k);
  void insert(const string &word);
  double search(const string &word);
  void print_data();
  int get_size();
  int get_collisions();

private:
  int m;
  int k;
  vector<int> data;
  int num_of_inserts;
  int collisions;

  int sha256(const string &w);
  int sha512(const string &w);
};

#endif // BLOOM_FILTER_H
