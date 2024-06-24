cmake_minimum_required(VERSION 3.0)
project(enggcalc_fltk)

#Find FLTK
find_package(FLTK REQUIRED)

# Find X11 (required for FLTK on Linux)
find_package(X11 REQUIRED)

# Add your source files
set(SOURCES
    src/Bin.cpp
    src/Dec.cpp
    src/Hex.cpp
    src/Oct.cpp
    src/Custom_Output.cpp
    main.cpp
    # Add more source files here if needed
)

# Set compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-comment")

# Include source headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create executable
add_executable(enggcalc_fltk ${SOURCES})

# Link libraries
target_link_libraries(enggcalc_fltk fltk ${X11_LIBRARIES})

# Installation paths
set(CMAKE_INSTALL_PREFIX /usr/local)

# Install the binary
install(TARGETS enggcalc_fltk RUNTIME DESTINATION bin)

# Define installation paths
set(ICON_DESTINATION share/icons/hicolor/256x256/apps)
set(DESKTOP_DESTINATION share/applications)

# Install the icon
install(FILES icon_256x256.png DESTINATION ${ICON_DESTINATION} RENAME enggcalc_fltk.png)

# Install the desktop entry
install(FILES enggcalc_fltk.desktop DESTINATION ${DESKTOP_DESTINATION})

