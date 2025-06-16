project(mocha_helper)

add_library(${PROJECT_NAME} log.cpp resource.cpp)
add_library(sub::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
  PUBLIC
    ../../include
)