<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%String error = (String)request.getAttribute("error"); 
	if(error==null)
	{
		error="";
	}
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'userlogin.jsp' starting page</title>
    
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
			text-align:center;
		}
		tr
		{
			height:30px;
		}
	</style>
	<script type="text/javascript">
		function goRegister()
		{
			document.myForm.action="userinfo.jsp";
			document.myForm.submit();
		}
		function login()
		{
			document.myForm.action="servlet/UserLoginServlet";
			document.myForm.submit();
		}
	</script>
  </head>
  
  <body>
  	<center>
	  	<form name="myForm" action="" method="post">
	  		<table border="1" cellpadding="0" cellspacing="0" width="400">
	  			<tr>
	  				<td colspan="2">
	  					用户登陆
	  				</td>
	  			</tr>
	  			<tr>
	  				<td>
	  					用户名：
	  				</td>
	  				<td>
	  					<input style="float:left;" type="text" name="userName"/>
	  				</td>
	  			</tr>
	  			<tr>
	  				<td>
	  					密码：
	  				</td>
	  				<td>
	  					<input style="float:left;" type="password" name="userPassword"/><span style="color:red;"><%=error %></span>
	  				</td>
	  			</tr>
	  			<tr>
	  				<td colspan="2">
	  					<input type="button" value="登陆" onclick="login()" />
	  					<input type="button" value="注册" onclick="goRegister()" />
	  				</td>
	  			</tr>
	  		</table>
	  	</form>
  	</center>
  </body>
</html>
