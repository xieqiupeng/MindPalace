<%@ Page Language="C#" AutoEventWireup="true" CodeFile="注册支援地区.aspx.cs" Inherits="注册支援地区" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>注册支援地区</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <span style="font-size: 24pt">&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
            &nbsp;&nbsp; 注册支援地区<br />
            &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <span style="font-size: 12pt">&nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; 名称：<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 密码：<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox><br />
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 电话：<asp:TextBox ID="TextBox3" runat="server"></asp:TextBox><br />
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 地址：<asp:TextBox ID="TextBox4" runat="server"></asp:TextBox><br />
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; 任务细节：<asp:TextBox ID="TextBox5" runat="server"></asp:TextBox><br />
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
                &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;
                <asp:Button ID="Button1" runat="server" Text="ok" OnClick="Button1_Click" /></span></span></div>
    </form>
</body>
</html>
