<%@ Page Language="C#" AutoEventWireup="true" CodeFile="注册志愿者.aspx.cs" Inherits="注册志愿者" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>注册志愿者</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <span style="font-size: 16pt"><strong>注册志愿者</strong></span><center>
            
                用 户 名：
                <asp:TextBox ID="TextBoxUserName" runat="server" ></asp:TextBox><br />
                性 别：
                <asp:RadioButtonList ID="TextBoxList1" runat="server" RepeatDirection="Horizontal"
                    RepeatLayout="Flow">
                    <asp:ListItem Selected="True">男</asp:ListItem>
                    <asp:ListItem Selected="False">女</asp:ListItem>
                </asp:RadioButtonList><br />
                密 码：
                <asp:TextBox ID="TextBoxPwd" runat="server" ></asp:TextBox><br />
                生 日：
                <asp:TextBox ID="TextBoxBirth" runat="server" ></asp:TextBox><br />
                电 话：
                <asp:TextBox ID="TextBoxNumber" runat="server" ></asp:TextBox><br />
                地 址：
                <asp:TextBox ID="TextBoxAddress" runat="server" ></asp:TextBox><br />
                &nbsp;<asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="OK" />&nbsp;
        </center>
    
    </div>
    </form>
</body>
</html>
