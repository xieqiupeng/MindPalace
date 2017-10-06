<%@ Page language="c#" Codebehind="Index.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.Index" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>Index</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<TABLE cellSpacing="1" cellPadding="1" width="98%" align="center" bgColor="#6699ff" border="0">
			<TR>
				<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>系统说明：</b></font></TD>
			</TR>
			<TR>
				<TD vAlign="top" bgColor="#ffffff" height="100"><BR>
					<TABLE cellSpacing="1" cellPadding="1" width="90%" align="center" border="0">
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
								1.使用步骤：(1)默认的管理员admin可以在后台创建编辑删除角色、用户、文件。<br />
                                (2)本系统设置的为高层管理人员：总经理，副总经理拥有全部权限，其他员工只拥有查看文献的功能。<br><br>
						
							</TD>
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
								2.用户权限级别越高，显示的文件类型越多；管理员(拥有所有权限的用户)可以看到全部类型文件，不同权限的用户显示在右侧的文件不同。<br><br>
								
							</TD>
						</TR>
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
								3.左上侧把文件分为A B C 三组，供用户查看；权限不同看到的文件类型不同；如：用户1仅可以看到Doc文件 
									，用户2可以看到Doc和Jpg文件，管理员可以看到全部类型文件。目前系统支持Doc Jpg Pdf Xsl Dwg 五种文件。<br><br>
								
							</TD>
						</TR>
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
								4.上传控制文件类型，仅Doc Xsl Dwg Jpg Pdf文件可以上传。<br><br>
								
							</TD>
						</TR>
						
						
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">5.后台部分，仅管理员可以登录，管理员指拥有查看所有文件权限的用户。<br><br></TD>
						</TR>
					</TABLE>
				</TD>
			</TR>
			<TR>
				<TD vAlign="top" bgColor="#ffffff" height="50">
					<TABLE cellSpacing="1" cellPadding="1" width="90%" align="center" border="0">
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">登陆用户：<asp:label id="username" Runat="server"></asp:label></TD>
						</TR>
						<TR>
							<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">用户权限：<asp:label id="role" Runat="server"></asp:label></TD>
						</TR>
					</TABLE>
				</TD>
			</TR>
		</TABLE>
		<br>
		<br>
	</body>
</HTML>
