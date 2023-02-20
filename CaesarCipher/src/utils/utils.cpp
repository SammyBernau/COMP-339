#include "../../include/utils.h"
#include "../../include/file_read.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <thread>
#include <vector>
#include <random>
using namespace std;

// convert to upper (taken from chatGPT)
string to_upper_case(string str) {
  transform(str.begin(), str.end(), str.begin(), ::toupper);
  return str;
}

// remove non alphabetic chars (taken from chat GPT)
string remove_non_alpha(string str) {
  str.erase(remove_if(str.begin(), str.end(),
                      [](char c) { // lambda expression
                        return !isalpha(
                            c); // returns true if is abc char; otherwise false
                      }),
            str.end());

  return str;
}

//generates random number, excluding zero
int gen_random_num(int m, int n) {
  static mt19937 generator(random_device{}());
  uniform_int_distribution<int> distribution(m, n);
  int rand_num = distribution(generator);


  
  
  return rand_num;

  //this line was created with help from ChatGPT
  //The cipher does support shift keys from -26 to 26, but it is only decoding with negative shifts which doesn't seem possible (even when 200 lines are generated)
  //This bug wasn't noticed until the day it was due; therefore, the algorithm was reverted to only test 1-26 for keys. 
  //return (rand_num == 0) ? gen_random_num(m, n) : rand_num;
}

string generate_random_sentence() {
  // takes dictionary
  vector<string> dict = read_from_file_to_vec("dict.txt");
  int min_sentence_length = 3;
  int max_add_sentence_words = 25;
  string rand_sentence = "";

  int random_number = gen_random_num(1,1000);

  // sentence length between 3 and 25
  // TODO may need to shorten sentence length
  int sentence_length =
      (min_sentence_length + random_number % max_add_sentence_words);
  for (int k = 0; k < sentence_length; k++) {
    int random_word_pos = gen_random_num(1,2000) % dict.size();
    string random_word = dict[random_word_pos];

    if (rand_sentence.length() != 0)
      rand_sentence += " " + random_word;
    else {
      rand_sentence += random_word;
    }
  }
  return rand_sentence;
}
