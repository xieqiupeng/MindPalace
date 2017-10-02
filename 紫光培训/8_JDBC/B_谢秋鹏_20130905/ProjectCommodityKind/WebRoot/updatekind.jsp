<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<jsp:useBean id="userVo" scope="request" class="com.unis.kevin.vo.KindVO">
</jsp:useBean>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'userinfo.jsp' starting page</title>
    
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
    <form name="myForm" action="servlet/ServletUpdateKind" method="post">
		<input type="hidden" value="<%=userVo.getKindId() %>" name="userId"/>
		<br/>
		商品名称：
		<input type="text" value="<%=userVo.getKindName() %>" name="userName"/>
		<br/>
		商品类型：
		<input type="text" value="<%=userVo.getKindDescribe() %>" name="userDescribe"/>
		<input type="submit" value="修改"/>
    </form>
  </body>
</html>
