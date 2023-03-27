#!/bin/bash

echo "Here are the results for reading dict.txt into the bloom filter"
echo ""
echo "1st Output"
.././build/bin/bloom_app -i ../dict.txt -s 1000000 -n 1
echo ""
echo "2nd Output"
.././build/bin/bloom_app -i ../dict.txt -s 1000000 -n 2

echo ""
echo "3rd Output"
.././build/bin/bloom_app -i ../dict.txt -s 6000000 -n 1
echo ""
echo "4th Output"
.././build/bin/bloom_app -i ../dict.txt -s 6000000 -n 2

echo ""
echo "5rd Output"
.././build/bin/bloom_app -i ../dict.txt -s 12000000 -n 1
echo ""
echo "6th Output"
.././build/bin/bloom_app -i ../dict.txt -s 12000000 -n 2

echo ""
echo "7rd Output"
.././build/bin/bloom_app -i ../dict.txt -s 24000000 -n 1
echo ""
echo "8th Output"
.././build/bin/bloom_app -i ../dict.txt -s 24000000 -n 2

echo ""
echo "9rd Output"
.././build/bin/bloom_app -i ../dict.txt -s 48000000 -n 1
echo ""
echo "10th Output"
.././build/bin/bloom_app -i ../dict.txt -s 48000000 -n 2