if(RAWSPEED_COVERAGE_BUILD)
  # want all the symbols.
  rawspeed_add_library(rawspeed_bench SHARED)
else()
  rawspeed_add_library(rawspeed_bench STATIC)
endif()

target_link_libraries(rawspeed_bench PUBLIC rawspeed)
target_link_libraries(rawspeed_bench PUBLIC benchmark)
target_include_directories(rawspeed_bench PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

function(add_rs_bench src)
  get_filename_component(BENCHNAME ${src} NAME_WE)
  rawspeed_add_executable(${BENCHNAME} ${src})
  target_link_libraries(${BENCHNAME} PUBLIC rawspeed)
  target_link_libraries(${BENCHNAME} PUBLIC rawspeed_bench)

  rawspeed_add_test(NAME ${BENCHNAME}-Dummy COMMAND ${BENCHNAME} --help)
  set_tests_properties(${BENCHNAME}-Dummy PROPERTIES LABELS "benchmark;dummy")
  if(WIN32)
    set_tests_properties(${BENCHNAME}-Dummy PROPERTIES ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:$<TARGET_FILE_DIR:rawspeed_bench>")
  endif()

  rawspeed_add_test(NAME ${BENCHNAME} COMMAND ${BENCHNAME} --benchmark_min_time=0)
  set_tests_properties(${BENCHNAME} PROPERTIES LABELS "benchmark")
  set_tests_properties(${BENCHNAME} PROPERTIES ENVIRONMENT "RAWSPEED_BENCHMARK_DRYRUN=1")
  if(WIN32)
    set_tests_properties(${BENCHNAME} PROPERTIES ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:$<TARGET_FILE_DIR:rawspeed_bench>")
  endif()

  add_dependencies(benchmarks ${BENCHNAME})
endfunction()

add_subdirectory(adt)
add_subdirectory(bench)
add_subdirectory(decompressors)
add_subdirectory(interpolators)
add_subdirectory(io)
add_subdirectory(metadata)
