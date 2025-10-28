

@echo off

pushd ..\build

cl -nologo -Zi -FC ..\code\win32_platform.c user32.lib gdi32.lib

win32_platform.exe

popd




