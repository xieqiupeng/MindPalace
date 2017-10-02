<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">




<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title></title>

</head>

<body >

    
<h1 align="center">校园导游咨询</h1>

<center>
    &nbsp;
        <asp:Image ID="Image1" runat="server" ImageUrl="~/untitled.jpg" Width="1076px" />
            
            
            

        <form runat="server" action="Default.aspx">
            <asp:Button ID="Button1" runat="server" Text="查询信息" OnClick="Button1_Click" />
            <asp:Button ID="Button2" runat="server" Text="查询路线" OnClick="Button2_Click" />
        </form>
    </center>


</body>


</html>;
