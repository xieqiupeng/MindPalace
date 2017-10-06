<%@ Page language="c#" Codebehind="Uploadfile.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.Uploadfile" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>Index</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
		<script language="javascript">
		function rename()
		{
			window.document.all.re_filename.value="";
			if(window.document.all.re_filename.disabled==false)
			{
				window.document.all.re_filename.disabled=true;
			}
			else
			{
				window.document.all.re_filename.disabled=false;
			}
			
		}
		function star()
		{
			window.document.all.re_filename.disabled=true;
		}
		</script>
	</HEAD>
	<body MS_POSITIONING="GridLayout" onload="star();">
		<form id="Form1" runat="server" method="post" enctype="multipart/form-data">
			<TABLE cellSpacing="1" cellPadding="1" width="98%" align="center" bgColor="#6699ff" border="0">
				<TR>
					<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>上传文件</b></font></TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="#ffffff" height="100"><BR>
						<TABLE cellSpacing="1" cellPadding="1" width="90%" align="center" border="0">
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="120" height="7">选择文件本地路径：
								</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7">
									<input id="UpFile" type="file" runat="server" class="textibput"> <FONT face="宋体">支持上传WORD、PDF、EXCEL、DWG、JPG类型文件
									</FONT>
								</TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="100" height="7"><input type="checkbox" id="isrename" name="isrename" onclick="rename()">是否重命名：
								</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7">
									<asp:TextBox ID="re_filename" name="re_filename" Runat="server" class="textinput"></asp:TextBox>
								</TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px; HEIGHT: 17px" align="left" width="100" height="17">文件目标类别：
								</TD>
								<TD style="FONT-SIZE: 12px; HEIGHT: 17px" align="left" height="17">
									<asp:ListBox ID="filearea" Runat="server" Rows="1" Width="112px" Font-Size="12px">
										<asp:ListItem Value="A" Selected="True">A类文件组 </asp:ListItem>
										<asp:ListItem Value="B">B类文件组 </asp:ListItem>
										<asp:ListItem Value="C">C类文件组 </asp:ListItem>
									</asp:ListBox>
								</TD>
							</TR>
							<tr>
								<td height="5"></td>
							</tr>
							<TR>
								<TD style="FONT-SIZE: 12px" align="left" width="100" height="7">
								</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7">
									<asp:Button ID="bt_upfile" Runat="server" class="textinput" Text="确 定" onclick="bt_upfile_Click"></asp:Button>
								</TD>
							</TR>
						</TABLE>
					</TD>
				</TR>
			</TABLE>
		</form>
	</body>
</HTML>
