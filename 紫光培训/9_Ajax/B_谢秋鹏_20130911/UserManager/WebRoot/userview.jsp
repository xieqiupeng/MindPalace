<%@ page language="java" import="java.util.*,com.unis.user.vo.UserVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
UserVO userVo =(UserVO)request.getAttribute("userVo");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'userView.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<style type="text/css">
		table
		{
			width:400px;
			border:2px solid black;
			border-collapse:collapse;
			margin:0px auto;
		}
		td
		{
			border:1px solid black;
		}
	</style>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
  	<form action="servlet/ServletUserList" method="post">
    	<table>
    		<tr align="center"> 
    			<td colspan="2"><h1>用户注册信息</h1></td>
    		</tr>
    		<tr align="center">
    			<td>用户名：</td>
    			<td><%=userVo.getUserName() %></td>
    		</tr>
    		<tr align="center">
    			<td>密&nbsp;&nbsp;码：</td>
    			<td><%=userVo.getUserPassword() %></td>
    		</tr>
    		<tr align="center">
    			<td>地&nbsp;&nbsp;址：</td>
    			<td><%=userVo.getProvince()+"省"+userVo.getCity()+"市" %></td>
    		</tr>
    		<tr align="center">
    			<td>性&nbsp;&nbsp;别：</td>
    			<td><%=userVo.getUserSex() %></td>
    		</tr>
    		<tr align="center">
    			<td>爱&nbsp;&nbsp;好：</td>
    			<td><%=userVo.getUserSex() %></td>
    		</tr>
    		<tr align="center">
    			<td>个<br/>人<br/>描<br/>述<br/></td>
    			<td><%=userVo.getDescribe() %></td>
    		</tr>
    		<tr align="center">
    			<td colspan="2">
    				<input type="submit" value="返回"/>
    			</td>
    		</tr>
    	</table>
    </form>
  </body>
</html>
