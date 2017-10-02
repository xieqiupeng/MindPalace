<%@ page language="java" import="java.util.*,com.vo.ClassVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ClassVO classVo =(ClassVO)request.getAttribute("classVo");
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
		<form name="myForm" action="servlet/ServletUpdateClass" method="post">
			<input type="hidden" name="classId" value="<%=classVo.getClassId() %>"/>
			班级名称：<input type="text" name="className" value="<%=classVo.getClassName() %>"/>
			<br/>
			班主任：<input type="text" name="classMaster" value="<%=classVo.getClassMaster() %>"/>
			<br/>
			班级信息：<input type="text" name="classDescribe" value="<%=classVo.getClassDescribe() %>"/>
			<br/>
			<input type="submit" value="修改"/>
		</form>
	</body>
</html>