//This is the word count app that will use hash functions concatenated together to create a unique ID for each word entered
//Probably will use three hash functions to do this

// #include "../include/WordCount.h"
// #include <iomanip>
// #include <iostream>
// #include <openssl/md5.h>
// #include <openssl/sha.h>
// #include <sstream>
// using namespace std;

// WordCount::WordCount(int m, int k)
//     : m(m), k(k), data(m), num_of_inserts(0), collisions(0) {}

// int BloomFilter::get_size() { return num_of_inserts; }
// int BloomFilter::get_collisions() {return collisions;}

// void BloomFilter::insert(const string &element) {

//   if (k == 1) {
//     int hash1 = h1(element) % m;

//     if (data[hash1] == 1) {
//       collisions++;
//     }
//     data[hash1] = 1;
    
//   } else if (k == 2) {
//     int hash1 = h1(element) % m;
//     int hash2 = h2(element) % m;
    
//     if (data[hash1] == 1 && data[hash2] == 1) {
//       collisions++;
//     }
    
//     data[hash1] = 1;
//     data[hash2] = 1;
//   }
//   num_of_inserts ++;
// }

// string BloomFilter::search(const string &element) {
//   if (k == 1) {
//     int hash1 = h1(element) % m;
//     if (data[hash1] == 0) {
//       return "Not in Bloom Filter";
//     }
//   } else if (k == 2) {
//     int hash1 = h1(element) % m;
//     int hash2 = h2(element) % m;
//     if (data[hash1] == 0 || data[hash2] == 0) {
//       return "Not in Bloom Filter";
//     }
//   }
//   double prob = pow(1.0 - pow(1.0 - 1.0 / m, k * num_of_inserts), k);
//   ostringstream oss;
//   oss << fixed << setprecision(10) << prob;
//   return oss.str();
// }

// void BloomFilter::print_data() {
//   cout << "[";
//   for (int i = 0; i < data.size(); i++) {
//     if (i != 0) {
//       cout << ", ";
//     }
//     cout << data[i];
//   }
//   cout << "]";
// }

// int BloomFilter::h1(const string &w) {
//   unsigned char md5_hash[MD5_DIGEST_LENGTH];
//   MD5(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(), md5_hash);
//   string md5_str(reinterpret_cast<const char *>(md5_hash), MD5_DIGEST_LENGTH);
//   return hash<string>{}(md5_str) % 10;
// }

// int BloomFilter::h2(const string &w) {
//   unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
//   SHA256(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),sha256_hash);
//   string sha256_str(reinterpret_cast<const char *>(sha256_hash), SHA256_DIGEST_LENGTH);
//   return hash<string>{}(sha256_str) % 10;
// }
