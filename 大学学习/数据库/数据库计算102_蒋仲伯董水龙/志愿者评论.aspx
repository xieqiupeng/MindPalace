<%@ Page Language="C#" AutoEventWireup="true" CodeFile="志愿者评论.aspx.cs" Inherits="志愿者评论" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>志愿者评论</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名： &nbsp; &nbsp; &nbsp;
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
        ngo名： &nbsp; &nbsp; &nbsp;&nbsp;
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox><br />
        志愿者对ngo评论<asp:TextBox ID="TextBox3" runat="server"></asp:TextBox><br />
        &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="添加评论" /></div>
    </form>
</body>
</html>
