add_library(ImGui STATIC

    imgui.cpp
    imgui_draw.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui_demo.cpp

    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.cpp
)

target_include_directories(ImGui PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}

    ${CMAKE_CURRENT_SOURCE_DIR}/backends

    ../GLFW/include
    ../GLAD/include
)

target_link_directories(ImGui PUBLIC
    ../GLFW/lib-mingw-w64
)

target_link_libraries(ImGui PUBLIC

    glfw3
    opengl32
)