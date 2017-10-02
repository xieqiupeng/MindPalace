//时间.js
			function addYear()
			{
				var objDate=document.getElementsByName("teacherBirth");
				for(var i=1990;i<=2020;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objDate[0].options.add(opt);
				}
			}
			function addMonth()
			{
				var objDate=document.getElementsByName("teacherBirth");
				for(var i=1;i<13;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objDate[1].options.add(opt);
				}
			}
			function addDay()
			{
				var intDay =checkDate();
				var objDate=document.getElementsByName("teacherBirth");
				objDate[2].options.length=0;
				for(var i=1;i<=intDay;i++)
				{
					var opt =new Option();
					opt.text=i;
					opt.value=i;
					objDate[2].options.add(opt);
				}
				
			}
			function checkDate()
			{
				var year=document.getElementsByName("teacherBirth")[0].value;
				//alert(year);
				//alert(document.getElementById("year"));
				var month=document.getElementsByName("teacherBirth")[1].value;
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