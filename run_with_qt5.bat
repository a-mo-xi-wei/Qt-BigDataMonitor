@echo off
REM === 1. 设置 Qt5 环境变量（运行时 DLL 目录） ===
setlocal
set PATH=F:\Qt\5.15.2\mingw81_64\bin;%PATH%
REM === 2. 配置 CMake，生成 Ninja 构建文件 ===
cmake -S . -B cmake-build-release-mingw-qt-5_15_2 -G Ninja -DCMAKE_PREFIX_PATH=F:/Qt/5.15.2/mingw81_64

REM === 3. 编译项目 ===
cmake --build cmake-build-release-mingw-qt-5_15_2 --config Release

REM === 4. 运行程序 ===
start "" cmake-build-release-mingw-qt-5_15_2\BigDataMonitor.exe

endlocal
