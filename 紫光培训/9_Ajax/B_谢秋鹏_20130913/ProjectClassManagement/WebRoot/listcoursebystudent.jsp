<%@ page language="java" import="java.util.*,com.vo.StudentVO,com.vo.CourseVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
StudentVO studentVo =(StudentVO)request.getAttribute("studentVo");
ArrayList<String> courseNameArray =(ArrayList<String>)request.getAttribute("courseNameArray");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'listcoursebystudent.jsp' starting page</title>
    
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
		<form name="myForm" action="" method="post">
			学生姓名：
			<%=studentVo.getStudentName() %>
			<br/>
			性别：
			<%=studentVo.getStudentSex() %>
			<br/>
			年龄：
			<%=studentVo.getStudentAge() %>
			<br/>
			专业：
			<%=studentVo.getStudentMajor() %>
			<br/>
			班级：
			<%=studentVo.getClassName() %>
			<br/>
			已选课程:
			<br/>
		<% 
			for (int i=0;i<courseNameArray.size();i++)
			{	
		%>
				<b><%=courseNameArray.get(i) %></b>&nbsp;&nbsp;
		<%
			}
		%>
		</form>
	</body>
</html>
