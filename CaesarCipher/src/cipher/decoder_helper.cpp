#include "../../include/file_read.h"
#include "../../include/utils.h"
#include <cctype>
#include <chrono>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <tuple> 
using namespace std;

string get_first_word(string str) {
  // Gets the first word in a string given that words are separated by spaces
  string first_word = "";
  for (char c : str) {
    if (!isspace(c)) {
      first_word += c;
    } else {
      break;
    }
  }
  return first_word;
}

string decode(string cipher_text, int shift) {
  //function that returns a decoded text based off shift (once it is found in get_shift)
  string plain_text;
  for (char c : cipher_text) {
    if (c >= 'a' && c <= 'z') {
      char decoded_char = 'a' + (c - 'a' - shift + 26) % 26;
      plain_text += decoded_char;
    } else if (c >= 'A' && c <= 'Z') {
      char decoded_char = 'A' + (c - 'A' - shift + 26) % 26;
      plain_text += decoded_char;
    } else {
      plain_text += c;
    }
  }
  
  return plain_text;
}

int get_shift(string str, set<string> dict) {
  //Tests for all variations of shift value only on the first word in the line
  //Tests only the first word to avoid unneccessary computation time of testing the whole line
  string current_decoded_str = "";
  int correct_shift;
  int shift;
  for (shift = 1; shift <= 26; shift++) {
    current_decoded_str = decode(str, shift); 
    
    if (dict.count(current_decoded_str)) {
      return shift;
    } else {
      current_decoded_str = "";
      continue;
    }
  }
  return shift;
}

tuple<string, int> decoder_helper(string cipher_text) {
  //wrapper method to house all decode methods
  set<string> dict_as_set = read_from_file_to_set("dict.txt");
  string first_word_cipher = get_first_word(cipher_text);
  
  // Try and decode first word until match is found
  int shift = get_shift(first_word_cipher, dict_as_set);
  return make_tuple(decode(cipher_text, shift), shift);
}