<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default2.aspx.cs" Inherits="Default2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>注册界面</title>
</head>

<body>

<h1 align="center">身份选择</h1>
<br />
<center>
    <form id="form1" runat="server">
    <div>
        <asp:RadioButton ID="志愿者" runat="server" OnCheckedChanged="志愿者_CheckedChanged" Text="志愿者" />
       
        <asp:RadioButton ID="NGO" runat="server" OnCheckedChanged="NGO_CheckedChanged" Text="NGO" />
       
        <asp:RadioButton ID="支援地区" runat="server" Text="支援地区"/><br />
        
        &nbsp;<asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="确定" /></div>
    </form>
</center>
</body>
</html>

