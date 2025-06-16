project(mocha_graphics)

find_package(glfw3 REQUIRED)

add_library(${PROJECT_NAME} glad.cpp stb.cpp render.cpp camera.cpp drawables.cpp)
add_library(sub::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
  glfw
  GL
) 

target_include_directories( ${PROJECT_NAME}
  PUBLIC
    ../../include
)