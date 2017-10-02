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