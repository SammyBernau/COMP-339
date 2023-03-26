//This is the word count app that will use hash functions concatenated together to create a unique ID for each word entered
//Probably will use three hash functions to do this

#include "../include/WordCount.h"
#include <iomanip>
#include <iostream>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sstream>
using namespace std;

void WordCount::insert(const string &word) {
    int first_half = h1(word); 
    int second_half = h2(word); 
    int unique_ID = first_half + second_half;

    if (words.count(unique_ID) == 0){
         words.insert(unique_ID); 
    } 
}

int WordCount::get_size() {
    return words.size();
}

bool WordCount::contains(const string &word){
    int first_half = h1(word); 
    int second_half = h2(word); 
    int unique_ID = first_half + second_half; 

    if (words.count(unique_ID)) {
        return true;
    } 
    return false;
}

int WordCount::h1(const string &w) {
  unsigned char md5_hash[MD5_DIGEST_LENGTH];
  MD5(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(), md5_hash);
  string md5_str(reinterpret_cast<const char *>(md5_hash), MD5_DIGEST_LENGTH);
  return hash<string>{}(md5_str);
}

int WordCount::h2(const string &w) {
  unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),sha256_hash);
  string sha256_str(reinterpret_cast<const char *>(sha256_hash), SHA256_DIGEST_LENGTH);
  return hash<string>{}(sha256_str);
}
