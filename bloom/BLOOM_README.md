# <Center> BLOOM FILTER

## <Center> Authors: Sam Bernau & Lukasz Duda

## Intro

- Our implementation of a bloom filter uses two hashing algorithms [SHA256](https://www.openssl.org/docs/man1.0.2/man3/SHA256.html) and SHA512 from [OpenSSL](https://www.openssl.org/). Initially we used [MD5](https://www.openssl.org/docs/man1.1.1/man3/MD5.html); however, upon further investigation we discovered that MD5 was less effective and reliable compared with newer hash functions. The hash function implementations were created with the help of our generous friend ChatGPT. 

## Deliverables

- Within the bloom directory there are two main functions, `BloomFilter` and `WordCount`.

### BloomFilter

- `BloomFilter` is an object class that creates a dynamic vector with the user entering the size and number of hash functions to be used at runtime. It also tracks the number of inserts and collisions.

### WordCount

- `WordCount` is an object class that wraps a set. It contains all the unique words that have been seen in a file. The ID for each unique words is computed as such: `uint64_t unique_ID = sha256(word) + sha512(word) + word.length();`. `WordCount` also tracks the total number of words seen (regardless of uniqueness). A `get_size()` function and `contains(const string &word)` are also available.

## Result Format

- To test and document our experiment, we printed the results to the terminal in this format.

``` 
---RESULT---
Reading from file: ...
Bit vector size: ...
Number of hash algs: ...
Avg false positive probability: ...
Total insertions into bit vector: ...
Total number of words seen: ...
Number of collisions: ...
Number of unique words seen: ...
Unique words not entered or lost: ...
```

## Scripts

- To automate the testing process we created two ShellScript files, `bloom_dict.sh` and `bloom_hamlet.sh` in the `/scripts` directory. One for testing `dict.txt` and one for `hamlet.txt`.

## How to use

- To use the scripts for yourself `cd` into the scripts directory and run either `./bloom_dict.sh` or `./bloom_hamlet.sh`.

## Results 

- `./bloom_dict.sh`

```
Here are the results for reading dict.txt into the bloom filter

1st Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 1000000
Number of hash algs: 1
Avg false positive probability: -1.73929e+220%
Total insertions into bit vector: 103914
Total number of words seen: 126657
Number of collisions: 22743
Number of unique words seen: 109820
Unique words not entered or lost: 5906


2nd Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 1000000
Number of hash algs: 2
Avg false positive probability: 1.55103%
Total insertions into bit vector: 103986
Total number of words seen: 126657
Number of collisions: 22671
Number of unique words seen: 109820
Unique words not entered or lost: 5834


3rd Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 6000000
Number of hash algs: 1
Avg false positive probability: -10116.3%
Total insertions into bit vector: 108823
Total number of words seen: 126657
Number of collisions: 17834
Number of unique words seen: 109820
Unique words not entered or lost: 997


4th Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 6000000
Number of hash algs: 2
Avg false positive probability: -3.11595e+42%
Total insertions into bit vector: 108786
Total number of words seen: 126657
Number of collisions: 17871
Number of unique words seen: 109820
Unique words not entered or lost: 1034


5rd Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 12000000
Number of hash algs: 1
Avg false positive probability: -2.70984e+302%
Total insertions into bit vector: 109324
Total number of words seen: 126657
Number of collisions: 17333
Number of unique words seen: 109820
Unique words not entered or lost: 496


6th Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 12000000
Number of hash algs: 2
Avg false positive probability: 0.0126971%
Total insertions into bit vector: 109285
Total number of words seen: 126657
Number of collisions: 17372
Number of unique words seen: 109820
Unique words not entered or lost: 535


7rd Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 24000000
Number of hash algs: 1
Avg false positive probability: 6.00369e+272%
Total insertions into bit vector: 109570
Total number of words seen: 126657
Number of collisions: 17087
Number of unique words seen: 109820
Unique words not entered or lost: 250


8th Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 24000000
Number of hash algs: 2
Avg false positive probability: 0.00320031%
Total insertions into bit vector: 109544
Total number of words seen: 126657
Number of collisions: 17113
Number of unique words seen: 109820
Unique words not entered or lost: 276


9rd Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 48000000
Number of hash algs: 1
Avg false positive probability: -1.60383e+148%
Total insertions into bit vector: 109703
Total number of words seen: 126657
Number of collisions: 16954
Number of unique words seen: 109820
Unique words not entered or lost: 117


10th Output
---RESULT---
Reading from file: ../dict.txt
Bit vector size: 48000000
Number of hash algs: 2
Avg false positive probability: 6.76512e+170%
Total insertions into bit vector: 109679
Total number of words seen: 126657
Number of collisions: 16978
Number of unique words seen: 109820
Unique words not entered or lost: 141
```

- `./bloom_hamlet.sh`

```
Here are the results for reading hamlet.txt into the bloom filter

1st Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 1000000
Number of hash algs: 1
Avg false positive probability: 2.08255%
Total insertions into bit vector: 5868
Total number of words seen: 35254
Number of collisions: 29386
Number of unique words seen: 5884
Unique words not entered or lost: 16


2nd Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 1000000
Number of hash algs: 2
Avg false positive probability: -4.0771e+197%
Total insertions into bit vector: 5867
Total number of words seen: 35254
Number of collisions: 29387
Number of unique words seen: 5884
Unique words not entered or lost: 17


3rd Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 6000000
Number of hash algs: 1
Avg false positive probability: -1.26146e+172%
Total insertions into bit vector: 5882
Total number of words seen: 35254
Number of collisions: 29372
Number of unique words seen: 5884
Unique words not entered or lost: 2


4th Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 6000000
Number of hash algs: 2
Avg false positive probability: -9.10838e+298%
Total insertions into bit vector: 5882
Total number of words seen: 35254
Number of collisions: 29372
Number of unique words seen: 5884
Unique words not entered or lost: 2


5rd Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 12000000
Number of hash algs: 1
Avg false positive probability: 0.173699%
Total insertions into bit vector: 5883
Total number of words seen: 35254
Number of collisions: 29371
Number of unique words seen: 5884
Unique words not entered or lost: 1


6th Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 12000000
Number of hash algs: 2
Avg false positive probability: -6.15352e+62%
Total insertions into bit vector: 5883
Total number of words seen: 35254
Number of collisions: 29371
Number of unique words seen: 5884
Unique words not entered or lost: 1


7rd Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 24000000
Number of hash algs: 1
Avg false positive probability: 0.0868569%
Total insertions into bit vector: 5883
Total number of words seen: 35254
Number of collisions: 29371
Number of unique words seen: 5884
Unique words not entered or lost: 1


8th Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 24000000
Number of hash algs: 2
Avg false positive probability: -1.12731e+226%
Total insertions into bit vector: 5884
Total number of words seen: 35254
Number of collisions: 29370
Number of unique words seen: 5884
Unique words not entered or lost: 0


9rd Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 48000000
Number of hash algs: 1
Avg false positive probability: 0.0434304%
Total insertions into bit vector: 5883
Total number of words seen: 35254
Number of collisions: 29371
Number of unique words seen: 5884
Unique words not entered or lost: 1


10th Output
---RESULT---
Reading from file: ../hamlet.txt
Bit vector size: 48000000
Number of hash algs: 2
Avg false positive probability: -7.78139e+235%
Total insertions into bit vector: 5884
Total number of words seen: 35254
Number of collisions: 29370
Number of unique words seen: 5884
Unique words not entered or lost: 0
```

## Conclusion

- From the results printed by the ShellScript files we were able to discover a few things.
    1. Using two hashing algorithms over one resulted in better results across the board.
    2. Reaching 0 total collisions was not possible with our implementation/configuration. For future implementations we will try different hash functions (not just from OpenSSL) as the hash functions seem to be the bottle neck. More specifically everytime we mod the hash values by the size of the vector we restrict uniqueness of hash values. Therefore, testing this specific area is necessary.
    3. At the very end (after new hash functions were implemented) we found out that our average false positive probability grew dramatically with one hash functions being used. Compared to our early testing this is an unexpected outcome.




