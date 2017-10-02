<%@ page language="java" import="java.util.*,com.unis.user.vo.UserVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
/*UserVO userVo =(UserVO)request.getAttribute("userVo");*/
%>
<jsp:useBean id="userList" scope="request" class="java.util.ArrayList">
</jsp:useBean>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'success.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript">
		function check(value)
		{
			var objCheck=document.getElementsByName("row");
			for (i=0;i<objCheck.length;i++)
			{
				if("全选"===value)
				{
					objCheck[i].checked=true;
				}
				else if("反选"===value)
				{
					objCheck[i].checked=!objCheck[i].checked;
				}
			}
		}
		function deleteList()
		{
			alert(1);
			document.myForm.action="servlet/ServletDeleteUserList";
			document.myForm.method="post";
			document.myForm.submit();
		}
	</script>
	<style type="text/css">
			table
			{
				width:400px;
				border:2px solid black;
				border-collapse:collapse;
				margin:0px auto;
			}
			tr
			{
				text-align:center;
			}
			td
			{
				border:1px solid black;
			}
	</style>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <form name="myForm" action="" method="get">
    	<table border="1" align="center" cellpadding="0">
    		<tr align="center"> 
    			<td colspan="6">用户信息列表</td>
    		</tr>
    		<tr align="center">
    			<td>&nbsp;</td>
    			<td>用户名</td>
    			<td>密码</td>
    			<td>省份</td>
    			<td>城市</td>
    			<td>操作</td>
    		</tr>
    		<%
    			for(int i = 0;i < userList.size();i++){
    			UserVO userVo = (UserVO)userList.get(i);
    		%>
    			<tr>
    				<td>
    					<input type="checkbox" name="row" value="<%=userVo.getUserId() %>"/>
    				</td>
	    			<td>
	    				<%=userVo.getUserName() %>
	    			</td>
	    			<td><%=userVo.getUserPassword() %></td>
	    			<td><%=userVo.getProvince() %></td>
	    			<td><%=userVo.getCity() %></td>
	    			<td>
	    				<a href="servlet/ServletUserDelete?userId=<%= userVo.getUserId() %>">删除</a>
	    				<a href="servlet/ServletToUserUpdate?userId=<%= userVo.getUserId() %>">修改</a>
	    				<a href="servlet/ServletViewUser?userId=<%= userVo.getUserId() %>">查询</a>
	    			</td>
    			</tr>
    		<%
    			}
    		%>
    	</table>
    	<div align="center">
	    	<input type="button" value="全选" onclick="check(value)"/>
	    	<input type="button" value="反选" onclick="check(value)"/>
	    	<input type="button" value="批量删除" onclick="deleteList()"/>
    	</div>
    </form>
  </body>
</html>
