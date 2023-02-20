#include <gtest/gtest.h>

#include "../../include/encoder.h"
#include "../../include/utils.h"
#include "../../include/decoder.h"
#include "../../include/decoder_helper.h"
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


//This test was used when the runtime of the program was O(log n) due to a poorly adapted random number library
//We found a new library and updated the program to O(n) so these tests aren't needed

TEST(EncoderRunTimeTest, Complex) { 
  //Test used to make sure encoder runs in O(log n) and not O(n)
  
  auto start_1 = chrono::high_resolution_clock::now();
  encoder("encoded_1.txt",15);
  auto stop_1 = chrono::high_resolution_clock::now();
  auto duration_1 = chrono::duration_cast<std::chrono::microseconds>(stop_1 - start_1);
  int time_elapsed_1 = duration_1.count()/1000; //convert microseconds to milliseconds
  
  ASSERT_LE(time_elapsed_1, 1000);

  auto start_2 = chrono::high_resolution_clock::now();
  encoder("encoded_1.txt",4);
  auto stop_2 = chrono::high_resolution_clock::now();
  auto duration_2 = chrono::duration_cast<std::chrono::microseconds>(stop_2 - start_2);
  int time_elapsed_2 = duration_2.count()/1000;

  ASSERT_LE(time_elapsed_2, 1000);

  auto start_3 = chrono::high_resolution_clock::now();
  encoder("encoded_1.txt",30);
  auto stop_3 = chrono::high_resolution_clock::now();
  auto duration_3 = chrono::duration_cast<std::chrono::microseconds>(stop_3 - start_3);
  int time_elapsed_3 = duration_3.count()/1000;

  ASSERT_LE(time_elapsed_3, 1000);
}

TEST(RandomSentenceTest, ChecksTrueRandom) {
  //Ensures any two sentences are indeed random
  string rs1 = generate_random_sentence();
  string rs2 = generate_random_sentence();
  ASSERT_NE(rs1, rs2);

  string rs3 = generate_random_sentence();
  string rs4 = generate_random_sentence();
  ASSERT_NE(rs3,rs4);

  string rs5 = generate_random_sentence();
  string rs6 = generate_random_sentence();
  ASSERT_NE(rs5,rs6);

  //Should be ASSERT_STRNE, doesn't seem to work in Replit
} 

// TEST(DecodingTest, ShiftValuePerLine) {
//   //Tests if each line of decoder has different shift values
//   encoder("encoded_test.txt", 4);
//   decoder("encoded_test.txt", "decoded_test.txt");
//   fstream new_file;
//   vector<int> shift_first_2_lines;
//   vector<int> shift_last_2_lines;
//   new_file.open("decoded_test.txt", ios::in);
//   if (new_file.is_open()) {
//     string file_text;
//     int shift_value;
//     while (getline(new_file, file_text)) { 
//       for(int line = 1; line <= 2; line++) {
//         //auto [decoded_text_temp , shift] = decoder_helper(file_text);
//         shift_first_2_lines.push_back(shift_value);
//         line++;
//         }
//       for(int line = 3; line <= 4; line++) {
//         //auto [decoded_text_temp , shift] = decoder_helper(file_text);
//         shift_first_2_lines.push_back(shift_value);
//         line++;
//       }
//     }
//     new_file.close();
//   }
//   for (int i = 0; i < shift_first_2_lines.size(); ++i) {
//     ASSERT_NE(shift_first_2_lines[i], shift_last_2_lines[i]);
//   }
// } 

TEST(DecodeShiftTest, Complex) {
  //Tests if each line of decoder has
  string encode_test = "encode_test.txt";
  string decode_test = "decode_test.txt";
  encoder(encode_test,10);
  decoder(encode_test, decode_test);
  fstream new_file;
  vector<int> shifts;
  
  try {
        new_file.open(decode_test, ios::in); //open file object for reading
        if (!new_file.is_open()) {
            cout << "Error opening file: " << decode_test << endl;
        }
        if (new_file.is_open()) {
            string file_text;
            string temp;
            while (getline(new_file, file_text)) { //read file text
                int index_start = 24;
                while (index_start != ':') {
                  temp += file_text[index_start];
                  index_start++;
                }
                int shift = stoi(temp);
                cout << "Adding to vec... "<< shift << endl;
                shifts.push_back(shift);
                temp = "";
                index_start = 24;
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure& e) {
        cerr << "Error opening file: " << e.what() << endl;
    }

  cout << "comparing... " << endl;
  for (int i = 1; i < shifts.size(); i++){
    cout<< shifts[i-1] << " : "<< shifts[i] << endl;
    ASSERT_NE(shifts[i], shifts[i-1]);
  }

}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
