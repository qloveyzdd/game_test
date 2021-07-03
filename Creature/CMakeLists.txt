aux_source_directory(./private creature)

include_directories(./public)

add_library(creature_library STATIC ${creature})

