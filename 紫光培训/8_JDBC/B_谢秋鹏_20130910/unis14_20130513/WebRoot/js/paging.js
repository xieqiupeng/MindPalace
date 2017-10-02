// JavaScript Document

var nowPageNumber = 1;
var onePageLines = 4;

//��ʾ��ҳ��ķ�ҳ��
function showPagingNumber()
{
	//��ȡ����������
	var pagingTable = document.getElementById("pagingTable");
	var tableAllNumber = pagingTable.rows.length;
	
	//��ȡ��ʾ��ҳ���div��
	var pagingNumberDiv = document.getElementById("pagingNumber");
	
	//�����ҳ�Ƿ�������
	var leaveLines = tableAllNumber%onePageLines;
	
	//������Ҫ�ֶ���ҳ
	var allPageNumber = parseInt(tableAllNumber/onePageLines);
	
	//���������֤����Ҫ���һҳ��ʾ����������
	if(leaveLines!=0)
	{
		allPageNumber = allPageNumber+1;
	}
	
	//��ҳ���ʽ����
	var pageNumberInnerHTML="";
	for(var i=1;i<=allPageNumber;i++)
	{
		pageNumberInnerHTML+="<span onclick='showNowPageLines("+i+")'>"+i+"</span>&nbsp;&nbsp;";
	}

	pagingNumberDiv.innerHTML="<span onclick='showNowPageLines(1)'>��ҳ</span>&nbsp;&nbsp;<span onclick='goUpPage()'>��һҳ</span>&nbsp;&nbsp;"+					pageNumberInnerHTML+"<span onclick='goDownPage()'>��һҳ</span>&nbsp;&nbsp;<span onclick='showNowPageLines("+allPageNumber+")'>βҳ</span>";
}




//�����Ӧҳ����ʾ��Ӧ����
function showNowPageLines(clickNumber)
{
	//��ȡ����������
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
		alert("��ǰ���ǵ�һҳ");
	}
	else
	{
		passValue = nowPageNumber-1;
		showNowPageLines(passValue);	
	}
}

function goDownPage()
{
	//��ȡ����������
	var pagingTable = document.getElementById("pagingTable");
	var tableAllNumber = pagingTable.rows.length;
	//�����ҳ�Ƿ�������
	var leaveLines = tableAllNumber%onePageLines;
	
	//������Ҫ�ֶ���ҳ
	var allPageNumber = parseInt(tableAllNumber/onePageLines);
	
	//���������֤����Ҫ���һҳ��ʾ����������
	if(leaveLines!=0)
	{
		allPageNumber = allPageNumber+1;
	}
	
	if(nowPageNumber==allPageNumber)
	{
		alert("��ǰ���ǵ����һҳ");
	}
	else
	{
		passValue = nowPageNumber+1;
		showNowPageLines(passValue);	
	}
}























