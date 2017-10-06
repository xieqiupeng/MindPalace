<%@ Page language="c#" Codebehind="UserList.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.UserList" %>
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
		<form id="Form1" method="post" runat="server">
			<TABLE cellSpacing="1" cellPadding="1" width="800" align="center" bgColor="#6699ff" border="0">
				<TR>
					<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>帐户列表</b></font></TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="#ffffff" height="30"><BR>
						<TABLE cellSpacing="1" cellPadding="1" width="700" align="center" border="0">
							<TR bgcolor='#0078cf'>
								<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
									<table width="100%">
										<tr>
											<td width="20%" align="center" style="FONT-SIZE:12px;COLOR:#ffffff">
												帐户名称
											</td>
											<td width="50%" align="center" style="FONT-SIZE:12px;COLOR:#ffffff">
												帐户角色
											</td>
											<td width="20%" align="center" valign="bottom">
											</td>
										</tr>
									</table>
								</TD>
							</TR>
							<asp:Label ID="userliststr" Runat="server"></asp:Label>
						</TABLE>
					</TD>
				</TR>
			</TABLE>
			<br>
			<br>
		</form>
	</body>
</HTML>
