<%@ page language="java" import="java.util.*,com.unis.user.vo.UserVo" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%UserVo userVo = (UserVo)request.getAttribute("userVo"); %>
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
    function showProvince()
	{
	  var province = ["河南","河北","山东"];
	  var provinceObj = document.getElementById("province_id");
	  for (var i=0;i<province.length;i++)
	  {
	    var newProvince = new Option();
		newProvince.text = province[i];
        newProvince.value = province[i];
        provinceObj.options.add(newProvince);
        if(newProvince.value  ==  '<%=userVo.getUserProvince()%>')
        {
        	newProvince.selected="true";
        }
	  }
	}
	function showCity()
	{
	  var city = [["郑州","濮阳"],["石家庄","秦皇岛"],["烟台","菏泽"]];
	  var provinceObj = document.getElementById("province_id");
	  var cityObj = document.getElementById("city_id");
	  cityObj.length = 0;
	  var provinceIndex = provinceObj.selectedIndex;
	  for (var j=0;j<city[provinceIndex].length;j++)
	  {
	    var newCity = new Option();
        newCity.text = city[provinceIndex][j];
        newCity.value = city[provinceIndex][j];
        cityObj.options.add(newCity);
        if(newCity.value == '<%=userVo.getUserCity()%>')
        {
        	newCity.selected = "true";
        }
	  }
	}
	function checkHobby()
	{
		var hobbyValue = '<%=userVo.getUserHobby()%>';
		var hobbyArray = hobbyValue.split(",");
		var checkObj = document.getElementsByName("userHobby");
		for(var j=0;j<checkObj.length;j++)
		{
			for(var i=0;i<hobbyArray.length;i++)
			{
				if(hobbyArray[i]==checkObj[j].value)
				{
					checkObj[j].checked = "checked";
				}
			}
		}
		
		
	}
  </script>
	<style type="text/css">
		.tableOne
		{
			border:1px solid black;
			border-collapse:collapse;
			width:400px;
			text-align:center;
		}
		.tableOne td
		{
			border:1px solid black;
			height:40px;
		}
	</style>
  </head>
  
  <body>
  <center>
    <form name="registerForm" action="servlet/ServletUserReturn" method="post">
    	<table class="tableOne">
    		<tr>
    			<td colspan="2"><b>用户查看</b></td>
    		</tr>
    		<tr>
    			<td>用户名：</td>
    			<td><%=userVo.getUserName() %></td>
    		</tr>
    		<tr>
    			<td>密&nbsp;&nbsp;&nbsp;&nbsp;码：</td>
    			<td><%=userVo.getUserPassword() %></td>
    		</tr>
    		<tr>
    			<td>地&nbsp;&nbsp;&nbsp;&nbsp;址：</td>
    			<td>
    				<%=userVo.getUserProvince() %>省
    				<%=userVo.getUserCity() %>市
    			</td>
    		</tr>
    		<tr>
    			<td>性&nbsp;&nbsp;&nbsp;&nbsp;别：</td>
    			<td>
    				<%=userVo.getUserSex() %>
    			</td>
    		</tr>
    		<tr>
    			<td>爱&nbsp;&nbsp;&nbsp;&nbsp;好：</td>
    			<td>
    				<%=userVo.getUserHobby() %>
    			</td>
    		</tr>
    		<tr>
    			<td style="text-align: center;height:150px;">个<br/>人<br/>描<br/>述</td>
    			<td>
    				<%=userVo.getUserDescribe() %>
    			</td>
    		</tr>
    		<tr>
    			<td colspan="2"><input type="submit" value="返回"/></td>
    		</tr>
    	</table>
    </form>
    </center>
  </body>
</html>
