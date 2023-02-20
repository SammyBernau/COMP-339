FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(
  caesar_cipher_tests
  src/cipher/caesar_cipher_tests.cc
  src/cipher/decoder.cpp
  src/cipher/decoder_helper.cpp
  src/cipher/encoder.cpp
  src/file_manipulation/file_read.cpp
  src/utils/utils.cpp
)
target_link_libraries(
  caesar_cipher_tests
  gtest_main
)

add_executable (ccencoder "encoder_main.cpp" "src/cipher/encoder.cpp" "src/file_manipulation/file_read.cpp" "src/utils/utils.cpp")

add_executable(ccdecoder "decoder_main.cpp" "src/cipher/decoder.cpp" "src/cipher/decoder_helper.cpp" "src/file_manipulation/file_read.cpp" "src/utils/utils.cpp")

include(GoogleTest)
gtest_discover_tests(caesar_cipher_tests)