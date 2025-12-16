cmake_minimum_required(VERSION 3.20)
project(backrooms LANGUAGES C)

if (MSVC)
    add_compile_options(/W4 /Ox)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()

add_executable(concept concept.c wallpaper.c)
target_link_libraries(concept termsup)

install(TARGETS concept
 RUNTIME DESTINATION bin
 LIBRARY DESTINATION lib)
