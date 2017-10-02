<%@ page language="java" import="java.util.*,com.PackageVO.TeacherVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
TeacherVO teacherVo=(TeacherVO)request.getAttribute("teacherVo");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'teacherinfo.jsp' starting page</title>
    
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
    teacherinfo
    <table>
    <tr><td>序号：<%= teacherVo.getTeacherId() %></td></tr>
	<tr><td>编号：<%= teacherVo.getTeacherNum() %></td></tr>
	<tr><td>姓名：<%= teacherVo.getTeacherName() %> </td></tr>
	<tr><td>性别：<%= teacherVo.getTeacherSex() %></td></tr>
	<tr><td>出生日期：<%= teacherVo.getTeacherBirth() %></td></tr>
	<tr><td>入职时间：<%= teacherVo.getTeacherWorktime() %></td></tr>
	<tr><td>家庭住址：<%= teacherVo.getTeacherAddress() %></td></tr>
	</table>
  </body>
</html>
