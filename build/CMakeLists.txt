# CMake最低版本號要求
# 這一行功能在確定目前使用的 CMake 版本符合需求，當版本不滿足最低需求時會發出錯誤訊息。即使沒加上這一檢查仍然可以繼續完成建置工作，只是 CMake 會發出警告。
cmake_minimum_required(VERSION 3.0)

# 項目名稱
project(main)

#建立欲編譯文件列表
aux_source_directory(../src SRC_LIST)
#list(REMOVE_ITEM SRC_LIST "exclude.cpp") 

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

# 指定生成目標
add_executable(${PROJECT_NAME} ${SRC_LIST})
