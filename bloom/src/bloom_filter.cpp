#include "../include/BloomFilter.h"
#include <iomanip>
#include <iostream>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <sstream>
using namespace std;

// Class constructor
BloomFilter::BloomFilter(int m, int k)
    : m(m), k(k), data(m), num_of_inserts(0), collisions(0) {}

int BloomFilter::get_size() { return num_of_inserts; }
int BloomFilter::get_collisions() { return collisions; }

void BloomFilter::insert(const string &element)
{
  if (k == 1)
  {
    int hash1 = sha256(element) % m;

    if (data[hash1] == 1)
    {
      collisions++;
    }
    else
    {
      data[hash1] = 1;
    }
  }
  else if (k == 2)
  {
    unsigned int hash1 = sha256(element);
    unsigned int hash2 = sha512(element);
    uint64_t comb_hash = (hash1 + hash2) % m;

    if (data[comb_hash] == 0)
    {
      data[comb_hash] = 1;
    }
    else
    {
      collisions++;
    }
  }
  num_of_inserts++;
}

string BloomFilter::search(const string &element)
{
  if (k == 1)
  {
    int hash1 = sha256(element) % m;
    if (data[hash1] == 0)
    {
      return "Not in Bloom Filter";
    }
  }
  else if (k == 2)
  {
    int hash1 = sha256(element);
    int hash2 = sha512(element);
    int comb_hash = (hash1+hash2) %  m;
    if (data[comb_hash] == 0)
    {
      return "Not in Bloom Filter";
    }
  }
  double prob = pow(1.0 - pow(1.0 - 1.0 / m, k * num_of_inserts), k);
  ostringstream oss;
  oss << fixed << setprecision(10) << prob;
  return oss.str();
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

int BloomFilter::sha512(const std::string& input_str) {
    // Create an OpenSSL context for the SHA-512 hash algorithm
    const EVP_MD* md = EVP_sha512();
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update the hash context with the input string
    EVP_DigestUpdate(ctx, input_str.c_str(), input_str.length());

    // Finalize the hash and obtain the resulting binary hash value
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);

    // Convert the binary hash value to a 32-bit integer using modulo operation
    uint64_t hash_int = *((uint64_t*) hash);

    // Map the 32-bit hash value to a 32-bit integer using modulo operation
    int output = hash_int % m;

    // Clean up the hash context
    EVP_MD_CTX_free(ctx);

    return output;
}

int BloomFilter::sha256(const std::string& input_str) {
    // Create an OpenSSL context for the SHA-512 hash algorithm
    const EVP_MD* md = EVP_sha256();
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update the hash context with the input string
    EVP_DigestUpdate(ctx, input_str.c_str(), input_str.length());

    // Finalize the hash and obtain the resulting binary hash value
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);

    // Convert the binary hash value to a 32-bit integer using modulo operation
    uint64_t hash_int = *((uint64_t*) hash);

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
