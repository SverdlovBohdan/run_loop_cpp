# Run loop

Threadsafe task executor.


## How to build
```
mkdir build && cd build
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -B<project_root>/build -G Ninja

cmake --build <project_root>/build --config Debug --target all
```

### or use VSCode with CMake extension

## Overview
![Alt overview](docs/overview.jpg?raw=true "Overview")