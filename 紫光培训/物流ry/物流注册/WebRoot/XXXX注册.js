	function setNull(obj)
	{
		//alert(obj.value);
		obj.value="";
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
		}
		else
		{
			confirmPwd.parentNode.nextSibling.nextSibling.innerHTML =
			"<span class='checkSuccess'>√</span>";
		}
	}
	//提交
	function submitAll(checkOne,checkTwo){
		var message="";
		var agreeItem =document.getElementById("agreeItem");
		if (agreeItem.checked !== true)
		{
			message +="您是否同意《网络服务使用协议》和《XXXX物流服务条款》！\n";
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
			document.getElementById("#form").submit();
		}
		else
		{
			alert(message);
		}
	}