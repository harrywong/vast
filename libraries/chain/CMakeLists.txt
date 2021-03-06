configure_file(${CMAKE_CURRENT_SOURCE_DIR}/genesis_state_root_key.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp)

## SORT .cpp by most likely to change / break compile
add_library(vast_chain
    address.cpp
    asset.cpp
    percent_slim.cpp
    merkle.cpp
    name.cpp
    name128.cpp
    transaction.cpp
    transaction_context.cpp
    block_header.cpp
    block_header_state.cpp
    block_state.cpp
    block_log.cpp
    chain_config.cpp
    chain_id_type.cpp
    genesis_state.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp

    fork_database.cpp
    token_database.cpp
    token_database_snapshot.cpp
    snapshot.cpp

    apply_context.cpp
    controller.cpp

    contracts/authorizer_ref.cpp
    contracts/group.cpp
    contracts/vast_link.cpp
    contracts/vast_org.cpp
    contracts/vast_contract_abi.cpp
    contracts/abi_serializer.cpp
    
    contracts/lua_engine.cpp
    contracts/lua_db.cpp
    contracts/lua_json.cpp
)

add_library(vast_chain_lite SHARED
    address.cpp
    asset.cpp
    percent_slim.cpp
    name.cpp
    name128.cpp
    transaction.cpp
    chain_id_type.cpp
    genesis_state.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp
    contracts/abi_serializer.cpp
    contracts/group.cpp
    contracts/authorizer_ref.cpp
    contracts/vast_link.cpp
    contracts/vast_contract_abi.cpp
)

find_package(LLVM REQUIRED)
find_package(luajit REQUIRED)

target_link_libraries(vast_chain vast_utilities fc chainbase rocksdb fmt-header-only sparsehash sss ${LLVM_LIBRARIES} ${LUAJIT_LIBRARIES})
target_include_directories(vast_chain PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
    "${LLVM_INCLUDE_DIR}"
    "${LLVM_C_INCLUDE_DIR}"
    "${LUAJIT_INCLUDE_DIR}"
)

target_link_libraries(vast_chain_lite fc_lite fmt-header-only sparsehash ${LLVM_LIBRARIES})
target_include_directories(vast_chain_lite PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../chainbase/include" 
    "${CMAKE_CURRENT_SOURCE_DIR}/../utilities/include"
    "${LLVM_INCLUDE_DIR}"
    "${LLVM_C_INCLUDE_DIR}"
)

target_compile_definitions(vast_chain PUBLIC FMT_STRING_ALIAS=1)

# find_package(TBB)

if(ENABLE_MAINNET_BUILD)
    target_compile_definitions(vast_chain PUBLIC MAINNET_BUILD)
endif()

install(TARGETS vast_chain
    RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR} OPTIONAL
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} OPTIONAL
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} OPTIONAL
)
install_directory_permissions( DIRECTORY ${CMAKE_INSTALL_FULL_INCLUDEDIR}/vast/chain )

install(TARGETS vast_chain_lite
    RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR} OPTIONAL
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} OPTIONAL
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR} OPTIONAL
)
