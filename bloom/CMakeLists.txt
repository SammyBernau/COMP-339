find_package(OpenSSL REQUIRED)

add_executable(
    bloom_app
    bloom_app.cpp
    src/bloom_filter.cpp
    src/utils/result.cpp
    src/word_count.cpp
)

target_link_libraries(bloom_app OpenSSL::Crypto OpenSSL::SSL)





