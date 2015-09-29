#########################################################################################################
#                                                                                                       #
#        PART ONE : INDICATE WHERE THE SFML FOLDER IS TO THE COMPILER                                   #
#                                                                                                       #
#########################################################################################################

# FINDING SFML : PUT HERE THE PATH TO THE SFML FOLDER
# this is an exemple.



set(SFML_ROOT D:/SFML2/)




#########################################################################################################
#        Misc  relative to CLion                                                                        #
#########################################################################################################
# In CLion, the built product is put i don't know where. uncomment next line if you want to make it
# appear in your project/bin folder.

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")



#########################################################################################################
#                                                                                                       #
#         PART TWO : uncomment the next line if you want static linking                                 #
#             still needs work to include needed lib if using static build                              #
#                                                                                                       #
#########################################################################################################

#set(SFML_STATIC_LIBRARIES)

#########################################################################################################
#         PART THREE : remove the dependencies you don't need.                                          #
#         Watch out, the order matters :                                                                #
#         "graphics" needs "window"                                                                     #
#         everything needs "system"                                                                     #
#                                                                                                       #
#         Clean line :                                                                                  #
#             find_package(SFML 2 REQUIRED audio graphics network window system)                        #
#                                                                                                       #
#########################################################################################################

find_package(SFML 2 REQUIRED audio graphics network window system)


if(SFML_FOUND)

    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

endif()