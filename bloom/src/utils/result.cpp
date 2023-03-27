#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <tuple>
#include "../../include/BloomFilter.h"
#include "../../include/WordCount.h"
using namespace std;

// get dictionary as vec
void result(string input_file, int bit_vec_size, int num_of_hashes)
{
    BloomFilter bf(bit_vec_size, num_of_hashes);
    WordCount wc;
    fstream new_file; // file object
    double running_total;

    try
    {
        new_file.open(input_file, ios::in); // open file object for reading
        if (!new_file.is_open())
        {
            cout << "Error opening file: " << input_file << endl;
        }
        if (new_file.is_open())
        {
            string line;
            while (getline(new_file, line))
            { // read file text
                string curr_word = "";
                for (auto &ch : line)
                {
                    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                    {
                        curr_word += ch;
                    }

                    if (ch == ' ')
                    {
                        
                        bf.insert(curr_word);
                        wc.insert(curr_word);
                        running_total += bf.false_pos();
                        curr_word = "";
                    }
                }

                if (curr_word.length() > 0 ) {
                    
                    bf.insert(curr_word);
                    wc.insert(curr_word);
                    running_total += bf.false_pos();
                    curr_word = "";
                }
            }
            new_file.close();
        }
    }
    catch (const ios_base::failure &e)
    {
        cerr << "Error opening file: " << e.what() << endl;
    }

    double avg_false_pos = (running_total / bf.get_size()) * 100;
    int words_lost = wc.get_size() - bf.get_size();

    if (words_lost < 0 ) {
        words_lost = 0;
    }

    cout << "---RESULT---" << endl;
    cout << "Reading from file: " << input_file << endl;
    cout << "Bit vector size: " << bit_vec_size << endl;
    cout << "Number of hash algs: " << num_of_hashes << endl;
    cout << "Avg false positive probability: " <<  avg_false_pos << "%" << endl;
    cout << "Total insertions into bit vector: " << bf.get_size() << endl;
    cout << "Total number of words seen: " << wc.get_total_words_seen() << endl;
    cout << "Number of collisions: " << bf.get_collisions() << endl;
    cout << "Number of unique words seen: " << wc.get_size() << endl;
    cout << "Unique words not entered or lost: " << words_lost << endl;
    cout << endl;
}