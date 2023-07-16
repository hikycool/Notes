# CCLS 问题

## clang 无法获取GCC标准库头文件

问题：

* OS：ubuntu-22.04
* GCC version: 11

Emacs读取工程文件时候，无法跳转到正确的标准库文件中，如：<iostream>

解决方法：

`apt install gcc-12 g++12`

可以让clang完整读取到头文件

