//ʡ������
	var area ={
		"userProvince":["��ѡ��","ɽ��","�ӱ�","����","����"],
		"userCity":[
			["��ѡ��"],
			["����","�ൺ","�Ͳ�","����","��̨","Ϋ��","����","̩��","����","����"],
			["ʯ��ׯ","��ɽ","�ػʵ�","����","��̨","�żҿ�","�е�","�ȷ�","����","����"],
			["�Ͼ�","����","����","����","��","���Ƹ� ","����","����","��ͨ","�γ�"],
			["�人","��ʯ","ʮ��","����","�˲�","�差","����","����","Т��","�Ƹ�"]
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
		//������area.userCity[]�ĳ���
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
	function show()
	{
		for (var i=0;i<4;i++)
		{
			for (var j=0;j<10;j++)
			{
		document.write(area.area.userProvince[i] +area.area.userCity[i][j]+"<br/>");
			}
		}
	}