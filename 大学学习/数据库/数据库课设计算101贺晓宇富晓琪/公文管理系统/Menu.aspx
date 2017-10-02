<%@ Page language="c#" Codebehind="Menu.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.Menu" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >

<script runat="server">

    protected void LinkButton1_Click(object sender, EventArgs e)
    {

    }

    protected void LinkButton1_Click1(object sender, EventArgs e)
    {

    }
</script>

<HTML>
	<HEAD>
		<title>Menu</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="form1" runat="server">
		<style type="text/css">
BODY { BACKGROUND: #799ae1; MARGIN: 0px; FONT: 9pt 宋体 }
TABLE { BORDER-RIGHT: 0px; BORDER-TOP: 0px; BORDER-LEFT: 0px; BORDER-BOTTOM: 0px }
TD { FONT: 12px 宋体 }
IMG { BORDER-RIGHT: 0px; BORDER-TOP: 0px; VERTICAL-ALIGN: bottom; BORDER-LEFT: 0px; BORDER-BOTTOM: 0px }
A { FONT: 12px 宋体; COLOR: #000000; TEXT-DECORATION: none }
A:hover { COLOR: #428eff; TEXT-DECORATION: underline }
.sec_menu { BORDER-RIGHT: white 1px solid; BACKGROUND: #d6dff7; OVERFLOW: hidden; BORDER-LEFT: white 1px solid; BORDER-BOTTOM: white 1px solid }
.menu_title { }
.menu_title SPAN { FONT-WEIGHT: bold; LEFT: 8px; COLOR: #215dc6; POSITION: relative; TOP: 2px }
.menu_title2 { }
.menu_title2 SPAN { FONT-WEIGHT: bold; LEFT: 8px; COLOR: #428eff; POSITION: relative; TOP: 2px }
		</style>
		<SCRIPT language="javascript1.2">
function showsubmenu(sid)
{
whichEl = eval("submenu" + sid);
if (whichEl.style.display == "none")
{
eval("submenu" + sid + ".style.display=\"\";");
}
else
{
eval("submenu" + sid + ".style.display=\"none\";");
}


}
		</SCRIPT>
		<table cellpadding="0" cellspacing="0" width="160" align="center">
			<tr>
				<td height="25" class="menu_title" onmouseover="this.className='menu_title2';" onmouseout="this.className='menu_title';"
					background="img/title_bg_quit.gif">
					<span style="Z-INDEX: 101"><a href="" target="_blank"><b><font color="red"></font></b></a>
						| <A HREF="login.aspx?flag=logout" TARGET="_top"><B>注销登录</B></A></span></td>
			</tr>
		</table>
		<table cellpadding="0" cellspacing="0" width="160" align="center">
			<tr>
				<td height="25" class="menu_title" onmouseover="this.className='menu_title2';" onmouseout="this.className='menu_title';"
					background="img/admin_left_1.gif" id="menuTitle1" onclick="showsubmenu(14)">
					<font color="#3366cc"><b>信息分类</b></font></td>
			</tr>
			<tr>
				<td id='submenu14'>
					<div class="sec_menu" style="WIDTH:160px">
						<table cellpadding="0" cellspacing="0" align="center" width="135">
						   
							<tr>
								<td height="20"><a href="FileList_v.aspx?zu=A" target="right">A类文件组</a></td>
							</tr>
							<tr>
								<td height="20"><a href="FileList_v.aspx?zu=B" target="right">B类文件组</a></td>
							</tr>
							<tr>
								<td height="20"><a href="FileList_v.aspx?zu=C" target="right">C类文件组</a></td>
							</tr>
							<tr>
								<td height="20"><a href="Default.aspx?"target="right">文件流转</a></td>
							</tr>
						</table>
					</div>
				</td>
			</tr>
			<tr>
				<td height="20">
                    &nbsp;</td>
			</tr>
		</table>
		</form>
		<table id="managearea" cellpadding="0" cellspacing="0" width="160" align="center" >
			<tr>
				<td height="25" class="menu_title" onmouseover="this.className='menu_title2';" onmouseout="this.className='menu_title';"
					background="img/admin_left_3.gif" id="menuTitle2" onclick="showsubmenu(15)">
					<font color="#3366cc"><b>后台管理</b></font></td>
			</tr>
			<tr>
				<td id='submenu15'>
					<div class="sec_menu" style="WIDTH:160px">
						<table cellpadding="0" cellspacing="0" align="center" width="135">
						
						
						<tr><td height=20 class=menu_title onmouseover=this.className='menu_flash_class2'; onmouseout=this.className='menu_flash_class'; id=menu_flash_class onclick="showsubmenu(10)"> 
<font color="#3366CC">文件管理</font></td></tr> 

<tr> 
<td id='submenu10'> 
<div  style="width:135;text-indent:10px;" align=right> 
<table cellpadding=0 cellspacing=0 align=right width=135> 
<tr> <td height=20 style="width:135;text-indent:15px;"><a href="Uploadfile.aspx" target=right>上传文件</a></td></tr> 

<tr> <td height=20 class=menu_title onmouseover=this.className='menu_flash_class2'; onmouseout=this.className='menu_flash_class'; id=menu_flash_class onclick="showsubmenu(16)" style="width:135;text-indent:15px;">文件列表</td></tr>


<tr> 
<td style="display:none" id='submenu16'> 
<div  style="width:135;text-indent:10px;" align=right> 
<table cellpadding=0 cellspacing=0 align=right width=135> 
<tr> <td height=20 style="width:135;text-indent:30px;"><a href="FileList_m.aspx?zu=A" target=right>A类文件组</a></td></tr> 
<tr> <td height=20 style="width:135;text-indent:30px;"><a href="FileList_m.aspx?zu=B" target=right>B类文件组</a></td></tr> 
<tr> <td height=20 style="width:135;text-indent:30px;"><a href="FileList_m.aspx?zu=C" target=right>C类文件组</a></td></tr> 

</table>
</div>
</td>
</tr> 


</div>
</td>
</tr> 

						</table>
					</div>
				</td>
			</tr>
			<tr><td height=20 class=menu_title onmouseover=this.className='menu_flash_class2'; onmouseout=this.className='menu_flash_class'; id=menu_flash_class onclick="showsubmenu(20)"> 
<font color="#3366CC">帐户管理</font></td></tr> 

<tr> 
<td style="display:none" id='submenu20'> 
<div  style="width:135;text-indent:10px;" align=right> 
<table cellpadding=0 cellspacing=0 align=right width=135> 
<tr> <td height=20 style="width:135;text-indent:15px;"><a href="CreateRole.aspx" target=right>创建角色</a></td></tr> 
<tr> <td height=20 style="width:135;text-indent:15px;"><a href="RoleList.aspx" target=right>角色列表</a></td></tr> 
<tr> <td height=20 style="width:135;text-indent:15px;"><a href="CreateUser.aspx" target=right>创建帐户</a></td></tr> 
<tr> <td height=20 style="width:135;text-indent:15px;"><a href="UserList.aspx" target=right>帐户列表</a></td></tr> 

</table>
</div>
</td>
</tr> 
			<tr>
				<td height="20">&nbsp;</td>
			</tr>
		</table>
	    </form>
		</form>
		</body>
</HTML>
