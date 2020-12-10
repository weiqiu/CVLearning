FILE(GLOB SGM_INCLUDE_FILES 
"${PROJECT_SOURCE_DIR}/src/sgm/sgm.h" 
"${PROJECT_SOURCE_DIR}/src/image/*.*")

FILE(GLOB IMAGE_INCLUDE_FILES 
"${PROJECT_SOURCE_DIR}/src/image/*.*")

INSTALL(FILES ${SGM_INCLUDE_FILES}
 DESTINATION ${CMAKE_INSTALL_PREFIX}/include/sgm)
 
 INSTALL(FILES ${SGM_INCLUDE_FILES}
 DESTINATION ${CMAKE_INSTALL_PREFIX}/include/image)
