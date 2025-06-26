project(engine)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
  sub::mocha_helper
  sub::mocha_graphics
  sub::mocha_ecs
  sub::mocha_window
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${CMAKE_SOURCE_DIR/include}
)