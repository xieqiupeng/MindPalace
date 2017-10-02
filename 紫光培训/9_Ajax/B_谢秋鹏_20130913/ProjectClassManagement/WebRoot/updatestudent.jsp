<%@ page language="java" import="java.util.*,com.vo.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ArrayList<ClassVO> classList=(ArrayList<ClassVO>)request.getAttribute("classList");
ArrayList<CourseVO> courseList=(ArrayList<CourseVO>)request.getAttribute("courseList");
StudentVO studentVo =(StudentVO)request.getAttribute("studentVo");
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
	<script type="text/javascript" src="js/jquery-1.4.2.js"></script>
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
				if(opt.value=='<%=studentVo.getClassId()%>')
		    	{
		    		opt.selected = "selected";
			   	}
		'<%	}
		%>'
		}
		function checkSex()
		{
			var checkObj = document.getElementsByName("studentSex");
		'<% if(studentVo.getStudentSex().equals("女"))
			{
		%>'
				checkObj[1].checked = "checked";
		'<% }
			else if(studentVo.getStudentSex().equals("男"))
			{
		%>'
				checkObj[0].checked = "checked";
		'<% }
		%>'
		}
	</script>
	<script type="text/javascript">
		$(document).ready(function(){
			addSelectOption();
			checkSex();
		});
	</script>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
	<body>
		<form name="myForm" action="servlet/ServletUpdateStudent" method="post">
			<input type="hidden" name="studentId" value="<%=studentVo.getStudentId() %>"/>
			学生姓名：
			<input type="text" name="studentName" value="<%=studentVo.getStudentName() %>"/>
			<span></span>
			<br/>
			性别：
			<input type="radio" name="studentSex" value="男"/>男
			<input type="radio" name="studentSex" value="女"/>女
			<br/>
			年龄：<input type="text" name="studentAge" value="<%=studentVo.getStudentAge() %>"/>
			<br/>
			专业：<input type="text" name="studentMajor" value="<%=studentVo.getStudentMajor() %>"/>
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
			<input type="submit" value="修改"/>
		</form>
	</body>
</html>