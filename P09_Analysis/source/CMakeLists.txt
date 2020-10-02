#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# CMakeLists.txt: Geant4 Tutorial for Hep/Medicine Users (2016.11.29 @Sendai)  
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

#----------------------------------------------------------------------------
# Setup Section: You have to set the following two parameters
#----------------------------------------------------------------------------
# Set the name of your main program
  set( NAME_MAIN_PROGRAM Application_Main)

# Set the path to Geant4 library
  set( Geant4_DIR  /opt/geant4/10.2.2/lib64/Geant4-10.2.2)

#----------------------------------------------------------------------------
# Intact Section: You don't need to touch the following part
#----------------------------------------------------------------------------
# Set the project name 
  project( ${NAME_MAIN_PROGRAM} ) 

# Find Geant4 package
  option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
  if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
  else()
    find_package(Geant4 REQUIRED)
  endif()

# Set up Geant4 include directories and compile definition
  include(${Geant4_USE_FILE})
  include_directories(${PROJECT_SOURCE_DIR}/include)

# Locate sources and headers for this project
  file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
  file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Compile and link your application
  add_executable(${NAME_MAIN_PROGRAM} ${NAME_MAIN_PROGRAM}.cc 
                                      ${sources} ${headers})
  target_link_libraries(${NAME_MAIN_PROGRAM} ${Geant4_LIBRARIES})

# Install the executable
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/..)
  install(TARGETS ${NAME_MAIN_PROGRAM} DESTINATION bin)

