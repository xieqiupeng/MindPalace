<%@ Page Language="C#" AutoEventWireup="true" CodeFile="支援地区信息.aspx.cs" Inherits="支援地区信息" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>支援地区信息</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        用户名<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" DataKeyNames="hname"
            DataSourceID="SqlDataSource1" Height="50px" Width="125px">
            <Fields>
                <asp:BoundField DataField="hname" HeaderText="hname" ReadOnly="True" SortExpression="hname" />
                <asp:BoundField DataField="hnumber" HeaderText="hnumber" SortExpression="hnumber" />
                <asp:BoundField DataField="hpassword" HeaderText="hpassword" SortExpression="hpassword" />
                <asp:BoundField DataField="haddress" HeaderText="haddress" SortExpression="haddress" />
                <asp:BoundField DataField="hdetail" HeaderText="hdetail" SortExpression="hdetail" />
                <asp:CommandField ShowEditButton="True" />
            </Fields>
        </asp:DetailsView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:DBTestConnectionString %>"
            DeleteCommand="DELETE FROM [help] WHERE [hname] = @hname" InsertCommand="INSERT INTO [help] ([hname], [hnumber], [hpassword], [haddress], [hdetail]) VALUES (@hname, @hnumber, @hpassword, @haddress, @hdetail)"
            SelectCommand="SELECT * FROM [help] WHERE ([hname] = @hname)" UpdateCommand="UPDATE [help] SET [hnumber] = @hnumber, [hpassword] = @hpassword, [haddress] = @haddress, [hdetail] = @hdetail WHERE [hname] = @hname">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" Name="hname" PropertyName="Text" Type="String" />
            </SelectParameters>
            <DeleteParameters>
                <asp:Parameter Name="hname" Type="String" />
            </DeleteParameters>
            <UpdateParameters>
                <asp:Parameter Name="hnumber" Type="String" />
                <asp:Parameter Name="hpassword" Type="String" />
                <asp:Parameter Name="haddress" Type="String" />
                <asp:Parameter Name="hdetail" Type="String" />
                <asp:Parameter Name="hname" Type="String" />
            </UpdateParameters>
            <InsertParameters>
                <asp:Parameter Name="hname" Type="String" />
                <asp:Parameter Name="hnumber" Type="String" />
                <asp:Parameter Name="hpassword" Type="String" />
                <asp:Parameter Name="haddress" Type="String" />
                <asp:Parameter Name="hdetail" Type="String" />
            </InsertParameters>
        </asp:SqlDataSource>
        &nbsp;
    
    </div>
    </form>
</body>
</html>
