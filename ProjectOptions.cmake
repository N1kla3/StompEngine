include(CMakeDependentOption)
include(CheckCXXCompilerFlag)

macro(stomp_setup_options)

  if(NOT PROJECT_IS_TOP_LEVEL)
    option(STOMP_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
    option(STOMP_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(STOMP_ENABLE_PCH "Enable precompiled headers" OFF)
    option(STOMP_ENABLE_CACHE "Enable ccache" OFF)
    option(STOMP_ENABLE_TESTS "Enable tests" ON)
  else()
    option(STOMP_WARNINGS_AS_ERRORS "Treat Warnings As Errors" ON)
    option(STOMP_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
    option(STOMP_ENABLE_PCH "Enable precompiled headers" OFF)
    option(STOMP_ENABLE_CACHE "Enable ccache" OFF)
    option(STOMP_ENABLE_TESTS "Enable tests" ON)
  endif()

  if(NOT PROJECT_IS_TOP_LEVEL)
    mark_as_advanced(
      STOMP_WARNINGS_AS_ERRORS
      STOMP_ENABLE_UNITY_BUILD
      STOMP_ENABLE_COVERAGE
      STOMP_ENABLE_PCH
      STOMP_ENABLE_CACHE)
  endif()

endmacro()

macro(stomp_local_options)
  if(PROJECT_IS_TOP_LEVEL)
    include(CMake/StandardProjectSettings.cmake)
  endif()

  add_library(stomp_warnings INTERFACE)
  add_library(stomp_options INTERFACE)

  include(CMake/CompilerWarnings.cmake)
  stomp_set_project_warnings(
    stomp_warnings
    ${STOMP_WARNINGS_AS_ERRORS}
    ""
    ""
    ""
    "")

  set_target_properties(stomp_options PROPERTIES UNITY_BUILD ${STOMP_ENABLE_UNITY_BUILD})

  if(STOMP_ENABLE_PCH)
    target_precompile_headers(
      STOMP_options
      INTERFACE
      <vector>
      <string>
      <utility>)
  endif()

  if(STOMP_ENABLE_CACHE)
    include(CMake/Cache.cmake)
    stomp_enable_cache()
  endif()

  if(STOMP_ENABLE_COVERAGE)
    include(cmake/Tests.cmake)
    stomp_enable_coverage(stomp_options)
  endif()

  if(STOMP_WARNINGS_AS_ERRORS)
    check_cxx_compiler_flag("-Wl,--fatal-warnings" LINKER_FATAL_WARNINGS)
    if(LINKER_FATAL_WARNINGS)
      # This is not working consistently, so disabling for now
      # target_link_options(STOMP_options INTERFACE -Wl,--fatal-warnings)
    endif()
  endif()

endmacro()
