aux_source_directory(./private gamemanager)

include_directories(./public)
include_directories(../Monster/public)
include_directories(../Creature/public)
include_directories(../Adventure/public)

link_directories(../Monster)

add_library(gamemanager_library SHARED ${gamemanager})

target_link_libraries(gamemanager_library PRIVATE monster_library)