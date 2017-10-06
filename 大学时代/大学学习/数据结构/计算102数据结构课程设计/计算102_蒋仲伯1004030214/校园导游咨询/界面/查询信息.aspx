<%@ Page Language="C#" AutoEventWireup="true" CodeFile="查询信息.aspx.cs" Inherits="查询信息" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>查询信息</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Label ID="Label1" runat="server" Text="查询"></asp:Label>
        <asp:TextBox ID="TextBox1" runat="server" OnTextChanged="TextBox1_TextChanged"></asp:TextBox>&nbsp;
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" DataKeyNames="Ino"
            DataSourceID="SqlDataSource1" Height="50px" Width="125px" OnPageIndexChanging="DetailsView1_PageIndexChanging">
            <Fields>
                <asp:BoundField DataField="Ino" HeaderText="Ino" ReadOnly="True" SortExpression="Ino" />
                <asp:BoundField DataField="Iname" HeaderText="Iname" SortExpression="Iname" />
                <asp:BoundField DataField="Infor" HeaderText="Infor" SortExpression="Infor" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DataStructConnectionString %>"
            SelectCommand="SELECT * FROM [Infor] WHERE ([Ino] = @Ino)" OnSelecting="SqlDataSource1_Selecting1">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="Ino" PropertyName="Text" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>
    </div>
    </form>
</body>
</html>
