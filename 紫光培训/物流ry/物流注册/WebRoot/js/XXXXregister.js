	function setNull(obj)
	{
		//alert(obj.value);
		obj.value="";
	}
	//�п�
	function checkNull(obj){
		var textId =obj.id;
		if(obj.value ==="")
		{
			//alert(obj.parentNode.nextSibling.nextSibling.innerHTML);
			obj.parentNode.nextSibling.nextSibling.innerHTML =textId+"����Ϊ��";
			return true;
		}
		else
		{
			obj.parentNode.nextSibling.nextSibling.innerHTML ="<span class='checkSuccess'>��</span>";
			return false;
		}
	}
	//�ж��ַ�
	function checkString(obj)
	{
		var str=obj.value;
		if(str.length<6)
		{
			obj.parentNode.nextSibling.nextSibling.innerHTML ="������6-16λ�ַ�����ĸ�����֣�";
			return false;
		}
		for(var i=0;i<str.length;i++)
		{
			n=str.charCodeAt(i);
			//����ǵĻ���continue
			if((n>=48&&n<=57) || (n>=65&&n<=90) || (n>=97&&n<=122) )
			{
				continue;
			}
			else
			{
				obj.parentNode.nextSibling.nextSibling.innerHTML ="������6-16λ�ַ�����ĸ�����֣�";
				return false;
			}
		}
		obj.parentNode.nextSibling.nextSibling.innerHTML="<span class='checkSuccess'>��</span>";
		return true;
	}
	//�е�
	function checkEqual()
	{
		var Pwd =document.getElementById("����");
		var confirmPwd =document.getElementById("ȷ������");
		if (confirmPwd.value !==Pwd.value)
		{
			confirmPwd.parentNode.nextSibling.nextSibling.innerHTML =
			"������������벻һ��";
		}
		else
		{
			confirmPwd.parentNode.nextSibling.nextSibling.innerHTML =
			"<span class='checkSuccess'>��</span>";
		}
	}
	//�ύ
	function submitAll(checkOne,checkTwo){
		var message="";
		var agreeItem =document.getElementById("agreeItem");
		if (agreeItem.checked !== true)
		{
			message +="���Ƿ�ͬ�⡶�������ʹ��Э�顷�͡�XXXX�������������\n";
		}
		if (checkOne ===false)
		{
			message +="���������ǳ�\n";
		}
		if (checkTwo ===false)
		{
			message +="��������������ȷ������\n";
		}
		if (message ==="") 
		{
			confirm("�ύ�ɹ�");
			document.getElementById("#form").submit();
		}
		else
		{
			alert(message);
		}
	}