#include <iostream>
using namespace std;
#include "../include/bloom_filter.h"

int main() {
    BloomFilter bf (10, 2);
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