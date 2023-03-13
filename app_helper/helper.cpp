#include <iostream>
using namespace std;
int main() {
  int num_of_programs = 2;
  cout << "Hello! Welcome to Sam and Lukaz's homework repository for COMP 301! "
          ":)"
       << endl;

  cout << "So far there are " << num_of_programs
       << " programs(s) available for use: CaesarCipher and BloomFilter"
       << endl;

  cout << "CaesarCipher ex: \"ccencoder -i input.txt -s 20\" and then "
          "\"ccdecoder -i input.txt -o output.txt\""
       << endl;

  cout << "BloomFilter ex:  \"bloom_app -s 20 -n 2\"" << endl;
}