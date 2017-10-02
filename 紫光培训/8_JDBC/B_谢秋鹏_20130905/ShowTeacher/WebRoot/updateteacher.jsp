<%@ page language="java" import="java.util.*,com.PackageVO.TeacherVO" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
TeacherVO teacherVo=(TeacherVO)request.getAttribute("teacherVo");
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'teacherinfo.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<script type="text/javascript" src="js/jquery-1.4.2.js" charset="GBK"></script>
	<script type="text/javascript" src="js/linkedCities.js" charset="GBK"></script>
	<script type="text/javascript" src="js/LinkedWorktime.js" charset="GBK"></script>
	<script type="text/javascript" src="js/LinkedBirth.js" charset="GBK"></script>
	<script type="text/javascript">
		$(document).ready(function (){
			//Address联动
			addProvinceOption();
			addCityOption();
			$("#province").change(function(){
				addCityOption();
			});
			//teacherBirth联动
			addYear();
			addMonth();
			addDay();
			$("#birthYear").change(addDay);
			$("#birthMonth").change(addDay);
			//teacherWorktime联动			
			addYearb();
			addMonthb();
			addDayb();
			$("#worktimeYear").change(addDayb);
			$("#worktimeMonth").change(addDayb);
		});
	</script>
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    	<form action="servlet/ServletUpdateTeacher" method="post"> 
    		<input type="hidden" name="teacherId" value="<%=teacherVo.getTeacherId() %>"/>
	    	<br/>
	    	编号：<input type="text" name="teacherNum"/><br/>
	    	姓名：<input type="text" name="teacherName"/><br/>
	    	性别：<input type="text" name="teacherSex"/><br/>
	    	出生日期：
	    	<select name="teacherBirth" id="birthYear"></select>年
	    	<select name="teacherBirth" id="birthMonth"></select>月
	    	<select name="teacherBirth"></select>日
	    	<br/>
	    	入职时间：
	    	<select name="teacherWorktime" id="worktimeYear"></select>年
	    	<select name="teacherWorktime" id="worktimeMonth"></select>月
	    	<select name="teacherWorktime"></select>日
	    	<br/>
	    	家庭住址：
	    	<select name="teacherAddress" id="province"></select>省
	    	<select name="teacherAddress" id="city"></select>市
	    	<br/>
	    	<input type="submit" value="修改"/>
		</form>
  </body>
</html>
