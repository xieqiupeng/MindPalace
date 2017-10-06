<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
</head>
<body>
    <form id="form1" runat="server">
    <asp:GridView ID="GridView2" runat="server" AutoGenerateColumns="False" 
        BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px" 
        CellPadding="3" DataKeyNames="id" DataSourceID="AccessDataSource1">
        <RowStyle ForeColor="#000066" />
        <Columns>
            <asp:BoundField DataField="id" HeaderText="编号" InsertVisible="False" 
                ReadOnly="True" SortExpression="id" />
            <asp:BoundField DataField="filename" HeaderText="文件名称" 
                SortExpression="filename" />
            <asp:BoundField DataField="username" HeaderText="发起人" 
                SortExpression="username" />
            <asp:BoundField DataField="summary" HeaderText="主要内容" 
                SortExpression="summary" />
            <asp:BoundField DataField="parterner" HeaderText="发起陪同人" 
                SortExpression="parterner" />
            <asp:BoundField DataField="draft" HeaderText="起草" SortExpression="draft" />
            <asp:BoundField DataField="pdraft" HeaderText="陪同人确认" SortExpression="pdraft" />
            <asp:BoundField DataField="start" HeaderText="启动" SortExpression="start" />
            <asp:BoundField DataField="comment" HeaderText="评论" SortExpression="comment" />
            <asp:BoundField DataField="addtime" HeaderText="发起时间" 
                SortExpression="addtime" />
        </Columns>
        <FooterStyle BackColor="White" ForeColor="#000066" />
        <PagerStyle BackColor="White" ForeColor="#000066" HorizontalAlign="Left" />
        <SelectedRowStyle BackColor="#669999" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#006699" Font-Bold="True" ForeColor="White" />
    </asp:GridView>
    <asp:AccessDataSource ID="AccessDataSource1" runat="server" 
        DataFile="~/database/files.mdb" SelectCommand="SELECT * FROM [files]">
    </asp:AccessDataSource>
    <asp:GridView ID="GridView3" runat="server" AutoGenerateColumns="False" 
        BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px" 
        CellPadding="3" DataSourceID="AccessDataSource2">
        <RowStyle ForeColor="#000066" />
        <Columns>
            <asp:BoundField DataField="Pnum" HeaderText="编号" SortExpression="Pnum" />
            <asp:BoundField DataField="Patime" HeaderText="到达时间" SortExpression="Patime" />
            <asp:BoundField DataField="Pftime" HeaderText="完成时间" SortExpression="Pftime" />
            <asp:BoundField DataField="Cno" HeaderText="公文处理人" SortExpression="Cno" />
            <asp:BoundField DataField="Panswer" HeaderText="处理结果" 
                SortExpression="Panswer" />
            <asp:BoundField DataField="Pstate" HeaderText="状态" SortExpression="Pstate" />
            <asp:BoundField DataField="Pnextdept" HeaderText="下一个部门" 
                SortExpression="Pnextdept" />
            <asp:BoundField DataField="Ppredept" HeaderText="上一个部门" 
                SortExpression="Ppredept" />
        </Columns>
        <FooterStyle BackColor="White" ForeColor="#000066" />
        <PagerStyle BackColor="White" ForeColor="#000066" HorizontalAlign="Left" />
        <SelectedRowStyle BackColor="#669999" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#006699" Font-Bold="True" ForeColor="White" />
    </asp:GridView>
    <asp:AccessDataSource ID="AccessDataSource2" runat="server" 
        DataFile="~/database/files.mdb" SelectCommand="SELECT * FROM [PA]">
    </asp:AccessDataSource>
    </form>
</body>
</html>
