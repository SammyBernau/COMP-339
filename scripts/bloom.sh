#!/bin/bash
echo "" 
echo "1st Output"
.././build/bin/bloom_app -i ../hamlet.txt -s 1000000 -n 1
echo ""
echo "2nd Output"
.././build/bin/bloom_app -i ../hamlet.txt -s 1000000 -n 2

echo ""
echo "3rd Output"
.././build/bin/bloom_app -i ../hamlet.txt -s 6000000 -n 1
echo ""
echo "4th Output"
.././build/bin/bloom_app -i ../hamlet.txt -s 12000000 -n 2