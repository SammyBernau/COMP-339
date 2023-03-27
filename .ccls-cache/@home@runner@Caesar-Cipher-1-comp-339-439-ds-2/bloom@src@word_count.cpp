// This is the word count app that will use hash functions concatenated together
// to create a unique ID for each word entered Probably will use three hash
// functions to do this

#include "../include/WordCount.h"
#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sstream>
using namespace std;

void WordCount::insert(const string &word) {
  // Concatenate the hashes to create a uniqueID of each word and if words
  // doesn't have it, store it
  uint64_t unique_ID = sha256(word) + sha512(word) + word.length();

  if (words.count(unique_ID) == 0) {
    words.insert(unique_ID);
  }
  total_words_seen++;
}

int WordCount::get_total_words_seen() { return total_words_seen; }

int WordCount::get_size() { return words.size(); }

// Testing function
bool WordCount::contains(const string &word) {
  uint64_t unique_ID = sha256(word) + sha512(word) + word.length();

  if (words.count(unique_ID)) {
    return true;
  }
  return false;
}

// int WordCount::sha512(const string &w) {
//   // Create an OpenSSL context for the SHA-512 hash algorithm
//   const EVP_MD *md = EVP_sha512();
//   EVP_MD_CTX *ctx = EVP_MD_CTX_new();
//   EVP_DigestInit_ex(ctx, md, NULL);

//   // Update the hash context with the input string
//   EVP_DigestUpdate(ctx, w.c_str(), w.length());

//   // Finalize the hash and obtain the resulting binary hash value
//   unsigned char hash[EVP_MAX_MD_SIZE];
//   unsigned int hash_len;
//   EVP_DigestFinal_ex(ctx, hash, &hash_len);

//   // Convert the binary hash value to a 32-bit integer using modulo operation
//   uint32_t hash_int = *((uint32_t *)hash);

//   // Map the 32-bit hash value to a 32-bit integer using modulo operation
//   int output = hash_int % numeric_limits<int>::max();

//   // Clean up the hash context
//   EVP_MD_CTX_free(ctx);

//   return output;
// }

// int WordCount::sha256(const string &w) {
//   // Create an OpenSSL context for the SHA-512 hash algorithm
//   const EVP_MD *md = EVP_sha256();
//   EVP_MD_CTX *ctx = EVP_MD_CTX_new();
//   EVP_DigestInit_ex(ctx, md, NULL);

//   // Update the hash context with the input string
//   EVP_DigestUpdate(ctx, w.c_str(), w.length());

//   // Finalize the hash and obtain the resulting binary hash value
//   unsigned char hash[EVP_MAX_MD_SIZE];
//   unsigned int hash_len;
//   EVP_DigestFinal_ex(ctx, hash, &hash_len);

//   // Convert the binary hash value to a 32-bit integer using modulo operation
//   uint32_t hash_int = *((uint32_t *)hash);

//   // Map the 32-bit hash value to a 32-bit integer using modulo operation
//   int output = hash_int % numeric_limits<int>::max();

//   // Clean up the hash context
//   EVP_MD_CTX_free(ctx);

//   return output;
// }

int WordCount::sha256(const string &w) {
  unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
  SHA256(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),
         sha256_hash);
  string sha256_str(reinterpret_cast<const char *>(sha256_hash),
                    SHA256_DIGEST_LENGTH);
  return hash<string>{}(sha256_str);
}

// Implemented sha512 because md5 is considered less effective
int WordCount::sha512(const string &w) {
  unsigned char sha512_hash[SHA512_DIGEST_LENGTH];
  SHA512(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),
         sha512_hash);
  string sha512_str(reinterpret_cast<const char *>(sha512_hash),
                    SHA512_DIGEST_LENGTH);
  return hash<string>{}(sha512_str);
}
