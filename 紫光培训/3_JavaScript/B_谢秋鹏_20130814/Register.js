//判空.js
			function checkNull(textId)
			{
				var content=document.getElementById(textId);
				if(content.value ==="")
				{
					content.nextSibling.innerHTML =textId+"不能为空";
					return true;
				}
				else
				{
					content.nextSibling.innerHTML ="√";
					return false;
				}
			}
			//判等
			function checkEqual()
			{
				var confirmPwd=document.getElementById("确认密码");
				var Pwd=document.getElementById("密码");
				if (confirmPwd.value !==Pwd.value)
				{
					confirmPwd.nextSibling.innerHTML ="两次输入的密码不一致";
				}
				else
				{
					confirmPwd.nextSibling.innerHTML ="√";
				}
			}
			//判等条件
			function checkNullAndEqual(textId)
			{
				checkNull(textId);
				if (checkNull(textId) ===false)
				{
					checkEqual();
				}
			}

//性别.js
			function checkSex(value)
			{
				var objTextarea=document.getElementById("textarea");
				if (1==value)
				{
					objTextarea.innerHTML=("帅哥一个");
				}
				else if(2==value)
				{
					objTextarea.innerHTML=("美女一枚");
				}
			}
//全选.js
function check(value)
{
	var objCheck=document.getElementsByName("hobby");
	for (i=0;i<objCheck.length;i++)
	{
		if("全选"==value)
		{
			objCheck[i].checked=true;
		}
		else if("全不选"==value)
		{
			objCheck[i].checked=false;
		}
		else if("反选"==value)
		{
			objCheck[i].checked=!objCheck[i].checked;
		}
	}
}
//时间.js
			function addYear()
			{
				var objYear=document.getElementById("year");
				for(var i=1990;i<=2020;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objYear.options.add(opt);
				}
			}
			function addMonth()
			{
				var objMonth=document.getElementById("month");
				for(var i=1;i<13;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objMonth.options.add(opt);
				}
			}
			function addDay()
			{
				var intDay =checkDate();
				var objDay=document.getElementById("day");
				objDay.options.length=0;
				for(var i=1;i<=intDay;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objDay.options.add(opt);
				}
				
			}
			function checkDate()
			{
				var year=document.getElementById("year").value;
				//alert(year);
				//alert(document.getElementById("year"));
				var month=document.getElementById("month").value;
				//alert(month);
				//alert(document.getElementById("month").options.selectedIndex);
				if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
				{
					return 31;
				}
				else if (month==4||month==6||month==9||month==11)
				{
					return 30;
				}
				else if (month==2)
				{
					if (year%4==0&&year%100!=0||year%400==0)
					{
						return 29;
					}
					else{return 28;}
				}		
			}
//地址.js
			var userProvince=["请选择","河南","河北","江苏","贵州"];
			var userCity=[["请选择"],["郑州","开封"],["唐山","保定"],["南京","无锡"],["贵阳","遵义"]];
			function addProvinceOption(id)
			{
				var objProvince=document.getElementById(id);
				for (var i=0;i<userProvince.length;i++)
				{
					var opt= new Option();
					opt.text=userProvince[i];
					opt.value=userProvince[i];
					objProvince.options.add(opt);
				}
			}
			function addCityOption(id)
			{
				var ci=checkProvince(id);
				var objCity=document.getElementById("city");
				objCity.length="";
				for (var i=0;i<userCity[ci].length;i++)//长度是userCity[]的长度
				{
					var opt= new Option();
					opt.text=userCity[ci][i];
					opt.value=userCity[ci][i];
					objCity.options.add(opt);
				}
			}
			function checkProvince(id)
			{
				var province=document.getElementById("province");//select的value值
				var position=province.selectedIndex;
				return position;
			}
//提交.js
			function presentOnLoad()
			{
				checkSex(1);
				addYear();
				addMonth();
				addDay();
				addProvinceOption('province');
				addCityOption('province');
			}