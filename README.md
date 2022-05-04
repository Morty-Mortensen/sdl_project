# CMake Tutorial

## Prerequisits (installations)

- Install C++ plugin.
- Install cmake (brew install cmake).
- Install CMake Tools plugin.
- Install GDB (https://www.ics.uci.edu/~pattis/common/handouts/macmingweclipse/allexperimental/mac-gdb-install.html)
- - Follow the process to create a self-signed certificate. But, instead of running the last command, run the following command instead: `codesign --entitlements gdb.xml -fs gdb-cert /usr/local/bin/gdb`. This works on newer versions of Mac / GDB.

## CMakeLists.txt (generates files that can build the executable)

- cmake_minimum_required(VERSION 3.23.1)
- project(sdl_project)
- add_executable(${PROJECT_NAME} main.cpp)

### CMake build process (builds executable)

1. mkdir build
2. cmake ./build
3. make -C ./build

## Debugging

- Add `set(CMAKE_BUILD_TYPE Debug)` to the CMakeLists.txt
- Install `CMake Tools` plugin (if not already installed).
- Install `GDB` (if not already installed).
- Click on the new "CMake" plugin icon on the left
- Select "Configure All Projects"
- If no build option is already availble, select "Build" and whichever project you want (default is "all")
- Right click on the wanted project from the "CMake" plugin panel (sdl_project in my case) and select "debug".

## VS Code

### launch.json

`{ "version": "0.2.0", "configurations": [ { "name": "GDB Debug", "type": "cppdbg", "request": "launch", "program": "${command:cmake.launchTargetPath}", "args": [], "stopAtEntry": false, "cwd": "${workspaceFolder}/build", "externalConsole": false, "MIMode": "gdb", "setupCommands": [ { "description": "Enable pretty-printing for gdb", "text": "-enable-pretty-printing", "ignoreFailures": true } ], "preLaunchTask": "build project", "miDebuggerPath": "/usr/local/bin/gdb" } ] }`

### tasks.json

`{ "version": "2.0.0", "tasks": [ { "type": "shell", "label": "build project", "command": "", "args": [ "make", "--directory=${workspaceFolder}/build" ], "options": { "cwd": "/usr/bin" }, "problemMatcher": [ "$gcc" ], "group": { "kind": "build", "isDefault": true } } ] }`

## Lessons Learned (C++)

1. If the `.h` file is encapsolated in a namespace, it is best to encapsolate the `.cpp` file in the same namespace (and not just say `using namespace <name>`).
2. Declare `friend` functions in the `.h` file and their implementation in the `.cpp` file without the `friend` keyword. They are given access to private variables even though `friend` functions are not considered member variables.
3. Returning a read-only reference `const &` does not allow the value to be updated (e.g. `std::string const &getValue()`).
4. Having `const` on the return value makes it `read-only` (`string const getValue()`). Having `const` in front of the function makes the return value need to be a `const` (`string getValue() const`).
5. Is there a reason to have reference member variables?
6. Template classes/functions cannot be separated in the `.h` and `.cpp` files. Unless you can declare all the types (`int`, `string`, etc) that the class/function could accept (that declaration happens somewhere at the bottom of the `.cpp` file). This is because a `templated` class/function is not an actual class/function. It just tells the compiler how the generated the class/function.
7. Template function explicit instantiation in .cpp: `template vector<string> const Reader::readFile<string>();`
8. Template class explicit instantiation in .cpp: `template class Reader<int>;`
9. Interfaces are `Abstract Classes` with `Pure Virtual Functions`: `virtual void getValue() = 0`
