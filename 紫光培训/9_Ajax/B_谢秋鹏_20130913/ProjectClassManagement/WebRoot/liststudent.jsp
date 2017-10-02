<%@ page language="java" import="java.util.*,com.vo.StudentVO,com.vo.ClassVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ArrayList<StudentVO> studentList=(ArrayList<StudentVO>)request.getAttribute("studentList");
ArrayList<ClassVO> classList=(ArrayList<ClassVO>)request.getAttribute("classList");
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
	  	<form name="myForm" action="servlet/ServletListStudentByClass" method="get">
	  		<select name="classId" id="classId"></select>
	  		<input type="submit" value="查询"/>
		    <table>
		    	<tr>
			    	<td>序号</td>
			    	<td>学生姓名</td>
			    	<td>性别</td>
			    	<td>年龄</td>
			    	<td>专业</td>
			    	<td>班级</td>
			    	<td>操作</td>
		    	</tr>
		<%
		    for (int i=0;i<studentList.size();i++)
		    {
		%>		
		    	<tr>
			    	<td><%=i+1 %></td>
			    	<td><%=studentList.get(i).getStudentName() %></td>
			    	<td><%=studentList.get(i).getStudentSex() %></td>
			    	<td><%=studentList.get(i).getStudentAge() %></td>
			    	<td><%=studentList.get(i).getStudentMajor() %></td>
			    	<td><%=studentList.get(i).getClassName() %></td>
			    	<td>
			    		<a href="servlet/ServletDisableStudent?studentId=<%=studentList.get(i).getStudentId() %>">删除</a>
			    		<a href="servlet/ServletToUpdateStudent?studentId=<%=studentList.get(i).getStudentId() %>">修改</a>
						<a href="servlet/ServletListCourseByStudent?studentId=<%=studentList.get(i).getStudentId() %>">查看课程</a>
					</td>
			   	</tr>
		<%    	
		   	} 
		%>
		    </table>
	    </form>
    </body>
</html>
