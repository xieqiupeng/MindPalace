<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'insertcourse.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript" src="jquery-1.4.2.js"></script>
	<script type="text/javascript">
	</script>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
	<body>
		<form name="myForm" action="servlet/ServletInsertCourse" method="post">
			课程名称：<input type="text" name="courseName"/><span></span>
			<br/>
			教师：<input type="text" name="teacherId"/>
			<br/>
			课程信息：<input type="text" name="courseDescribe"/>
			<br/>
			<input type="submit" value="添加"/>
		</form>
	</body>
</html>