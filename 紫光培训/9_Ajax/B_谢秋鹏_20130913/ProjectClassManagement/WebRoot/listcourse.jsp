<%@ page language="java" import="java.util.*,com.vo.CourseVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ArrayList<CourseVO> courseList=(ArrayList<CourseVO>)request.getAttribute("courseList");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'classlist.jsp' starting page</title>
    
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
	  	<form name="myForm" action="" method="get">
		    <table>
		    	<tr>
			    	<td>序号</td>
			    	<td>课程名称</td>
			    	<td>教师</td>
			    	<td>课程介绍</td>
			    	<td>操作</td>
		    	</tr>
		<%
		    for (int i=0;i<courseList.size();i++)
		    {
		%>		
		    	<tr>
			    	<td><%=i+1 %></td>
			    	<td><%=courseList.get(i).getCourseName() %></td>
			    	<td><%=courseList.get(i).getTeacherId() %></td>
			    	<td><%=courseList.get(i).getCourseDescribe() %></td>
			    	<td>
			    		<a href="servlet/ServletDisableCourse?courseId=<%=courseList.get(i).getCourseId() %>">删除</a>
			    		<a href="servlet/ServletToUpdateCourse?courseId=<%=courseList.get(i).getCourseId() %>">修改</a>
					</td>
			   	</tr>
		<%    	
		   	} 
		%>
		    </table>
	    </form>
    </body>
</html>
