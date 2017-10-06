<%@ Page language="c#" Codebehind="EditUser.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.EditUser" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title></title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
		<script language="javascript">
		</script>
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<TABLE cellSpacing="1" cellPadding="1" width="98%" align="center" bgColor="#6699ff" border="0">
				<TR>
					<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>编辑帐户</b></font></TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="#ffffff" height="100"><BR>
						<TABLE cellSpacing="1" cellPadding="1" width="90%" align="center" border="0">
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="80" height="7">帐户名称</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7"><FONT face="宋体"><asp:textbox class="textinput" id="username" Runat="server" name="username" ReadOnly="True"></asp:textbox>(帐户名称不可修改)</FONT></TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="80" height="7">帐户原密码</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7"><asp:textbox class="textinput" id="password" Runat="server" name="password"></asp:textbox></TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="80" height="7">帐户新密码</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7"><asp:textbox class="textinput" id="password2" Runat="server" name="password2"></asp:textbox></TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px; HEIGHT: 6px" align="left" width="80" height="6">帐户角色</TD>
								<TD style="FONT-SIZE: 12px; HEIGHT: 6px" align="left" height="6"><asp:listbox id="selrole" Runat="server" name="selrole" Rows="1" Width="155px" AutoPostBack="True"></asp:listbox></TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="80" height="7"></TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7"><asp:button class="textinput" id="adduser" Runat="server" Text="确 定" onclick="adduser_Click"></asp:button>&nbsp;<asp:Button ID="deluser" Runat="server" class="textinput" Text="删 除" onclick="deluser_Click"></asp:Button></TD>
							</TR>
						</TABLE>
					</TD>
				</TR>
			</TABLE>
			<br>
			<br>
		</form>
	</body>
</HTML>
