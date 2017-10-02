// JavaScript Document

var nowPageNumber = 1;
var onePageLines = 4;

//显示分页框的分页码
function showPagingNumber()
{
	//获取表格的总行数
	var pagingTable = document.getElementById("pagingTable");
	var tableAllNumber = pagingTable.rows.length;
	
	//获取显示分页码的div框
	var pagingNumberDiv = document.getElementById("pagingNumber");
	
	//计算分页是否有余数
	var leaveLines = tableAllNumber%onePageLines;
	
	//计算需要分多少页
	var allPageNumber = parseInt(tableAllNumber/onePageLines);
	
	//如果有余数证明需要多分一页显示余下是行数
	if(leaveLines!=0)
	{
		allPageNumber = allPageNumber+1;
	}
	
	//将页码格式生成
	var pageNumberInnerHTML="";
	for(var i=1;i<=allPageNumber;i++)
	{
		pageNumberInnerHTML+="<span onclick='showNowPageLines("+i+")'>"+i+"</span>&nbsp;&nbsp;";
	}

	pagingNumberDiv.innerHTML="<span onclick='showNowPageLines(1)'>首页</span>&nbsp;&nbsp;<span onclick='goUpPage()'>上一页</span>&nbsp;&nbsp;"+					pageNumberInnerHTML+"<span onclick='goDownPage()'>下一页</span>&nbsp;&nbsp;<span onclick='showNowPageLines("+allPageNumber+")'>尾页</span>";
}




//点击对应页码显示对应行数
function showNowPageLines(clickNumber)
{
	//获取表格的总行数
	var pagingTable = document.getElementById("pagingTable");
	var tableAllNumber = pagingTable.rows.length;
	
	var endPageLine = clickNumber*onePageLines;
	var startPageLine = endPageLine-onePageLines;
	
	if(tableAllNumber<endPageLine)
	{
		endPageLine=tableAllNumber;	
	}
	
	for(var i=0;i<tableAllNumber;i++)
	{
		pagingTable.rows[i].style.display="none";
	}
	
	for(var j=startPageLine;j<endPageLine;j++)
	{
		pagingTable.rows[j].style.display="block";
	}
	nowPageNumber = clickNumber;
}

function goUpPage()
{
	if(nowPageNumber==1)
	{
		alert("当前已是第一页");
	}
	else
	{
		passValue = nowPageNumber-1;
		showNowPageLines(passValue);	
	}
}

function goDownPage()
{
	//获取表格的总行数
	var pagingTable = document.getElementById("pagingTable");
	var tableAllNumber = pagingTable.rows.length;
	//计算分页是否有余数
	var leaveLines = tableAllNumber%onePageLines;
	
	//计算需要分多少页
	var allPageNumber = parseInt(tableAllNumber/onePageLines);
	
	//如果有余数证明需要多分一页显示余下是行数
	if(leaveLines!=0)
	{
		allPageNumber = allPageNumber+1;
	}
	
	if(nowPageNumber==allPageNumber)
	{
		alert("当前已是第最后一页");
	}
	else
	{
		passValue = nowPageNumber+1;
		showNowPageLines(passValue);	
	}
}























