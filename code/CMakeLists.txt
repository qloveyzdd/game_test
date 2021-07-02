aux_source_directory(./Adventure/private Creature)
aux_source_directory(./Creature/private Creature)

add_library(Creature SHARED ${Creature})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

