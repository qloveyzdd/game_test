aux_source_directory(./private monster)

include_directories(./public)
include_directories(../Creature/public)
include_directories(../Adventure/public)

link_directories(../Creature)
link_directories(../Adventure)

add_library(monster_library SHARED ${monster})

target_link_libraries(monster_library PRIVATE creature_library)
target_link_libraries(monster_library PRIVATE adventure_library)