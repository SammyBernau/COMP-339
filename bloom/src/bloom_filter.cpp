#include "../include/BloomFilter.h"
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <sstream>
using namespace std;

// Class constructor
BloomFilter::BloomFilter(int m, int k)
    : m(m), k(k), data(m), num_of_inserts(0), collisions(0) {}

int BloomFilter::get_size() { return num_of_inserts; }
int BloomFilter::get_collisions() { return collisions; }


//Insert words into the bloomfilter, indicating 1 for a word being present 
// void BloomFilter::insert(const string &word){
//   if (k == 1){
//     int hash1 = sha256(word) % m;

//     if (data[hash1] == 1)
//     {
//       collisions++;
//     }
//     else
//     {
//       data[hash1] = 1;
//       num_of_inserts++;
//     }
//   } else if (k == 2) {
//     int hash1 = sha256(word) % m;
//     int hash2 = sha512(word) % m;

//     if (data[hash1] == 0 && data[hash2] == 0) {
//       data[hash1] = 1;
//       data[hash2] = 1;
//       num_of_inserts++;
//     } else {
//       collisions++;
//     }
//   }
// }

//Insert words into the bloomfilter, indicating 1 for a word being present 
void BloomFilter::insert(const string &word){
  if (k == 1){
    unsigned int hash = sha256(word) % m;

    if (data[hash] == 0){
      data[hash] = 1;
      num_of_inserts++;
    } else{
      collisions++;
    }
  } else if (k == 2) {
    unsigned int hash1 = sha256(word);
    unsigned int hash2 = sha512(word);
    uint64_t combined_hash = (hash1 + hash2) % m;

    if (data[combined_hash] == 0 ) {
      data[combined_hash] = 1;
      num_of_inserts++;
    } else {
      collisions++;
    }
  }
}

double BloomFilter::false_pos(){
  return pow(1.0 - pow(1.0 - 1.0 / m, k * num_of_inserts), k);
}

void BloomFilter::print_data()
{
  cout << "[";
  for (int i = 0; i < data.size(); i++)
  {
    if (i != 0)
    {
      cout << ", ";
    }
    cout << data[i];
  }
  cout << "]";
}

int BloomFilter::sha256(const string& w) {
    // Create an OpenSSL context for the SHA-512 hash algorithm
    const EVP_MD* md = EVP_sha256();
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update the hash context with the input string
    EVP_DigestUpdate(ctx, w.c_str(), w.length());

    // Finalize the hash and obtain the resulting binary hash value
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);

    // Convert the binary hash value to a 32-bit integer using modulo operation
    uint32_t hash_int = *((uint32_t*) hash);

    // Map the 32-bit hash value to a 32-bit integer using modulo operation
    int output = hash_int % m;

    // Clean up the hash context
    EVP_MD_CTX_free(ctx);

    return output;
}

int BloomFilter::sha512(const string& w) {
    // Create an OpenSSL context for the SHA-512 hash algorithm
    const EVP_MD* md = EVP_sha512();
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update the hash context with the input string
    EVP_DigestUpdate(ctx, w.c_str(), w.length());

    // Finalize the hash and obtain the resulting binary hash value
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);

    // Convert the binary hash value to a 32-bit integer using modulo operation
    uint32_t hash_int = *((uint32_t*) hash);

    // Map the 32-bit hash value to a 32-bit integer using modulo operation
    int output = hash_int % m;

    // Clean up the hash context
    EVP_MD_CTX_free(ctx);

    return output;
}



// int BloomFilter::sha256(const std::string& input) {
//     unsigned char hash[SHA256_DIGEST_LENGTH];
//     SHA256((const unsigned char*) input.c_str(), input.length(), hash);

//     // Convert hash to an integer by taking the first 4 bytes and interpreting them as a 32-bit integer
//     uint32_t hash_int = *((uint32_t*) hash);

//     // Map the 32-bit hash value to a 32-bit integer using modulo operation
//     int output = hash_int % std::numeric_limits<int>::max();
    
//     return output;
// }

// int BloomFilter::sha384(const std::string& input) {
//     unsigned char hash[SHA384_DIGEST_LENGTH];
//     SHA384((const unsigned char*) input.c_str(), input.length(), hash);

//     // Convert hash to an integer by taking the first 4 bytes and interpreting them as a 32-bit integer
//     uint32_t hash_int = *((uint32_t*) hash);

//     // Map the 32-bit hash value to a 32-bit integer using modulo operation
//     int output = hash_int % std::numeric_limits<int>::max();
    
//     return output;
// }



// int BloomFilter::sha384(const string &w) {
//   unsigned char sha384_hash[SHA384_DIGEST_LENGTH];
//   SHA384(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(), sha384_hash);
//   string sha384_str(reinterpret_cast<const char *>(sha384_hash), SHA384_DIGEST_LENGTH);
//   return hash<string>{}(sha384_str) % m;
// }

// int BloomFilter::sha256(const string &w) {
//   unsigned char sha256_hash[SHA256_DIGEST_LENGTH];
//   SHA256(reinterpret_cast<const unsigned char *>(w.c_str()), w.length(),sha256_hash);
//   string sha256_str(reinterpret_cast<const char *>(sha256_hash),SHA256_DIGEST_LENGTH);
//   return hash<string>{}(sha256_str) % m;
// }
