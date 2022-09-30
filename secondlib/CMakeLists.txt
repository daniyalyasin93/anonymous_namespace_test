project(mylib)

add_library(mylib STATIC main.cpp)
target_include_directories(${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )

install(EXPORT MyLibTargets
        FILE MyLibTargets.cmake
        NAMESPACE MyLib::
        DESTINATION lib/cmake/MyLib
         )

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
         DESTINATION
             .
         FILES_MATCHING PATTERN
             "*.h"
     )
install(TARGETS mylib
        EXPORT MyLibTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

configure_file(MyLibConfig.cmake.in MyLibConfig.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/MyLibConfig.cmake"
               #"${CMAKE_CURRENT_BINARY_DIR}/MyLibConfigVersion.cmake"
         DESTINATION lib/cmake/MyLib
         )