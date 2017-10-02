﻿<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
	<base href="<%=basePath%>">
	<title> XXXX注册 </title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<meta http-equiv="content-type" content="text/html; charset=GB2312"/>
	<link rel=stylesheet href="css/XXXXregister.css" type="text/css">
	<script src="js/jquery-1.4.2.js" type="text/javascript"></script>
	<script src="js/XXXXregister.js" type="text/javascript"></script>
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
		});
	</script>
	</head>
	
	<body>
		<!--页头布局-->
		<div id="divHead" class="layout">
			<div class="top1">logoPosition</div>
			<div class="top2">-注册</div>
			<div class="top3">
				<a href="#">XXXX首页</a>|
				<a href="#">帮助</a>
			</div>
		</div>
		<!--主题布局-->
		<div class="divContent layout">
			<div id="divTop"></div>
			<div id="divMiddle"><form action="servlet/ZhuCe">
			<!--表格布局-->
				<table id="resTable">
					<tr id="tr1">
						<td class="title" colspan="3">填写个人资料</td>
					</tr>
					<tr id="tr2">
						<td class="columnFirst tdright">
							<span class="red">*</span>用户名
						</td>
						<td class="columnSecond">
							<input type="text" name="userName" id="用户名"/>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr id="tr3">
						<td>&nbsp;</td>
						<td class="tip" colspan="2">
							6-16位字符（字母，数字）不区分大小写<br/>
						</td>
					</tr>
					<tr>
						<td class="tdright">
							<span class="red">*</span>性别
						</td>
						<td>
							<input type="radio" name="userSex" value="男" checked="checked"/>
							男
							<input type="radio" name="userSex" value="女"/>
							女
						</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>所在地区
						</td>
						<td>
							<input type="text" name="userSchool" value="请填写您的学校" id="学校" onfocus="setNull(this)"/>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red"></span>
						</td>
						<td>
							<input type="text" name="userDormitory" value="请填写宿舍号码" onfocus="setNull(this)" id="宿舍号码"/>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="title" colspan="3">
							设置安全信息
							<span class="tiphead">
								以下信息对保护您的安全信息极为重要，请慎重填写并牢记
							</span>
						</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>登录密码
						</td>
						<td>
							<input type="password" name="userPassword" id="密码"/>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="tr7">
						<td>&nbsp;</td>
						<td class="tip" colspan="2">
							6-16位字符（字母，数字）不区分大小写
						</td>
					</tr>
					<tr id="tr8">
						<td class="tdright">
							<span class="red">*</span>再次输入密码
						</td>
						<td>
							<input type="password" id="确认密码"/>
						</td>
						<td class="red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>手机号
						</td>
						<td class="columnSecond">
							<input type="text" name="userPhone" id="手机号"/>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright">
							<span class="red">*</span>有效证件号
						</td>
						<td class="columnSecond">
							<select name="idNumber">
								<option>身份证号</option>
								<option>学生证号</option>
							</select>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr id="">
						<td class="tdright"></td>
						<td class="columnSecond">
							<input type="text" id="有效证件号"/>
						</td>
						<td class="columnThird red">&nbsp;</td>
					</tr>
					<tr id="tr9">
						<td>&nbsp;</td>
						<td colspan="2">
							<input type="checkbox" checked="checked" id="agreeItem"/>我已经看过并同意
							<a href="#">《网络使用协议》</a>和
							<a href="#">《XXXX物流使用条款》</a>
						</td>
					</tr>
					<tr id="tr10">
						<td>&nbsp;</td>
						<td>
							<input type="button" value="提交" id="submit"/>
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
