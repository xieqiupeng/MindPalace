<%@ page language="java" import="java.util.*,com.unis.user.vo.UserVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
UserVO userVo = (UserVO)request.getAttribute("userVo");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'userupdate.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript" src="js/jquery-1.4.2.js"></script>
	<script type="text/javascript">
	function showProvince()
	{
	  var province = ["河南","河北","山东"];
	  var provinceObj = document.getElementById("province");
	  for (var i=0;i<province.length;i++)
	  {
	    var newProvince = new Option();
		newProvince.text = province[i];
        newProvince.value = province[i];
        provinceObj.options.add(newProvince);
        if(newProvince.value=='<%=userVo.getProvince()%>')
        {
        	newProvince.selected="true";
        }
	  }
	}
	function showCity()
	{
		var city = [["郑州","濮阳"],["石家庄","秦皇岛"],["烟台","菏泽"]];
		var provinceObj = document.getElementById("province");
		var cityObj = document.getElementById("city");
		cityObj.length = 0;
		var provinceIndex = provinceObj.selectedIndex;
		for (var j=0;j<city[provinceIndex].length;j++)
		{
			var newCity = new Option();
		    newCity.text = city[provinceIndex][j];
		    newCity.value = city[provinceIndex][j];
		    cityObj.options.add(newCity);
		    if(newCity.value == '<%=userVo.getCity()%>')
		    {
		    	newCity.selected = "true";
		    }
		}
	}
	function checkHobby()
	{
		var hobbyValue = '<%=userVo.getHobby()%>';
		var hobbyArray = hobbyValue.split("，");
		var checkObj = document.getElementsByName("hobby");
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
	function checkSex()
	{
		var checkObj = document.getElementsByName("userSex");
		if('<%=userVo.getUserSex().equals("男")%>')
		{
			checkObj[0].checked = "checked";
		}
		else if('<%=userVo.getUserSex().equals("女")%>')
		{
			checkObj[1].checked = "checked";
		}
	
	}
		$(document).ready(function (){
			showProvince();
			showCity();
			checkHobby();
			checkSex()
			$("#province").change(function(){
				showCity();
			});
		});
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
    <form action="servlet/ServletUserUpdate" method="post">
    	<input type="hidden" name="userId" value="<%=userVo.getUserId()  %>"/>
    	<table border="1" align="center">
    		<tr align="center"> 
    			<td colspan="2">用户信息修改</td>
    		</tr>
    		<tr align="center">
    			<td>用户名：</td>
    			<td>
    				<input type="text" name="userName" value="<%=userVo.getUserName() %>"/>
    			</td>
    		</tr>
    		<tr align="center">
    			<td>密&nbsp;&nbsp;码：</td>
    			<td>
    				<input type="text" name="userPassword" value="<%=userVo.getUserPassword() %>"/>
    			</td>
    		</tr>
    		<tr align="center">
    			<td>地&nbsp;&nbsp;址：</td>
    			<td>
    				<select name="province" id="province"></select>
    				<select name="city" id="city"></select>
				</td>
    		</tr>
    		<tr align="center">
    			<td>性&nbsp;&nbsp;别：</td>
    			<td>
    				<input type="radio" name="userSex" value="男"/>男
    				<input type="radio" name="userSex" value="女"/>女
    			</td>
    		</tr>
    		<tr align="center">
    			<td>爱&nbsp;&nbsp;好：</td>
    			<td>
    				<input type="checkbox" name="hobby" value="篮球"/>篮球
    				<input type="checkbox" name="hobby" value="足球"/>足球
    				<input type="checkbox" name="hobby" value="羽毛球"/>羽毛球
    				<input type="checkbox" name="hobby" value="跑步"/>跑步
    			</td>
    		</tr>
    		<tr align="center">
    			<td>个<br/>人<br/>描<br/>述<br/></td>
    			<td><textarea name="describe"><%=userVo.getDescribe() %></textarea></td>
    		</tr>
    		<tr align="center">
    			<td colspan="2">
    				<input type="submit" value="修改"/>
    			</td>
    		</tr>
    	</table>
    </form>
    </body>
</html>