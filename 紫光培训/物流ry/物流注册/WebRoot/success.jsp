<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

String userName = (String)request.getAttribute("userName");
String userPassword = (String)request.getAttribute("userPassword");
String userSex = (String)request.getAttribute("usersex");
String userSchool = (String)request.getAttribute("userSchool");
String userDormitory = (String)request.getAttribute("userDormitory");
String userPhone = (String)request.getAttribute("userPhone");
String idNumber = (String)request.getAttribute("idNumber");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
    	<base href="<%=basePath%>">
    	<title>注册成功</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
		<meta http-equiv="content-type" content="text/html; charset=GB2312"/>
		<link rel=stylesheet href="css/XXXXregister.css" type="text/css">
		<script src="js/jquery-1.4.2.js" type="text/javascript"></script>
		<script src="js/XXXXregister.js"></script>
		<script type="text/javascript">
			$(document).ready(function(){		
				//先判空后判字符
				var checkOne=false;
				$("input[type='text']").blur(function (){
					if (checkNull(this) ===false)
					{
						checkOne =checkString(this);
					}
				});
				//先判空后判字符,最后判等
				var checkTwo=false;
				$("input[type='password']").blur(function (){
					// alert(this.value);
					if (checkNull(this) ===false)
					{
						if(checkString(this) ===false)
						{
							checkTwo =checkEqual();
						}
					}
				});
				$("#submit").click(function(){
					submitAll(checkOne,checkTwo);
				});
			});
		</script>
	</head>
  
 	<body>
		<!--页头布局-->
		<div id="divHead" class="layout">
			<div class="top1">您的注册信息是</div>
			<div class="top2">-注册</div>
			<div class="top3">
				<a href="#">XXXX首页</a>|
				<a href="#">帮助</a>
			</div>
		</div>
		<!--主题布局-->
		<div class="divContent layout">
			<div id="divTop"></div>
			<div id="divMiddle"><form action="">
			<!--表格布局-->
				<table id="resTable">
					<tr id="tr2">
						<td class="columnFirst tdright">
							<span class="red">*</span>用户名
						</td>
						<td class="columnSecond">
							<%=userName %>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr>
						<td class="tdright">
							<span class="red">*</span>性别
						</td>
						<td>
							<%=userSex %>
						</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>所在地区
						</td>
						<td >
							<%=userSchool %>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright"><span class="red"></span>
						</td>
						<td >
							<%=userDormitory %>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="tr6">
						<td class="tdright">
							<span class="red">*</span>登录密码
						</td>
						<td >
							<%=userPassword %>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>手机号
						</td>
						<td class="columnSecond">
							<%=userPhone %>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>有效证件号
						</td>
						<td class="columnThird">
							<%=idNumber %>
						</td>
					</tr>
					<tr id="tr10">
						<td>&nbsp;</td>
						<td>
							<input type="button" value="返回" onclick="close()"/>
						</td>
						<td>&nbsp;</td>
					</tr>
				</table>
			</form>
			</div>
			<!--主题底部边框-->
			<div id="divBottom">			
			</div>
		</div>
		<!--页脚布局-->
		<div id="divFoot" class="layout">
			<div id="foot1">
				客户服务电话
				<a href="#">400-800-800</a>&nbsp;&nbsp;欢迎批评指正
			</div>		
			<div id="foot2">
				<a href="#">XXXX简介</a> | 
				<a href="#">about XXXX</a> | 
				<a href="#">广告服务</a> |
				<a href="#">联系我们</a> | 
				<a href="#">招聘信息</a> | 
				<a href="#">网站律师</a> | 
				<a href="#">XXXX English</a>| 
				<a href="#">会员注册</a> | 
				<a href="#">产品答疑</a>
			</div>
			<div id="foot3">
				Copyright@1996-2011 XXXX Corporation, All rights reserved. XXXX公司
				<a href="#">版权所有</a>
			</div>
		</div>
		<!--XXXXlogo布局-->
		<div id="divLogo"></div>
	</body>
</html>