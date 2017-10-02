<%@ page language="java" import="java.util.*,com.unis.kevin.vo.UserVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<jsp:useBean id="userList" scope="request" class="java.util.ArrayList">
</jsp:useBean>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'userlist.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

	<style type="text/css">
		table
		{
			border:1px solid red;
			width:400px;
			border-collapse:collapse;
			margin:auto;
			text-align:center;
		}
		td
		{
			border:1px solid red;
		}
		a
		{
			text-decoration:none;
			margin-right:10px;
		}
	</style>
  </head>
  
  <body>
    <form name="myForm" action="" method="get">
    	<table>
    		<tr>
    			<td width="50px">序号</td>
    			<td width="100px">用户名</td>
    			<td width="100px">密码</td>
    			<td width="150px">操作</td>
    		</tr>
    		<%
    			for(int i = 0;i < userList.size();i++){
    			UserVO userVo = (UserVO)userList.get(i);
    		%>
    			<tr>
    				<td><%=i+1 %></td>
    				<td><%=userVo.getUserName() %></td>
    				<td><%=userVo.getUserPassword() %></td>
    				<td align="center">
    					<a href="servlet/ServletUserInfo?userId=<%=userVo.getUserId() %>" target="_blank">查看</a>
    					<a href="servlet/ServletUserInfo?userId=<%=userVo.getUserId() %>" target="_blank">修改</a>
    					<a href="servlet/ServletUserInfo?userId=<%=userVo.getUserId() %>" target="_blank">删除</a>
    				</td>
    			</tr>
    		<%
    			}
    		%>
    	</table>
    </form>
  </body>
</html>
