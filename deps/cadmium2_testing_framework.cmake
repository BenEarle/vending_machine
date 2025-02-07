include(FetchContent)

FetchContent_Declare(
  cadmium2_testing_framework
  GIT_REPOSITORY https://github.com/CurtisWinstanley/cadmium2_testing_framework.git
  GIT_TAG main
  GIT_PROGRESS TRUE
  GIT_SUBMODULES ""  # Do not initialize submodules
)

FetchContent_GetProperties(cadmium2_testing_framework)
if(NOT cadmium2_testing_framework_POPULATED)
  FetchContent_Populate(cadmium2_testing_framework)
endif()

set(CADMIUM2_TESTING_FRAMEWORK_INCLUDE_DIR ${FETCHCONTENT_BASE_DIR}/cadmium2_testing_framework-src/include CACHE STRING "Cadmium2 Testing Framework Include File Location")
