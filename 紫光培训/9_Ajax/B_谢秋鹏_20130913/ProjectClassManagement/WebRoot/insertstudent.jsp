<%@ page language="java" import="java.util.*,com.vo.ClassVO,com.vo.CourseVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ArrayList<ClassVO> classList=(ArrayList<ClassVO>)request.getAttribute("classList");
ArrayList<CourseVO> courseList=(ArrayList<CourseVO>)request.getAttribute("courseList");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'insertstudent.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript">
		function addSelectOption()
		{
			var objSelect =document.getElementById("classId");
		'<% for (int i=0;i<classList.size();i++)
			{
				ClassVO classVo =new ClassVO();
				classVo = classList.get(i);
		%>'
				var opt= new Option();
				opt.text='<%=classVo.getClassName()%>';
				opt.value='<%=classVo.getClassId()%>';
				objSelect.options.add(opt);
		'<%	}
		%>'
		}
	</script>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
	<body onload="addSelectOption()">
		<form name="myForm" action="servlet/ServletInsertStudent" method="post">
			学生姓名：
			<input type="text" name="studentName"/><span></span>
			<br/>
			性别：
			<input type="radio" name="studentSex" value="男" checked="checked"/>男
			<input type="radio" name="studentSex" value="女"/>女
			<br/>
			年龄：<input type="text" name="studentAge"/>
			<br/>
			专业：<input type="text" name="studentMajor"/>
			<br/>
			班级：<select name="classId" id="classId"></select>
			<br/>
			选课：
		<%
			for(int i=0;i<courseList.size();i++)
			{
				CourseVO courseVo =courseList.get(i);
		%>
				<input type="checkbox" name="courseId" value="<%=courseVo.getCourseId() %>"/>
				<%=courseVo.getCourseName() %>
		<%
			}
		%>
			<br/>
			<input type="submit" value="添加"/>
		</form>
	</body>
</html>