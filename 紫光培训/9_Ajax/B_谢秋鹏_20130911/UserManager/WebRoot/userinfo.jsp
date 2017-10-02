<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript" src="js/jquery-1.4.2.js"></script>
	<script type="text/javascript" src="js/linkedCities.js" charset="GB2312"></script>
	<script type="text/javascript">
		function ajaxJudgeUserName()
		{
			$.ajax({
				url:"servlet/ServletAjaxJudgeUserName",
				type:"post",
				beforeSend:function(passValue){},
				data:"userName="+$("#userName").val(),
				success:function(passValue){
					if(passValue=="true")
					{
						$(".userName").html("用户名可用。");
					}
					else
					{
						$(".userName").html("此用户名已被占用。");
					}
				}
			})
		}
		$(document).ready(function (){
			addProvinceOption();
			addCityOption();
			$("#province").change(function (){
				addCityOption();
			});
			$("#userName").blur(function (){
				ajaxJudgeUserName();
			});
		});
	</script>
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
	</head>
  
  <body>
    <form action="servlet/ServletUserRegister" method="post">
    	<table>
    		<tr align="center"> 
    			<td colspan="2">用户注册</td>
    		</tr>
    		<tr align="center">
    			<td>用户名：</td>
    			<td>
    				<input type="text" name="userName" id="userName"/>
    				<span class="userName"></span>
    			</td>
    		</tr>
    		<tr align="center">
    			<td>密&nbsp;&nbsp;码：</td>
    			<td>
    				<input type="password" name="userPassword"/>
    			</td>
    		</tr>
    		<tr align="center">
    			<td>地&nbsp;&nbsp;址：</td>
    			<td>
    				<select name="province" id="province">
    				
    				</select>
    				<select name="city" id="city">
    				
    				</select>
				</td>
    		</tr>
    		<tr align="center">
    			<td>性&nbsp;&nbsp;别：</td>
    			<td>
    				<input type="radio" name="userSex" value="男" checked="checked"/>男
    				<input type="radio" name="userSex" value="女"/>女
    			</td>
    		</tr>
    		<tr align="center">
    			<td>爱&nbsp;&nbsp;好：</td>
    			<td>
    				<input type="checkbox" name="hobby" value="篮球"/>篮球
    				<input type="checkbox" name="hobby" value="足球"/>足球
    				<input type="checkbox" name="hobby" value="羽毛球"/>羽毛球
    				<input type="checkbox" name="hobby" value="跑步"/>跑步
    			</td>
    		</tr>
    		<tr align="center">
    			<td>个<br/>人<br/>描<br/>述<br/></td>
    			<td><textarea name="describe"></textarea></td>
    		</tr>
    		<tr align="center">
    			<td colspan="2">
    				<input type="submit" value="提交"/>
    			</td>
    		</tr>
    	</table>
    </form>
  </body>
</html>
