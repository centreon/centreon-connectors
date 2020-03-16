include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(gtest REQUIRED)
include_directories(${gtest_INCLUDE_DIRS})
link_directories(${gtest_LIB_DIRS})

add_definitions(-DBUILD_PATH="${CMAKE_BINARY_DIR}")

add_executable(ut
  # Core sources
  ${CMAKE_SOURCE_DIR}/perl/src/embedded_perl.cc
  ${CMAKE_SOURCE_DIR}/perl/src/log_v2.cc
  ${CMAKE_SOURCE_DIR}/perl/src/pipe_handle.cc
  ${CMAKE_SOURCE_DIR}/perl/src/script.cc
  ${CMAKE_SOURCE_DIR}/perl/src/xs_init.cc
  # Test sources.
  ${CMAKE_SOURCE_DIR}/perl/test/main.cc
  ${CMAKE_SOURCE_DIR}/perl/test/connector.cc
  ${CMAKE_SOURCE_DIR}/perl/test/embedded_perl.cc
  )

target_link_libraries(ut ${gtest_LIBS} ${CLIB_LIBRARIES} ${PERL_LIBRARIES} ${fmt_LIBS} ${spdlog_LIBS})