REM make.bat,for assembling and linking 16-bit programs (.EXE)
ML /nologo /c /Fl /Sg /Zi %1.asm
if errorlevel 1 goto terminate
LINK /nologo /CO %1.obj;
if errorlevel 1 goto terminate
DIR %1.*
:terminate
