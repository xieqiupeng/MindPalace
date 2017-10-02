<%@ Page language="c#" Codebehind="Login.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.Login" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>公文管理系统</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="Visual Basic .NET 7.1" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
	    <style type="text/css">
            .style1
            {
                width: 198px;
            }
        </style>
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<table height="100" cellSpacing="0" cellPadding="0" width="800" align="center" border="0">
			<tr>
				<td height="60"></td>
			</tr>
			<tr>
				<td align="center" width="100%"><IMG src="img/title.gif" 
                        style="width: 504px; height: 135px">
				</td>
			</tr>
			<tr alige="middle" width="100%">
				<td align="center" width="100%">
					<table cellSpacing="1" align="center" bgColor="#0078cf" 
                        style="width: 298px; height: 210px">
						<tr>
							<td align="center" width="280" bgColor="#ffffff">
								<table style="width: 292px; height: 181px">
									<form id="Form1" method="post" runat="server">
										<TBODY>
											<tr>
												<td width="90" bgColor="#ffffff"><font class="font_13px ">用户名：</font>
												</td>
												<td bgColor="#ffffff" class="style1"><asp:textbox class="TextInput" id="username" tabIndex="1" Runat="server"></asp:textbox></td>
											</tr>
											<tr>
												<td width="80" bgColor="#ffffff"><font class="font_13px ">密码：</font>
												</td>
												<td bgColor="#ffffff" class="style1"><asp:textbox class="TextInput" id="password" tabIndex="2" Runat="server" TextMode="Password"></asp:textbox></td>
											</tr>
											<tr>
												<td colSpan="2" height="10">
                                                    <asp:RadioButtonList ID="RadioButtonList1" runat="server" 
                                                        DataSourceID="AccessDataSource1" DataTextField="Crank" DataValueField="Crank">
                                                    </asp:RadioButtonList>
                                                    <asp:AccessDataSource ID="AccessDataSource1" runat="server" 
                                                        DataFile="~/database/files.mdb" 
                                                        SelectCommand="SELECT distinct [Crank] FROM [Clerk]"></asp:AccessDataSource>
                                                </td>
											</tr>
											<tr>
												<td width="80" bgColor="#ffffff"><font class="font_13px "></font></td>
												<td bgColor="#ffffff" class="style1">&nbsp;
													<asp:button id="loginin" tabIndex="3" Runat="server" Text="确 定" onclick="loginin_Click"></asp:button>
													<asp:button id="cancel" tabIndex="4" Runat="server" Text="取 消"></asp:button></td>
											</tr>
									</form>
								</table>
							</td>
						</tr>
					</table>
				</td>
			</tr>
			</TBODY></table>
		</FORM>
	</body>
</HTML>
