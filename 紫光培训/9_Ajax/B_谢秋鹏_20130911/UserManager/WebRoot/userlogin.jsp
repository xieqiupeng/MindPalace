<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
String error =(String)request.getAttribute("error");
if (error==null)
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
	<script type="text/javascript" src="js/jquery-1.4.2.js"></script>
	<script type="text/javascript">
		$(document).ready(function (){
			$(":button[value='登陆']").click(function (){
				ajaxJudgeUserPassword();
			});
			$(":button[value='注册']").click(function (){
				goRegister();
			});
		});
		function goRegister()
		{
			document.myForm.action="userinfo.jsp";
			document.myForm.submit();
		}
		function login()
		{
			document.myForm.action="servlet/ServletUserList";
			document.myForm.submit();
		}
		function ajaxJudgeUserPassword()
		{
			$.ajax({
				url:"servlet/ServletAjaxJudgeUserPassword",
				type:"post",
				beforeSend:function(passValue){},
				data:"userName="+$("#userName").val()+ 
				"&userPassword="+$("#userPassword").val(),
				success:function(passValue){
					if(passValue=="false")
					{
						$("span").html("密码不正确。");
					}
					else if(passValue=="true")
					{
						$("span").html("登陆成功。");
						login();
					}
				}
			})
		}
	</script>
	<style type="text/css">
		span
		{
			color:red;
		}
		table
		{
			width:400px;
			border:2px solid black;
			border-collapse:collapse;
			margin:0px auto;
		}
		tr
		{
			text-align:center;
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
     <form name="myForm" action="" method="post"> 
	     <table> 
	     	<tr><td colspan="2"><h1>用户登录</h1></td></tr>
	     	<tr>
	    		<td>用户名：</td>
	    		<td>
	    			<input type="text" name="userName" id="userName"/>
	    		</td>
	    	</tr>
	   		<tr>
		    	<td>密码：</td>
		    	<td>
		    		<input type="text" name="userPassword" id="userPassword"/>
		    		<span><%=error %></span>
		    	</td>
	    	</tr>
	    	<tr>
	    		<td colspan="2">
	    		<input type="button" value="登陆"/>
	    		<input type="button" value="注册"/>
	    		</td>
	    	</tr>
	    </table>
    </form>
  </body>
</html>
