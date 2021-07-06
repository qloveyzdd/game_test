aux_source_directory(./private monster)

include_directories(./public)
include_directories(../Creature/public)
include_directories(../Adventure/public)

link_directories(../Adventure)

add_library(monster_library SHARED ${monster})

target_link_libraries(monster_library adventure_library)