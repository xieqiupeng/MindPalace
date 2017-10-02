<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

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
	<script type="text/javascript" src="jquery-1.4.2.js"></script>
	<script type="text/javascript">
	</script>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
	<body>
		<form name="myForm" action="servlet/ServletInsertClass" method="post">
			班级名称：<input type="text" name="className"/><span></span>
			<br/>
			班主任：<input type="text" name="classMaster"/>
			<br/>
			班级信息：<input type="text" name="classDescribe"/>
			<br/>
			<input type="submit" value="添加"/>
		</form>
	</body>
</html>