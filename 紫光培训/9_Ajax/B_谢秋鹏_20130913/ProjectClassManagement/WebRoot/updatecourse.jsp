<%@ page language="java" import="java.util.*,com.vo.CourseVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
CourseVO courseVo =(CourseVO)request.getAttribute("courseVo");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'insertclass.jsp' starting page</title>
    
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
		<form name="myForm" action="servlet/ServletUpdateCourse" method="post">
			<input type="hidden" name="courseId" value="<%=courseVo.getCourseId() %>"/>
			课程名称：<input type="text" name="courseName" value="<%=courseVo.getCourseName() %>"/>
			<br/>
			老师：<input type="text" name="teacherId" value="<%=courseVo.getTeacherId() %>"/>
			<br/>
			课程信息：<input type="text" name="courseDescribe" value="<%=courseVo.getCourseDescribe() %>"/>
			<br/>
			<input type="submit" value="修改"/>
		</form>
	</body>
</html>