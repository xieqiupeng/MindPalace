<%@ Page language="c#" Codebehind="FileList_m.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.FileList_m" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>Index</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
		<SCRIPT language="javascript1.2">
		
		</SCRIPT>
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<TABLE cellSpacing="1" cellPadding="1" width="800" align="center" bgColor="#6699ff" border="0">
				<TR>
					<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>文件列表</b>—</font><asp:Label Runat="server" ID="zu_file" Font-Size="10pt" Font-Italic="True" Font-Bold="True"
							ForeColor="White"></asp:Label></TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="#ffffff" height="30"><BR>
						<TABLE cellSpacing="1" cellPadding="1" width="700" align="center" border="0">
							<TR bgcolor='#0078cf'>
								<TD style="FONT-SIZE: 12px" align="left" width="100%" height="7">
									<table width="100%">
										<tr>
											<td width="20%" align="center" style="FONT-SIZE:12px;COLOR:#ffffff">
												文件名称
											</td>
											<td width="20%" align="center" style="FONT-SIZE:12px;COLOR:#ffffff">
												文件组
											</td>
											<td width="20%" align="center" valign="bottom" style="FONT-SIZE:12px;COLOR:#ffffff">
												文件类型
											</td>
											<td width="20%" align="center" valign="bottom" style="FONT-SIZE:12px;COLOR:#ffffff">
												添加时间
											</td>
											<td width="20%" align="center" valign="bottom" style="FONT-SIZE:12px;COLOR:#ffffff">
											</td>
										</tr>
									</table>
								</TD>
							</TR>
							<asp:Label ID="fileliststr" Runat="server"></asp:Label>
						</TABLE>
					</TD>
				</TR>
			</TABLE>
			<br>
			<br>
		</form>
	</body>
</HTML>
