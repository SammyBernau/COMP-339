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
    //Concatenate the hashes to create a uniqueID of each word and if words doesn't have it, store it
    int unique_ID = sha256(word) + sha384(word) + md5(word);

    if (words.count(unique_ID) == 0){
         words.insert(unique_ID); 
    } 
}

int WordCount::get_size() {
    return words.size();
}

//Testing function 
bool WordCount::contains(const string &word){
    int unique_ID = sha256(word) + sha384(word) + md5(word);

    if (words.count(unique_ID)) {
        return true;
    } 
    return false;
}

int WordCount::md5(const string &w) {
  unsigned char md5_hash[MD5_DIGEST_LENGTH];
  MD5(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(), md5_hash);
  string md5_str(reinterpret_cast<const char *>(md5_hash), MD5_DIGEST_LENGTH);
  return hash<string>{}(md5_str);
}

int WordCount::sha256(const string &w) {
  unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),sha256_hash);
  string sha256_str(reinterpret_cast<const char *>(sha256_hash), SHA256_DIGEST_LENGTH);
  return hash<string>{}(sha256_str);
}

//Implemented sha384 because md5 is considered less effective
int WordCount::sha384(const string &w){
  unsigned char sha384_hash[SHA384_DIGEST_LENGTH];
  SHA384(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(), sha384_hash);
  string sha384_str(reinterpret_cast<const char *>(sha384_hash), SHA384_DIGEST_LENGTH);
  return hash<string>{}(sha384_str);
}
