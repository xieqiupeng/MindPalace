<%@ Page language="c#" Codebehind="EditRole.aspx.cs" AutoEventWireup="True" Inherits="FileManage_Sys.EditRole" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title></title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<LINK href="img/home.css" type="text/css" rel="stylesheet">
		<script language="javascript">
		 function copyToList(from,to)
        {
          fromList = eval('document.all.' + from);
          toList = eval('document.all.' + to);
          if (toList.options.length > 0 && toList.options[0].value == 'temp')
          {
            toList.options.length = 0;
          }
          var sel = false;
          var selDel = false;
          var intDel = 0;
          for (i=0;i<fromList.options.length;i++)
          {
            var current = fromList.options[i];
            if (current.selected)
            {
              sel = true;
              txt = current.text;
              val = current.value;
              toList.options[toList.length] = new Option(txt,val);
              if (from.toString()=='selectItems')
              {
                selDel = true;
                intDel +=1;
              }
              fromList.options[i] = null;
              i--;
            }
          }
          if (!sel) alert ('��������ѡ��һ����Ŀ!');
        }

        function allSelect()
       {

         //List = document.forms[2].selectItems;
         //if (List.length && List.options[0].value == 'temp') return;
         //for (i=0;i<List.length;i++)
         //{
         //  List.options[i].selected = true;
         //}
       }
   function add_role()
   {
		if(window.document.all.role_name.value=="")
		{
			alert('����д��ɫ����');
			return false;
		}
		var rolenamestr="",rolestr="",i=0;
		var roleid ="";
		roleid = GetArgsFromHref(window.location.href,"roleid");
		
		if(window.document.all.selectItems.options.length==0) {alert('����ѡ��һ��!');return false;}
		rolenamestr = window.document.all.role_name.value;
		for(i=0;i<window.document.all.selectItems.options.length;i++)
		{
			if((window.document.all.selectItems.options.length-1)==i)
				rolestr=rolestr+window.document.all.selectItems.options[i].value;
			else
				rolestr=rolestr+window.document.all.selectItems.options[i].value+",";
			
		}
		
   
		document.location.href="CreateRole_add.aspx?flag=edit&rolename="+rolenamestr+"&role="+rolestr+"&roleid="+roleid;
		
		//window.open("CreateRole_add.aspx?flag=edit&rolename="+rolenamestr+"&role="+rolestr+"&roleid="+roleid);
   }
   
   function GetArgsFromHref(sHref,sArgName)
	{
    var args  = sHref.split("?");
    var retval = "";
    
    if(args[0] == sHref) /*����Ϊ��*/
    {
         return retval; /*�������κδ���*/
    }  
    var str = args[1];
    args = str.split("&");
    for(var i = 0; i < args.length; i ++)
    {
        str = args[i];
        var arg = str.split("=");
        if(arg.length <= 1) continue;
        if(arg[0] == sArgName) retval = arg[1]; 
    }
    return retval;
	}

		</script>
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<TABLE cellSpacing="1" cellPadding="1" width="98%" align="center" bgColor="#6699ff" border="0">
				<TR>
					<TD align="center" height="20"><font style="FONT-SIZE: 12px; COLOR: #ffffff"><b>�༭��ɫ</b></font></TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="#ffffff" height="100"><BR>
						<TABLE cellSpacing="1" cellPadding="1" width="90%" align="center" border="0">
							<TR>
								<TD style="FONT-SIZE: 12px" align="center" width="80" height="7">��ɫ����</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7"><FONT face="����"><asp:TextBox name="role_name" ID="role_name" class="textinput" Runat="server"></asp:TextBox></FONT></TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="center" width="80" height="7">��ɫȨ��</TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7">�������ѡȡ��ɫӦ�þ��������Ӧ�ļ���Ȩ�ޣ�����ѡ��һ�����Ҳ��</TD>
							</TR>
							<TR>
								<TD style="FONT-SIZE: 12px" align="center" width="80" height="7"></TD>
								<TD style="FONT-SIZE: 12px" align="left" height="7">
									<table>
										<tr>
											<td width="30%">
												<table>
													<tr>
														<td align="center">
															<font class="font_12px">δѡѡ��</font>
														</td>
													</tr>
													<tr>
														<td>
															<select size="5" id="unSelectItems" name="unSelectItems" style="FONT-SIZE: 12px; WIDTH: 130px; HEIGHT: 150px"
																runat="server">
																<option value="P">PDF�ļ�</option>
																<option value="E">EXCEL�ļ�</option>
																<option value="J">JPG�ļ�</option>
																<option value="D">DWG�ļ�</option>
															</select>
														</td>
													</tr>
												</table>
											</td>
											<td width="30%">
												<table>
													<tr>
														<td align="center">
															<font class="font_12px"></font>
														</td>
													</tr>
													<tr>
														<td width="18%" align="center" valign="middle" class="tdInput">
															<div align="center">
																<input type="button" value="���>>" name="Input" class="Textinput" onClick="copyToList('unSelectItems','selectItems')">
																<br>
																<br>
																<input type="button" value="<<ɾ��" name="Input" class="Textinput" onClick="copyToList('selectItems','unSelectItems')">
															</div>
														</td>
													</tr>
												</table>
											</td>
											<td width="30%">
												<table>
													<tr>
														<td align="center">
															<font class="font_12px">��ѡѡ��</font>
														</td>
													</tr>
													<tr>
														<td>
															<select size="5" id="selectItems" name="selectItems" multiple style="FONT-SIZE: 12px; WIDTH: 130px; HEIGHT: 150px"
																runat="server">
																<option value="W">WORD�ļ�</option>
															</select>
														</td>
													</tr>
												</table>
											</td>
										</tr>
										<TR>
											<TD style="FONT-SIZE: 12px" align="center" width="80" height="7"></TD>
											<TD style="FONT-SIZE: 12px" align="right" height="7"><input type="button" onclick="add_role();" value="ȷ ��" class="textinput">&nbsp;<asp:Button ID="delrole" Runat="server" class="textinput" Text="ɾ ��" onclick="delrole_Click"></asp:Button></TD>
										</TR>
									</table>
								</TD>
							</TR>
						</TABLE>
					</TD>
				</TR>
			</TABLE>
			<br>
			<br>
		</form>
	</body>
</HTML>
