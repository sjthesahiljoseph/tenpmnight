

@echo off

if not exist ..\build mkdir ..\build



pushd ..\build

del *.pdb > NUL 2 > NUL
echo WAITING FOR PDB > lock.tmp

cl -nologo -Zi -FC ..\code\win32_platform.c /link user32.lib gdi32.lib -incremental:no -opt:ref

del lock.tmp
del *.obj

win32_platform.exe

popd




