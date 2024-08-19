file(GLOB_RECURSE TEST_SOURCES
        "*.c"
        "*.cpp"
        "*.cxx"
        )

set(TEST_FILES "${TEST_SOURCES}" PARENT_SCOPE)
