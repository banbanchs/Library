## 图书管理系统 ##

### Build ###

Linux:

    make

Windows(mingw):

将`Makefile`中编译器改为`g++`，安装`mingw`，将数据文件(`data.txt`, `user.txt`)和界面`manager.cpp`转换为`gb2312`编码

最好将数据文件换行符格式转为dos格式CRLF

    mingw32-make

### Run ###

    ./book

