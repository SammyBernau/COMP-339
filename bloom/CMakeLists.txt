find_package(OpenSSL REQUIRED)

add_executable(
    bloom_app
    bloom_app.cpp
    src/bloom_filter.cpp
    src/utils/file_read.cpp
)

target_link_libraries(bloom_app OpenSSL::Crypto OpenSSL::SSL)





