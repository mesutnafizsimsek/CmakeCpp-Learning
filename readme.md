# CRETE MAKEFILE 

After creating a CmakeList.txt, you will build your project with this command 

cmake -S . -B out/build/

-S . means you are in the project folder
-B means you need to build to out/build/ dir 


# BUILD THE PROJECT

When you build your project to /out/build/ folder, you need to navigate here with cd 
and write 

make

command, this will create the executable using your specified cpp file in your CmakeList.txt

./ExeName will run the executable

# ADDING CPP FILE 

To add another file, lets say we have only one function in add.cpp and use it in our main.cpp file 
write the function definition into add.cpp and add the function declaration in main.cpp 
in this way cpp compiler will know you will use this function

But you need to add this cpp file to the cmakelist while you declare executable

add_executable(${PROJECT_NAME} main.cpp add.cpp)

# ADDING CPP WITH HEADER FILE 

As we write all of our libraries with Headers in pulpo, its better to know how to add header files 
For this, we should introduce our method into cmakelist 
For an example, we will create a Adder library with add.cpp and add.h files 

1) create a Adder directory
2) Create add.cpp and add.h 
3) Create a CMakeLists.txt in  Adder directory, this will be sub-level CMakeLists.txt
In this CMakeLists we will add 
add_library(add add.cpp)
command to say we will use add library 

4) In out main CMakeLists.txt 
We should introducte these commands to properly add a new library that we have created.

add_subdirectory(Adder)
target_include_directories(${PROJECT_NAME} PRIVATE Adder)
target_link_directories(${PROJECT_NAME} PRIVATE Adder/)
target_link_libraries(${PROJECT_NAME} add)

5) Build and Run like previously 

# SH files to automate commands
Sh can be used to automate the commands in Linux 
We write each of them on seperate .sh files and 
give each of them executable access like with, so we can run them easier.

chmod -x configure.sh
# SUBMODULES

Submoduler lets us integrate 3rd party libraries using Github

We will initizalize empty github repo with command 
git init 

Than we can add any library using like 
git submodule add https://github.com/glfw/glfw.git external/glfw

here we will add submodule to external/glfw directory

We can also write the automatic submodule import to cmakelists.txt in main folder but 
It will make our work look complicated, so now its better to add them manually for me.
# Submodule options 

Each professional project of libraries has options in their cmakelists file, we can change their
default values by adding -D{optionName}={someValue} while configure our project like : 

cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build/

here we set GLFW_BUILD_DOCS to OFF 

# Versioning 

To version your program, you should add the VERSION flag to project() func of cmake.

Also this command should be added 

configure_file(HighlighterConfig.h.in HighlighterConfig.h)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${PROJECT_BINARY_DIR}
)

Then, we will create HighlighterConfig.h.in file and write our macro in it.

# Options  MORE 

If we want to include any library optionally, we will use of #ifndef #else #endif preprocessors on code 
Also we need to create required CMakelists settings. 

We can use 
list(INCLUDE <listname> <variable>)
for required imports

# Installs

Yet we were installing our software manually with configure-build-run pipeline,
however, if we wan our software installable like other programs we can do it with Cmake 

Add 
install(TARGETS add DESTINATION lib)
install(FILES add.h DESTINATION include)

to adder lib makes this work for adder library

And 

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_NAME}/HighlighterConfig.h" DESTINATION include)

in main CMakeLists 

Then, we should create another .sh file which has this code 
cd out/build ; make install

This will make our programm accessable on the computer from command line like other
programs in the device.