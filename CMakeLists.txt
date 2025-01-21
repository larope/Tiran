#https://github.com/meemknight/cmakeSetup

cmake_minimum_required(VERSION 3.16)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>") #we want to use the static runtime
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

project(mygame)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw-3.3.2)			#window oppener
add_subdirectory(thirdparty/glad)				#opengl loader
add_subdirectory(thirdparty/stb_image)			#loading immaged
add_subdirectory(thirdparty/stb_truetype)		#loading ttf files
add_subdirectory(thirdparty/glm)				#math


# Define MY_SOURCES to be a list of all the source files for my game
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(mygame ${MY_SOURCES}
		src/rendering/Renderable.h
		src/rendering/Renderable.cpp
		src/Input/InputManager.cpp
		src/Input/InputManager.h
		src/Controllers/CameraController.cpp
        src/Controllers/CameraController.h
		src/tools/Dispatcher.h
		src/tools/Observer.h
		src/entities/Entity.cpp
		src/entities/Entity.h
		src/input/MouseButtonInput.cpp
		src/input/MouseButtonInput.h
		src/input/KeyboardInput.cpp
		src/input/KeyboardInput.h
		src/input/MousePositionInput.cpp
		src/input/MousePositionInput.h
        src/tools/Dispatcher.cpp
)

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game


if(MSVC) # If using the VS compiler...

	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)

	#remove console
	#set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

	set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
	set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

endif()


target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")


target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glm glfw
		glad stb_image stb_truetype)

