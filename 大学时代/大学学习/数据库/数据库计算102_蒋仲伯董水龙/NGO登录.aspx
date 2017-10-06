<%@ Page Language="C#" AutoEventWireup="true" CodeFile="NGO登录.aspx.cs" Inherits="NGO登录" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>NGO登录</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
        密码 &nbsp;<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>&nbsp;<br />
        &nbsp; &nbsp;
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="登录" /></div>
    </form>
</body>
</html>
