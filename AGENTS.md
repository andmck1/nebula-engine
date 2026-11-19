# Project overview
- This is a graphics application built in C++20 using Vulkan for Linux.

# Developer Instructions
- Never make edits
- Always check the top level file structure and recursive file structure in src/ first using `ls`. 
- Always check for available packages in the root CMakeLists.txt
- Never use auto where possible.

# AI Instructions
- Always compact and summarise before running tasks.
- This is a British English project so no Americanisms in the code (eg.
  initialise instead of initialize).

# Architecture and Design
- Data-oriented design 
    - prioritise the efficient processing of objects over their structure
- Entity-component and component-effect structures
    - Where possible effects, abilities, etc must be modular, prioritising many smaller scripts over single larger ones
- Test-driven development
    - Each feature must be modular and testable and expose parameters to be changed by humans for game feel
    - The focus on testing is not in making sure each function has a unit test but that APIs have contracts with pre- and post-conditions and invariants
- Layered architecture
    - Eg. platform, render, etc layers make resources available to the layer above as needed
- Service locator pattern
    - Interfaces are implemented for services and made available via a global service-locator singleton

# Building
- Run `cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Debug` then `cmake --build cmake`.

# Testing
- doctest is used for testing, with tests sitting with code.
- Contract-style tests are used with pre- and post-conditions and invariants.
- To run tests run `./build/bin/nebula-engine-core-tests`

# Debugging
- When debugging graphics pipelines used take screenshots of the application.
- Use RenderDoc.
