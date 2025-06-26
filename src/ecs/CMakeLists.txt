project(mocha_ecs)

add_library(${PROJECT_NAME} ecs.cpp)
add_library(sub::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
  PUBLIC
    ../../include
)