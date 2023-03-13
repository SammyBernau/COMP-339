#include "../../include/file_read.h"
#include "../../include/utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <chrono>
using namespace std;



//Encrypts "n" number of randomly generated sentences and adds them to your choice of file 
void encoder(string write_file_name, int num_of_sentences) {

  //cout << "Encoding file... " << write_file_name << "\n" <<endl;
  vector<string> dict = read_from_file_to_vec("dict.txt"); // Load dict into vec
  int random_key;
  int last_shift = 0;
  for (int i = 1; i <= num_of_sentences; i++) {
    
    
    random_key = gen_random_num(1, 26);// get random shift between -26 and 26 except 0

    //Makes sure two consecutive rows dont have the same shift
    while (random_key == last_shift) {
      random_key = gen_random_num(1, 26);
    }
    last_shift = random_key;
    

    //cout << "Encoding with key " << random_key << endl;
    string plain_text_sentence = "";

    
    plain_text_sentence = generate_random_sentence();
    string cipher_text;
    for (char c : plain_text_sentence) {
      if (c >= 'a' && c <= 'z') {
        char encoded_char = ((c- 'a' + random_key + 26) % 26 + 'a');
        cipher_text += encoded_char;
      } else if (c >= 'A' && c <= 'Z') {
        char encoded_char = ((c- 'A' + random_key + 26) % 26 + 'A');
        cipher_text += encoded_char;
      } else {
        cipher_text += c;
      }
    }

    write_to_file(write_file_name, cipher_text);
  }
}
