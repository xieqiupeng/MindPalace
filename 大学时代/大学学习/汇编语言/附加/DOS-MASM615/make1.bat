REM make.bat,for assembling and linking 16-bit programs (.COM)
ML /nologo /c /Fl /Sg /Zi %1.asm
if errorlevel 1 goto terminate
LINK /nologo /CODEVIEW /TINY %1.obj;
if errorlevel 1 goto terminate
DIR %1.*
:terminate
