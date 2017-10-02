//部门联动
	var company ={
			"departmentId":[0,1,2,3,4],
			"departmentName":["领导组","秘书处","研究室一","研究室二","研究室三"],
			"staffId":[[0，5],[1],[2，6],[3],[4]],
			"staffName":[["谢秋鹏","张可伦"],["陆彤"],["王群","谢雨"],["王同禄"],["穆道元"]],
	};
	function addDepartmentOption()
	{
		var objDepartment =document.getElementById("department");
		for (var i=0;i<company.departmentId.length;i++)
		{
			var opt= new Option();
			opt.text=company.departmentName[i];
			opt.value=company.departmentId[i];
			objDepartment.options.add(opt);
		}
	}
	function addStaffOption()
	{
		var departmentIndex =checkDepartment();
		var objStaff =document.getElementById("staff");
		objStaff.length="";
		//长度是company.userstaff[]的长度
		for (var i=0;i<company.staffId[departmentIndex].length;i++)
		{
			var opt= new Option();
			opt.text=company.staffName[departmentIndex][i];
			opt.value=company.staffId[departmentIndex][i];
			objStaff.options.add(opt);
		}
	}
	function checkDepartment()
	{
		var objdepartment =document.getElementById("department");
		var departmentIndex =objdepartment.selectedIndex;
		return departmentIndex;
	}
//遍历所有下拉列表
	function showCompany()
	{
		for (var i=0;i<company.departmentId.length;i++)
		{
			for (var j=0;j<company.staffId[i].length;j++)
			{
				document.write(company.departmentId[i] +company.staffId[i][j]+"<br/>");
			}
		}
	}