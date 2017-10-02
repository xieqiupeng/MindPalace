<%@ page language="java" import="java.util.*,com.PackageVO.TeacherVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
//TeacherVO teachervo=(TeacherVO)request.getAttribute("teachervo");
%>
<jsp:useBean id="voList" scope="request" class="java.util.ArrayList">
</jsp:useBean>


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'teacherlist.jsp' starting page</title>
    
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
    <form action="" method="get">
		teacherlist
	    <table>
	  		<tr>
	  			<td>序号</td>
	  			<td>编号</td>
	  			<td>姓名</td>
	  			<td>性别</td>
	  			<td>出生日期</td>
	  			<td>入职时间</td>
	  			<td>家庭住址</td>
	  		</tr>
	  		<%
	  		for(int i=0;i<voList.size();i++){
	  			TeacherVO teacherVo =(TeacherVO)voList.get(i);
	  		%>
	  		<tr>
	  			<td><%=i+1 %></td>
	  			<td><%=teacherVo.getTeacherNum() %></td>
	  			<td><%=teacherVo.getTeacherName() %></td>
	  			<td><%=teacherVo.getTeacherSex() %></td>
	  			<td><%=teacherVo.getTeacherBirth() %></td>
	  			<td><%=teacherVo.getTeacherWorktime() %></td>
	  			<td><%=teacherVo.getTeacherAddress() %></td>
	  			<td align="center">
    				<a href="servlet/ServletTeacherInfo?teacherId=<%=teacherVo.getTeacherId() %>" target="_blank">查看</a>
    				<a href="servlet/ServletToUpdateTeacher?teacherId=<%=teacherVo.getTeacherId() %>" target="_blank">修改</a>
    				<a href="servlet/ServletDisableTeacher?teacherId=<%=teacherVo.getTeacherId() %>" target="_blank">删除</a>
    			</td>
    	<% }
    	%>	
	  		</tr>
	  	</table>
	</form>
  </body>
</html>
