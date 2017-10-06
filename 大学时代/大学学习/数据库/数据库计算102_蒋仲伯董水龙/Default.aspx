<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">




<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title></title>
</head>

<body >

    
<h1 align="center">NGO管理系统</h1>

<center>
<form id="Form1" action="Default.aspx" runat="server">
<br />


身份：<asp:DropDownList ID="DropDownList1" runat="server" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
        <asp:ListItem>志愿者</asp:ListItem>
        <asp:ListItem>NGO</asp:ListItem>
        <asp:ListItem>支援地区</asp:ListItem>
    </asp:DropDownList>
    &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;
     
    <br />
    
    <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="注册" />

    <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="登录" />&nbsp;
    
    </form> 
    <asp:Image ID="Image1" runat="server" ImageUrl="~/1.jpg" /></center>




</body>
</html>;
