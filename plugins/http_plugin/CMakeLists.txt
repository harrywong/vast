file(GLOB HEADERS "include/vast/http_plugin/*.hpp")
add_library( http_plugin
             http_plugin.cpp
             ${HEADERS} )

target_link_libraries( http_plugin chain_plugin vast_chain appbase fc )
target_include_directories( http_plugin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
