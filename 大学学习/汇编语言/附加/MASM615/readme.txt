MASM615.EXE软件包说明文件

1. 安装说明
在Windows下执行MASM615.EXE进行自解压，默认复制到D盘ML615文件夹（D:\ML615）。
用户可能需要修改Windows的ML615快捷方式。在Windows下，右击ML615快捷方式，选择“属性”，在其中程序对话框中：
如果你使用的COMMAND.COM文件不在D:\WINNT\SYSTEM32\文件夹，或者不是使用COMMAND.COM模拟DOS，则相应修改命令行栏的内容；
如果你不准备在D:\ML615文件夹下使用本软件包，则相应修改工作目录栏的内容。

2. MASM 6.15的汇编系统基本文件

ML.EXE    汇编程序
ML.ERR    汇编错误信息文件
LINK.EXE  连接程序
LIB.EXE   子程序库管理文件
tools.ini  配置文件
CV目录    CodeView调试程序CV.EXE以及配套的库文件
HELP目录  快速帮助文件QH.EXE，以及MASM宏汇编语言、汇编程序ML、连接程序LINK、调试程序CV等帮助文件
CLRFILE.CV4和CURRENT.STS是CodeView运行过程中生成的临时文件

3. 作者创建的文件

ML615        Windows快捷方式，进入DOS环境（COMMAND.COM）的MASM当前目录（D:\ML615）
MLL.BAT      产生列表文件的汇编快捷操作批处理文件
MAKE.BAT     生成CodeView调试信息的汇编快捷操作批处理文件（适用于SMALL，COMPACT，MEDIUM，LARGE和HUGE存储模式，生成EXE文件）
MAKE1.BAT    生成CodeView调试信息的汇编快捷操作批处理文件（仅适用于Tiny微型存储模式，生成COM可执行文件）
QH.BAT       展开各种帮助文件的批处理文件
CV.BAT       进入CodeView调试程序的批处理文件
example.asm  模板源程序文件（MASM 6.X适用，SMALL存储模式）
example.exe  模板文件对应的可执行文件
example.lst  模板文件对应的列表文件
example.obj  模板文件对应的模块文件
exampleb.asm 模板源程序文件（MASM 5.X适用）
examplec.asm 模板源程序文件（MASM 6.X适用，Tiny存储模式）
exampled.asm 模板源程序文件（MASM 6.X适用，带有IO.INC包含文件）
io.inc       I/O子程序库声明文件
io.lib       I/O子程序库