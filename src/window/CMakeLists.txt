project(mocha_window)

find_package(glfw3 REQUIRED)

add_library(${PROJECT_NAME} ../graphics/glad.cpp window.cpp)
add_library(sub::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
  glfw
  GL
) 

target_include_directories( ${PROJECT_NAME}
  PUBLIC
    ../../include
)