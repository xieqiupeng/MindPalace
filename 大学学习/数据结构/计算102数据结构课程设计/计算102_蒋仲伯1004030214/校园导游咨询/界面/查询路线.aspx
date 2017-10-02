<%@ Page Language="C#" AutoEventWireup="true" CodeFile="查询路线.aspx.cs" Inherits="查寻路线" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>查询路线</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        查询路径<asp:TextBox ID="TextBox1" runat="server" OnTextChanged="TextBox1_TextChanged1"></asp:TextBox><br />
    
    </div>
        &nbsp; &nbsp;
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False"
            DataKeyNames="way" DataSourceID="SqlDataSource1" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="way" HeaderText="way" ReadOnly="True" SortExpression="way" />
                <asp:BoundField DataField="dis" HeaderText="dis" SortExpression="dis" />
                <asp:BoundField DataField="route" HeaderText="route" SortExpression="route" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DataStructConnectionString %>"
            SelectCommand="SELECT * FROM [search] WHERE ([way] = @way)">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="way" PropertyName="Text" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>
    </form>
</body>
</html>
