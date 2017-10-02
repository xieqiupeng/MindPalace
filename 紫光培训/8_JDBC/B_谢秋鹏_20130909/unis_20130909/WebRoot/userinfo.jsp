<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
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
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
  </head>
  
  <body>
  	<center>
    <form name="myForm" action="servlet/ServletUserRegister"  method="post">
    	<table width="350" height="400" cellpadding="0" cellspacing="0" border="1">
    		<tr>
    			<td>
    				用户名：
    			</td>
    			<td>
    				<input type="text" name="userName" />
    			</td>
    		</tr>
    		<tr>
    			<td>
    				密码：
    			</td>
    			<td>
    				<input type="text" name="userPassword" />
    			</td>
    		</tr>
    		<tr>
    			<td>
    				地址：
    			</td>
    			<td>
    				
    				<select name="userProvince" >
    					<option value="河南">河南</option>
    					<option value="河南">河北</option>
    					<option value="河南">山东</option>
    				</select>
    				省
    				
    				<select name="userCity" >
    					<option value="郑州">郑州</option>
    					<option value="石家庄">石家庄</option>
    				</select>
    				市
    			</td>
    		</tr>
    		<tr>
    			<td>
    				性别：
    			</td>
    			<td>
    				<input type="radio" name="userSex" value="man" />男
    				
    				<input type="radio" name="userSex" value="woman" />女
    			</td>
    		</tr>
    		<tr>
    			<td>
    				爱好：
    			</td>
    			<td>
    				<input type="checkbox" name="userHobby" value="篮球"/>篮球
    				<input type="checkbox" name="userHobby" value="足球"/>足球
    				<input type="checkbox" name="userHobby" value="羽毛球"/>羽毛球
    				<input type="checkbox" name="userHobby" value="跑步"/>跑步
    			</td>
    		</tr>
    		
    		<tr>
    			<td>
    				个人介绍
    			</td>
    			<td>
    				<textarea name="userDescribe" rows="10" cols="30">
    				</textarea>
    			</td>
    		</tr>
    		<tr>
    			<td colspan="2">
    				<input type="submit" value="注册"/>
    			</td>
    		</tr>
    	</table>
    </form>
    </center>
  </body>
</html>
