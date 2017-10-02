<%@ Page Language="C#" AutoEventWireup="true" CodeFile="NGO信息.aspx.cs" Inherits="NGO信息" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>NGO信息</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" DataKeyNames="nname"
            DataSourceID="SqlDataSource1" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="nname" HeaderText="nname" ReadOnly="True" SortExpression="nname" />
                <asp:BoundField DataField="Npassword" HeaderText="Npassword" SortExpression="Npassword" />
                <asp:BoundField DataField="nnumber" HeaderText="nnumber" SortExpression="nnumber" />
                <asp:BoundField DataField="naddress" HeaderText="naddress" SortExpression="naddress" />
                <asp:CommandField ShowEditButton="True" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DBTestConnectionString %>"
            DeleteCommand="DELETE FROM [ngo] WHERE [nname] = @nname" InsertCommand="INSERT INTO [ngo] ([nname], [Npassword], [nnumber], [naddress]) VALUES (@nname, @Npassword, @nnumber, @naddress)"
            SelectCommand="SELECT * FROM [ngo] WHERE ([nname] = @nname)" UpdateCommand="UPDATE [ngo] SET [Npassword] = @Npassword, [nnumber] = @nnumber, [naddress] = @naddress WHERE [nname] = @nname">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="nname" PropertyName="Text" Type="String" />
            </SelectParameters>
            <DeleteParameters>
                <asp:Parameter Name="nname" Type="String" />
            </DeleteParameters>
            <UpdateParameters>
                <asp:Parameter Name="Npassword" Type="String" />
                <asp:Parameter Name="nnumber" Type="String" />
                <asp:Parameter Name="naddress" Type="String" />
                <asp:Parameter Name="nname" Type="String" />
            </UpdateParameters>
            <InsertParameters>
                <asp:Parameter Name="nname" Type="String" />
                <asp:Parameter Name="Npassword" Type="String" />
                <asp:Parameter Name="nnumber" Type="String" />
                <asp:Parameter Name="naddress" Type="String" />
            </InsertParameters>
        </asp:SqlDataSource>
        须评论志愿者名<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox><br />
        &nbsp; 评 &nbsp; &nbsp;&nbsp; 论&nbsp;
        <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox><br />
        <br />
        &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="添加评论" /></div>
    </form>
</body>
</html>
