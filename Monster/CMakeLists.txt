aux_source_directory(./private monster)

include_directories(./public)
include_directories(../Creature/public)
include_directories(../Adventure/public)

link_directories(../Adventure)
# link_directories(../Creature)

add_library(monster_library SHARED ${monster})

target_link_libraries(monster_library adventure_library)
# target_link_libraries(monster_library creature_library)