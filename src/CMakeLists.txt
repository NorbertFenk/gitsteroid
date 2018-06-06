set(SOURCES
        main.cpp
        ship.cpp
        )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(gitsteroid ${SOURCES})

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(gitsteroid ${SFML_LIBRARIES})
