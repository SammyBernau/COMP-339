#include "../include/BloomFilter.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <openssl/sha.h>
using namespace std;

BloomFilter::BloomFilter(int m, int k) : m(m), k(k), data(m), n(0) {}

void BloomFilter::insert(const string& element) {
    if (k == 1) {
        int hash1 = h1(element) % m;
        data[hash1] = 1;
    } else if (k == 2) {
        int hash1 = h1(element) % m;
        int hash2 = h2(element) % m;
        data[hash1] = 1;
        data[hash2] = 1;
    }
    n++;
}

string BloomFilter::search(const string& element) {
    if (k == 1) {
        int hash1 = h1(element) % m;
        if (data[hash1] == 0) {
            return "Not in Bloom Filter";
        }
    } else if (k == 2) {
        int hash1 = h1(element) % m;
        int hash2 = h2(element) % m;
        if (data[hash1] == 0 || data[hash2] == 0) {
            return "Not in Bloom Filter";
        }
    }
    double prob = pow(1.0 - pow(1.0 - 1.0 / m, k * n), k);
    ostringstream oss;
    oss << fixed << setprecision(10) << prob;
    return "Might be in Bloom Filter with false positive probability " + oss.str();
}

void BloomFilter::print_data() {
  cout << "[";
  for ( int i = 0; i < data.size(); i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << data[i];
    }
  cout << "]";
}

int BloomFilter::h1(const string& w) {
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(w.c_str()), w.length(), md5_hash);
    string md5_str(reinterpret_cast<const char*>(md5_hash), MD5_DIGEST_LENGTH);
    return hash<string>{}(md5_str) % 10;
}

int BloomFilter::h2(const string& w) {
    unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(w.c_str()), w.length(), sha256_hash);
    string sha256_str(reinterpret_cast<const char*>(sha256_hash), SHA256_DIGEST_LENGTH);
    return hash<string>{}(sha256_str) % 10;
  }



