file(GLOB HSDS_SRC *.c)
add_library(hsds SHARED ${HSDS_SRC})
install(TARGETS hsds
    EXPORT hsds-targets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin
    ARCHIVE DESTINATION bin
)

# install(DIRECTORY include/ DESTINATION include)

