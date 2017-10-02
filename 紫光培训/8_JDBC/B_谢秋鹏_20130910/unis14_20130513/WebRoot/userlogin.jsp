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
    
    <title>My JSP 'userinfo.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	  <script type="text/javascript">
 		function registerButton()
 		{
 			document.loginForm.action="userinfo.jsp";
 			document.loginForm.submit();
 		}
  	  </script>
	<style type="text/css">
		.tableOne
		{
			border:1px solid black;
			border-collapse:collapse;
			width:400px;
			text-align:center;
		}
		.tableOne td
		{
			border:1px solid black;
		}
	</style>
  </head>
  
  <body>
  <center>
    <form name="loginForm" action="servlet/UserloginServlet" method="post">
    	
    	<table class="tableOne">
    		
    		<tr>
    			<td colspan="2"><b>用户登录</b></td>
    		</tr>
    		<tr>
    			<td>用户名：</td>
    			<td><input style="float:left;margin-left:40px;" type="text" name="userName" size="19"/><span style="color: red;float:left;width:120px;font-size:12px;font-weight:bold;"></span></td>
    		</tr>
    		<tr>
    			<td>密&nbsp;&nbsp;&nbsp;&nbsp;码：</td>
    			<td><input style="float:left;margin-left:40px;" type="password" name="userPassword"/><span style="color: red;float:left;width:120px;font-size:12px;font-weight:bold;"><%=error %></span></td>
    		</tr>
    		<tr>
    			<td colspan="2"><input type="submit" value="登录"/>&nbsp;&nbsp;&nbsp;&nbsp;<input type="button" value="注册" onclick="registerButton()"/></td>
    		</tr>
    	</table>
    	<br/>
    	
    	
    </form>
    </center>
  </body>
</html>
