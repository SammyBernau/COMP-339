#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

//Wrapper class that houses a set 
//We decided to create a class for this rather than just use set so that we could properly manage different instances of a word count without calling set a bunch of times
class WordCount {
public:
    WordCount(){};
    void insert(const string& word);
    int get_size();
    bool contains(const string& word);

private:
    set<int> words;

    int md5(const string& w);
    int sha256(const string& w);
    int sha384(const string& w);
};

#endif 