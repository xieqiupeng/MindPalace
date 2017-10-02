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
	<style type="text/css">
	</style>
  </head>
  
	<body>
		<form name="myForm" action="" method="get">
			<a href="insertclass.jsp" target="main">添加班级</a>
			<br/>
			<a href="servlet/ServletListClass" target="main">班级管理</a>
			<br/>
			<a href="insertcourse.jsp" target="main">添加课程</a>
			<br/>
			<a href="servlet/ServletListCourse" target="main">课程管理</a>
			<br/>
			<a href="servlet/ServletToInsertStudent" target="main">添加学生</a>
			<br/>
			<a href="servlet/ServletListStudent" target="main">学生管理</a>
		</form>
	</body>
</html>
