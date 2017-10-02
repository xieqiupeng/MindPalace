//省市联动
//area中的省市对应关系是手动写死的。
	var area ={
		"userProvince":["请选择","山东","河北","江苏","湖北"],
		"userCity":[
			["请选择"],
			["济南","青岛","淄博","德州","烟台","潍坊","济宁","泰安","临沂","菏泽"],
			["石家庄","唐山","秦皇岛","邯郸","邢台","张家口","承德","廊坊","沧州","保定"],
			["南京","苏州","无锡","常州","镇江","连云港 ","扬州","徐州","南通","盐城"],
			["武汉","黄石","十堰","荆州","宜昌","襄樊","鄂州","荆门","孝感","黄冈"]
		]
	};
	function addProvinceOption()
	{
		var objProvince =document.getElementById("province");
		for (var i=0;i<area.userProvince.length;i++)
		{
			var opt= new Option();
			opt.text=area.userProvince[i];
			opt.value=area.userProvince[i];
			objProvince.options.add(opt);
		}
	}
	function addCityOption()
	{
		var provinceIndex =checkProvince();
		var objCity =document.getElementById("city");
		objCity.length="";
		//长度是area.userCity[]的长度
		for (var i=0;i<area.userCity[provinceIndex].length;i++)
		{
			var opt= new Option();
			opt.text=area.userCity[provinceIndex][i];
			opt.value=area.userCity[provinceIndex][i];
			objCity.options.add(opt);
		}
	}
	function checkProvince()
	{
		var objProvince =document.getElementById("province");
		var provinceIndex =objProvince.selectedIndex;
		return provinceIndex;
	}
	function showArea()
	{
		for (var i=0;i<area.userProvince.length;i++)
		{
			for (var j=0;j<area.userCity[i].length;j++)
			{
				document.write(area.area.userProvince[i] +area.area.userCity[i][j]+"<br/>");
			}
		}
	}