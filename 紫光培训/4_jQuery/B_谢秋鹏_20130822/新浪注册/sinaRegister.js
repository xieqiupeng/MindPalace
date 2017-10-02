﻿// 省市联动
	var userProvince=["河南","河北","江苏","贵州"];
	var userCity=[
		["郑州","开封"],
		["唐山","保定"],
		["南京","无锡"],
		["贵阳","遵义"]
	];
	function addProvinceOption(){
		var objProvince=document.getElementById("pro");
		for (var i=0;i<userProvince.length;i++){
			var opt= new Option();
			opt.text=userProvince[i];
			opt.value=userProvince[i];
			objProvince.options.add(opt);
		}
	}
	function addCityOption(){
		var position =checkProvince();
		var objCity =document.getElementById("ci");
		objCity.length="";
		//长度是userCity[]的长度
		for (var i=0;i <userCity[position].length;i++){
			var opt= new Option();
			opt.text=userCity[position][i];
			opt.value=userCity[position][i];
			objCity.options.add(opt);
		}
	}
	function checkProvince(){
		//select的value值
		var province =document.getElementById("pro");
		var position =province.selectedIndex
		return position;
	}
//判空
	function checkNull(obj){
		var textId =obj.id;
		if(obj.value ==="")
		{
			//alert(obj.parentNode.nextSibling.nextSibling.innerHTML);
			obj.parentNode.nextSibling.nextSibling.innerHTML =textId+"不能为空";
			return true;
		}
		else
		{
			obj.parentNode.nextSibling.nextSibling.innerHTML ="<span class='checkSuccess'>√</span>";
			return false;
		}
	}
	//判断字符
	function checkString(obj)
	{
		var str=obj.value;
		if(str.length<6)
		{
			obj.parentNode.nextSibling.nextSibling.innerHTML ="必须是6-16位字符（字母，数字）";
			return false;
		}
		for(var i=0;i<str.length;i++)
		{
			n=str.charCodeAt(i);
			//如果是的话，continue
			if((n>=48&&n<=57) || (n>=65&&n<=90) || (n>=97&&n<=122) )
			{
				continue;
			}
			else
			{
				obj.parentNode.nextSibling.nextSibling.innerHTML ="必须是6-16位字符（字母，数字）";
				return false;
			}
		}
		obj.parentNode.nextSibling.nextSibling.innerHTML="<span class='checkSuccess'>√</span>";
		return true;
	}
	//判等
	function checkEqual()
	{
		var Pwd =document.getElementById("密码");
		var confirmPwd =document.getElementById("确认密码");
		if (confirmPwd.value !==Pwd.value)
		{
			confirmPwd.parentNode.nextSibling.nextSibling.innerHTML =
			"两次输入的密码不一致";
			return false;
		}
		else
		{
			confirmPwd.parentNode.nextSibling.nextSibling.innerHTML =
			"<span class='checkSuccess'>√</span>";
			return true;
		}
	}
	//提交
	function submitAll(checkOne,checkTwo){
		var message="";
		var agreeItem =document.getElementById("agreeItem");
		if (agreeItem.checked !== true)
		{
			message +="您是否同意《新浪网络服务使用协议》和《新浪免费邮箱服务条款》！\n";
		}
		if (checkOne ===false)
		{
			message +="请检查您的昵称\n";
		}
		if (checkTwo ===false)
		{
			message +="请检查您的密码与确认密码\n";
		}
		if (message ==="") 
		{
			confirm("提交成功");
			//document.getElementById("#form").submit();
			location.href="success.html";
		}
		else
		{
			alert(message);
		}
	}