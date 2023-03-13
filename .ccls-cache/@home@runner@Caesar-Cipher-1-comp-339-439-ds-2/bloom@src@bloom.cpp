#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <functional>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

class BloomFilter {
public:
    BloomFilter(int m, int k) : m(m), k(k), data(m, 0), n(0) {}

    void insert(const string& element) {
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

    string search(const string& element) {
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
        double prob = pow(1.0 - pow(1.0 - 1.0/m, k*n), k);
        return "Might be in Bloom Filter with false positive probability " + to_string(prob);
    }

private:
    int m; // size of the bit array
    int k; // number of hash functions
    vector<int> data; // bit array
    int n; // number of elements in the set

    int h1(const string& w) {
        unsigned char md[MD5_DIGEST_LENGTH];
        MD5(reinterpret_cast<const unsigned char*>(w.c_str()), w.size(), md);
        string str(reinterpret_cast<char*>(md), MD5_DIGEST_LENGTH);
        str = str.substr(0, 6);
        return hash<string>{}(str) % 10;
    }

    int h2(const string& w) {
        unsigned char md[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char*>(w.c_str()), w.size(), md);
        string str(reinterpret_cast<char*>(md), SHA256_DIGEST_LENGTH);
        str = str.substr(0, 6);
        return hash<string>{}(str) % 10;
    }
};

int main() {
    BloomFilter bf(10, 2);
    bf.insert("hello");
    bf.insert("world");
    bf.insert("foo");
    bf.insert("bar");

    cout << bf.search("hello") << endl;
    cout << bf.search("world") << endl;
    cout << bf.search("foo") << endl;
    cout << bf.search("bar") << endl;
    cout << bf.search("baz") << endl;

    return 0;
}

