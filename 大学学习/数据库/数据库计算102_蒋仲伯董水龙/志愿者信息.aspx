<%@ Page Language="C#" AutoEventWireup="true" CodeFile="志愿者信息.aspx.cs" Inherits="志愿者信息" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>志愿者信息</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名：<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br />
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" DataKeyNames="vname"
            DataSourceID="SqlDataSource1" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="vname" HeaderText="vname" ReadOnly="True" SortExpression="vname" />
                <asp:BoundField DataField="vsex" HeaderText="vsex" SortExpression="vsex" />
                <asp:BoundField DataField="Vpassword" HeaderText="Vpassword" SortExpression="Vpassword" />
                <asp:BoundField DataField="vbirth" HeaderText="vbirth" SortExpression="vbirth" />
                <asp:BoundField DataField="vnumber" HeaderText="vnumber" SortExpression="vnumber" />
                <asp:BoundField DataField="vaddress" HeaderText="vaddress" SortExpression="vaddress" />
                <asp:CommandField ShowEditButton="True" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DBTestConnectionString %>"
            DeleteCommand="DELETE FROM [volunteer] WHERE [vname] = @vname" InsertCommand="INSERT INTO [volunteer] ([vname], [vsex], [Vpassword], [vbirth], [vnumber], [vaddress]) VALUES (@vname, @vsex, @Vpassword, @vbirth, @vnumber, @vaddress)"
            SelectCommand="SELECT * FROM [volunteer] WHERE ([vname] = @vname)" UpdateCommand="UPDATE [volunteer] SET [vsex] = @vsex, [Vpassword] = @Vpassword, [vbirth] = @vbirth, [vnumber] = @vnumber, [vaddress] = @vaddress WHERE [vname] = @vname">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="vname" PropertyName="Text" Type="String" />
            </SelectParameters>
            <DeleteParameters>
                <asp:Parameter Name="vname" Type="String" />
            </DeleteParameters>
            <UpdateParameters>
                <asp:Parameter Name="vsex" Type="String" />
                <asp:Parameter Name="Vpassword" Type="String" />
                <asp:Parameter Name="vbirth" Type="String" />
                <asp:Parameter Name="vnumber" Type="String" />
                <asp:Parameter Name="vaddress" Type="String" />
                <asp:Parameter Name="vname" Type="String" />
            </UpdateParameters>
            <InsertParameters>
                <asp:Parameter Name="vname" Type="String" />
                <asp:Parameter Name="vsex" Type="String" />
                <asp:Parameter Name="Vpassword" Type="String" />
                <asp:Parameter Name="vbirth" Type="String" />
                <asp:Parameter Name="vnumber" Type="String" />
                <asp:Parameter Name="vaddress" Type="String" />
            </InsertParameters>
        </asp:SqlDataSource>
        <asp:DetailsView ID="DetailsView2" runat="server" AutoGenerateRows="False" DataKeyNames="hname"
            DataSourceID="SqlDataSource2" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="hname" HeaderText="hname" ReadOnly="True" SortExpression="hname" />
                <asp:BoundField DataField="haddress" HeaderText="haddress" SortExpression="haddress" />
                <asp:BoundField DataField="hdetail" HeaderText="hdetail" SortExpression="hdetail" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:DBTestConnectionString %>"
            SelectCommand="SELECT [hname], [haddress], [hdetail] FROM [help]"></asp:SqlDataSource>
        <asp:DetailsView ID="DetailsView3" runat="server" AutoGenerateRows="False" DataKeyNames="nname"
            DataSourceID="SqlDataSource3" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="nname" HeaderText="nname" ReadOnly="True" SortExpression="nname" />
                <asp:BoundField DataField="naddress" HeaderText="naddress" SortExpression="naddress" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:DBTestConnectionString %>"
            SelectCommand="SELECT [nname], [naddress] FROM [ngo]"></asp:SqlDataSource>
        <br />
        志愿者名：
        <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox><br />
        ngo名：<asp:TextBox ID="TextBox3" runat="server"></asp:TextBox><br />
        支援单位名：<asp:TextBox ID="TextBox4" runat="server"></asp:TextBox><br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="申请" />
        <asp:Button ID="Button2" runat="server" Text="评论" OnClick="Button2_Click" /></div>
    </form>
</body>
</html>
