AUX_SOURCE_DIRECTORY(. USER_DIR_SRC_DEMO)
ADD_LIBRARY ( USER_SRC_DEMO_LIB ${USER_DIR_SRC_DEMO})

#使用命令 ADD_SUBDIRECTORY 指明本项目包含一个子目录 firstchapter 
ADD_SUBDIRECTORY( firstchapter )
ADD_SUBDIRECTORY( start3d )
ADD_SUBDIRECTORY( camera )
ADD_SUBDIRECTORY( line )
# 链接库
TARGET_LINK_LIBRARIES(
    USER_SRC_DEMO_LIB 
    USER_SRC_DEMO_FIRST_CHAPTER_LIB 
    USER_SRC_DEMO_START_3D_LIB 
    USER_SRC_DEMO_CAMERA_LIB 
    USER_SRC_DEMO_LINE_LIB )
