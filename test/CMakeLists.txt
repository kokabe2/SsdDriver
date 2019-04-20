add_executable(
    gtests
    "")

target_sources(
    gtests
    PRIVATE
        SsdDriverTest.cpp
    )

target_link_libraries(
    gtests
    gtest_main
    SsdDriver
    )

add_test(
  NAME
    SsdDriverTest
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/gtests
  )
