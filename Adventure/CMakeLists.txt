aux_source_directory(./private adventure)

include_directories(./public)
include_directories(../Creature/public)

link_directories(../Creature)

add_library(adventure_library SHARED ${adventure})

target_link_libraries(adventure_library PRIVATE creature_library)