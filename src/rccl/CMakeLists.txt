file(GLOB SRC_FILES "*.cpp")

# add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/rccl" "third_party/rccl")
find_package(rccl REQUIRED)


add_library(megray_rccl STATIC)
target_sources(megray_rccl PRIVATE ${SRC_FILES})
target_link_libraries(megray_rccl INTERFACE PRIVATE librccl megray_core INTERFACE hip_hcc)
target_include_directories(megray_rccl PUBLIC ${PROJECT_BINARY_DIR}/include)
target_include_directories(megray_rccl PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(megray_rccl PUBLIC ${HIP_INCLUDE_DIRS})
target_compile_options(megray_rccl PUBLIC ${HIP_COMPILE_OPTIONS})
target_link_directories(megray_rccl INTERFACE ${HIP_LIB_INSTALL_DIR} ${RCCL_BUILD_DIR})
# target_include_directories(megray_rccl PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/third_party/rccl")
