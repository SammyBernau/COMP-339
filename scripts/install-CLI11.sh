#!/bin/bash

# Using GoogleTest is best by fetching from Google and doing a local build
git clone https://github.com/CLIUtils/CLI11
mkdir -p CLI11/build
pushd CLI11/build
cmake ..
sudo make install
popd