<%@ page language="java" import="java.util.*,com.unis.user.vo.UserVo" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%ArrayList<UserVo> userList = (ArrayList<UserVo>)request.getAttribute("userList"); %>
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
	  <script type="text/javascript">
 		function checkAll()
 		{
 			var checkObj = document.getElementsByName("userId");
			for(var i=0;i<checkObj.length;i++)
			{
				checkObj[i].checked="checked";
			}
 		}
 		function checkNotAll()
 		{
 			var checkObj = document.getElementsByName("userId");
			for(var i=0;i<checkObj.length;i++)
			{
				checkObj[i].checked=!checkObj[i].checked;
			}
 		}
 		function deleteList()
 		{
 			document.listForm.action="servlet/ServletDeleteUserList";
 			document.listForm.submit();
 		}
  	  </script>
	<style type="text/css">
		.divHead
		{
			margin-left:150px;
		}
		.tableOne
		{
			border:1px solid black;
			border-collapse:collapse;
			width:400px;
			text-align:center;
		}
		.trOne
		{
			font-weight:bold;
			font-size:15px;
			
		}
		.tableOne td
		{
			border:1px solid black;
		}
	</style>
  </head>
  
  <body>
  	<center>
    <form name="listForm" action="servlet/ServletUserRegister" method="post">
    	<table class="tableOne">
    		<tr>
    			<td colspan="6"><b>用户信息列表</b></td>
    		</tr>
    		<tr class="trOne">
    			<td></td>
    			<td>用户名</td>
    			<td>密码</td>
    			<td>省份</td>
    			<td>城市</td>
    			<td>操作</td>
    		</tr>
    		<%for(int i=0;i<userList.size();i++){ %>
    		<tr>
				<td><input type="checkbox" name="userId" value="<%=userList.get(i).getUserId() %>"></td>
    			<td><a href="servlet/ServletViewUser?userId=<%=userList.get(i).getUserId() %>"><%=userList.get(i).getUserName() %></a></td>
    			<td><%=userList.get(i).getUserPassword() %></td>
    			<td><%=userList.get(i).getUserProvince() %></td>
    			<td><%=userList.get(i).getUserCity() %></td>
    			<td><a href="servlet/ServletUserDelete?userId=<%=userList.get(i).getUserId() %>">删除</a>&nbsp;&nbsp;
    			<a href="servlet/ServletToUserUpdate?userId=<%=userList.get(i).getUserId() %>">修改</a></td>
    		</tr>
    		<%} %>
    	</table>
    	<input type="button" value="全选" onclick="checkAll()"/>
    	<input type="button" value="反选" onclick="checkNotAll()"/>
    	<input type="button" value="批量删除" onclick="deleteList()"/>
    </form>
    </center>
  </body>
</html>
