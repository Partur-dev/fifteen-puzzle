project(game)

add_executable(game
    Application.cc
    Game.cc
    GameApplication.cc
    Main.cc
    Heuristic.cc
    Solver.cc
)

target_link_libraries(game
    PRIVATE
        glad imgui glm cgltf stb_image spdlog
)


target_compile_options(game PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror>
)

