aux_source_directory(./private monster)

include_directories(./public)
include_directories(../Adventure/public)
include_directories(../Creature/public)

link_directories(../Adventure)

add_library(monster_library SHARED ${monster})

target_link_libraries(monster_library PRIVATE adventure_library)