// JavaScript Document


//-----------------------------------------------提示窗口设置-----------------------------------------
//写入一个覆盖全页面的透明框，禁止所有操作。
document.write("<div id='bg' style='width:100%;height:100%;top:0px;left:0px;position:absolute;z-index:8900;filter: Alpha(opacity=50);opacity:0.5; /*background:#000000;*/ display:none;'></div>"); 
//写入一个透明框上的半透明框，显示提示信息。
document.write("<div id='popbox' style='position:absolute;z-index:9000;width:480px; height:151px; left:50%; top:50%; margin:-200px 0 0 -200px; display:none; background-image:url(img/prompthead.jpg);'><img src='img/close.png' style='position:absolute;left:90%; top:12%;'  onclick='popclose()'><div id='infoShow' style='position:absolute;left:10%; top:50%;' ></div></div>"); 

//显示提示框
function popopen(){
	        document.getElementById("bg").style.display="block";
            document.getElementById("popbox").style.display="block" ;	
	}

//关闭提示框
function popclose(){
document.getElementById("bg").style.display="none";
            document.getElementById("popbox").style.display="none" ;	
}

/**
*设置窗口内内容
**/
function setpopboxInfo(printInfo)
{
	document.getElementById("infoShow").innerHTML = printInfo;
}

//-----------------------------------------------提示窗口设置-----------------------------------------



//-----------------------------------------------判断功能-----------------------------------------
//验证数据为空
function checkNull(objId,putInfo)
{	
	var tempObj = document.getElementById(objId);
	//alert(tempObj.value);
	if(tempObj.value == "")
	{
		//printInfo = "<p href='#' style='position:absolute;left:10%; top:40%;'>"+putInfo+"</p>";
		setpopboxInfo(putInfo);
		popopen();
		return false;
	}
	return true;
}

//验证数据为数字
function checkNumber(objId,putInfo)
{
	
	var tempObj = document.getElementById(objId);
	//alert(tempObj.value);
	
	if( isNaN(tempObj.value))
	{
		printInfo = "<p style='position:absolute;left:10%; top:40%;' href='#'  >"+putInfo+"</p>";
		setpopboxInfo(printInfo);
		popopen();		
		return false;
	}
	return true;
}

//限制字符长度
function checkMaxLength(objId,maxLength,putInfo)
{
	
	var tempObj = document.getElementById(objId);
	//alert(tempObj.value.length);
	if(tempObj.value.length>Number(maxLength) )
	{
		printInfo = "<p href='#' style='position:absolute;left:10%; top:40%;'  >"+putInfo+"</p>";
		setpopboxInfo(printInfo);
		popopen();
		
		return false;
	}
	
	return true;
}

//比较时间
function checkTime(starTime,endTime,putInfo)
{
	var sTime = new Date();
	var eTime = new Date();
	
	var timeone = document.getElementById(starTime);
	var timetwo = document.getElementById(endTime);
	
	var strST = timeone.value;	
	var strET = timetwo.value;
	
	//alert(strST);
	//alert(strST.substring(0,4)+strST.substring(5,7)+strST.substring(8,10));
	//alert(getY(strST)+getM(strST)+getD(strST));
	
	
	sTime.setFullYear(getY(strST),getM(strST),getD(strST));
	eTime.setFullYear(getY(strET),getM(strET),getD(strET));
	
	//alert(sTime.getTime());
	
	if(Number(sTime.getTime()) >= Number(eTime.getTime()))
	{
		//alert(eTime.getTime());
	    printInfo ="<p href='#' style='position:absolute;left:10%; top:40%;'  >"+putInfo+"</p>";
		setpopboxInfo(printInfo);
		popopen();
		
		return false;
	}
	
	return true;
}


//-------------------------2012-10-19-------------------------------------
//比较精确到秒的时间
function checkTimeBySeconds(starTime,endTime,putInfo)
{
	var sTime = new Date();
	var eTime = new Date();
	
	var timeone = document.getElementById(starTime);
	var timetwo = document.getElementById(endTime);
	
	var strST = timeone.value;	
	var strET = timetwo.value;
	
	//alert(strST);
	//alert(strST.substring(0,4)+strST.substring(5,7)+strST.substring(8,10));
	//alert(strST.substring(11,13)+strST.substring(14,16)+strST.substring(17,19));
	//alert(getY(strST)+getM(strST)+getD(strST));
	//alert(getH(strST)+getMs(StrST));//+getS(StrST));
	//alert(getH(StrST)+getMin(StrST)+getS(StrST));
	
	sTime.setFullYear(getY(strST),getM(strST),getD(strST));
	
	
	
	sTime.setHours(strST.substring(11,13),strST.substring(14,16),strST.substring(17,19),"000");
	
	
	eTime.setFullYear(getY(strET),getM(strET),getD(strET));
	eTime.setHours(strET.substring(11,13),strET.substring(14,16),strET.substring(17,19),"000");
	
	//alert(sTime.getTime());
	
	if(Number(sTime.getTime()) >= Number(eTime.getTime()))
	{
		//alert(eTime.getTime());
	    printInfo = "<p href='#' style='position:absolute;left:10%; top:30%;'  >"+putInfo+"</p>";
		setpopboxInfo(printInfo);
		popopen();
		
		return false;
	}
	
	return true;
}
//-------------------------2012-10-19-------------------------------------

//-----------------------------------------------判断功能-----------------------------------------


//---------------------------------------字符串功能---20121022----------------------------------------------
//如果目标字符串（sourceString）的长度大于阀值(length)，将目标以阀值+指定字符串(replaceString)长度截取，并用将字符串加入到目标字符串后。
function replaceString(sourceString,length,replaceString)
{
	if(sourceString.length > (length+replaceString.length))
	sourceString = sourceString.substring(0,length)+replaceString;
	return sourceString;
}


//---------------------------------------字符串功能---20121022----------------------------------------------

//-----------------------------------------------时间功能-----------------------------------------
function getY(timeInfo)
{
	return timeInfo.substring(0,4);
}
function getM(timeInfo)
{
	return timeInfo.substring(5,7);
}
function getD(timeInfo)
{
	return timeInfo.substring(8,10);
}

function parserTime(timeInfo)
{
	var dateInfo =new Array( timeInfo.substring(0,4),timeInfo.substring(5,7),timeInfo.substring(8,10));
	return dateInfo;
}
//-----------------------------------------------时间功能-----------------------------------------