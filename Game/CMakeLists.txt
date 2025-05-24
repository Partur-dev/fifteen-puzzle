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

