aux_source_directory(./private adventure)

add_subdirectory(../Creature)

add_library(adventure_lib SHARED ${adventure})

target_link_libraries(adventure_lib creature_lib)