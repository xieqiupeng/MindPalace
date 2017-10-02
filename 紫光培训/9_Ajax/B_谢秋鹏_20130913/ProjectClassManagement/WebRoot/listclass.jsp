<%@ page language="java" import="java.util.*,com.vo.ClassVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
ArrayList<ClassVO> list=(ArrayList<ClassVO>)request.getAttribute("list");
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
			    	<td>班级名称</td>
			    	<td>班主任</td>
			    	<td>班级介绍</td>
			    	<td>操作</td>
		    	</tr>
		<%
		    for (int i=0;i<list.size();i++)
		    {
		%>		
		    	<tr>
			    	<td><%=i+1 %></td>
			    	<td><%=list.get(i).getClassName() %></td>
			    	<td><%=list.get(i).getClassMaster() %></td>
			    	<td><%=list.get(i).getClassDescribe() %></td>
			    	<td>
			    		<a href="servlet/ServletDisableClass?classId=<%=list.get(i).getClassId() %>">删除</a>
			    		<a href="servlet/ServletToUpdateClass?classId=<%=list.get(i).getClassId() %>">修改</a>
					</td>
			   	</tr>
		<%    	
		   	} 
		%>
		    </table>
	    </form>
    </body>
</html>