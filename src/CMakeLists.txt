add_library(
    SsdDriver
    "")

target_sources(
    SsdDriver
    PRIVATE
        SsdDriver.c
        LedDriver.c
        SpyRuntimeError.c
    )

target_include_directories(
    SsdDriver
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
