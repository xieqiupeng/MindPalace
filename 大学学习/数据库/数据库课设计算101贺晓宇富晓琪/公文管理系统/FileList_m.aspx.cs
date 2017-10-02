using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;
using System.Text;
using System.Data.OleDb;

namespace FileManage_Sys
{
	/// <summary>
	/// FileList_m 的摘要说明。
	/// </summary>
	public partial class FileList_m : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.Cookies["UserCookie"]["role"]!=null)
			{
				if(Request.Cookies["UserCookie"]["role"].ToString().Length!=9)
				{
					Response.Write("<SCRIPT language='JavaScript'>alert('您不是管理员！');window.parent.location.href='Login.aspx'; </SCRIPT>");
				}
			}
			string SqlStr="";
			string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//打开数据库

			if(Request.QueryString["fileid"]!=null)
			{//删除文件
				SqlStr="Delete * From files Where id="+ Request.QueryString["fileid"].ToString();
				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
				AccessCommand.ExecuteNonQuery();
				AccessCommand.Dispose();
				Response.Write("<SCRIPT language='JavaScript'>alert('删除成功');window.location.href='FileList_m.aspx?zu="+ Request.QueryString["zu"].ToString() +"'; </SCRIPT>");

			}
			else
			{
				if(Request.QueryString["zu"]!=null)
				{
					zu_file.Text = Request.QueryString["zu"].ToString();
					string File_Zu;
					File_Zu = Request.QueryString["zu"].ToString();//文件组

					StringBuilder FileList_Builder= new StringBuilder();//记录查询结果
					string FileListString = "";

					SqlStr="Select * From files Where filearea='"+ File_Zu +"' Order By Id DESC";

					OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

					OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
					int Rownum=0;

					string FileType="";//文件类型
					while(AccessReader.Read())
					{//提取信息
					
						switch(AccessReader["fileexe"].ToString())
						{
							case ".pdf":
								FileType = "PDF文件";
								break;
							case ".doc":
								FileType = "WORD文件";
								break;
							case ".xls":
								FileType = "EXCEL文件";
								break;
							case ".jpg":
								FileType = "JPG文件";
								break;
							case ".dwg":
								FileType = "DWG文件";
								break;
							case ".PDF":
								FileType = "PDF文件";
								break;
							case ".DOC":
								FileType = "WORD文件";
								break;
							case ".Xls":
								FileType = "EXCEL文件";
								break;
							case ".JPG":
								FileType = "JPG文件";
								break;
							case ".DWG":
								FileType = "DWG文件";
								break;
							default:break;
						}


						if(Rownum==0)
							FileListString = FileListString +"<TR bgcolor='#E4E4E4' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'><a href='"+ AccessReader["filepath"].ToString()+AccessReader["filename"].ToString() +"' target='_blank'>"+AccessReader["filename"].ToString()+"</a></font></td><td width='20%' align='center'><font class='font_12px'>"+File_Zu+"类文件组</font></td><td width='20%' align='center'><font class='font_12px'>"+ FileType +"</font></td><td width='20%' align='center'><font class='font_12px'>"+ AccessReader["addtime"].ToString() +"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='删 除' onclick= window.document.location.href='FileList_m.aspx?fileid="+AccessReader["id"].ToString()+"&zu="+ Request.QueryString["zu"].ToString() +"' style='Cursor:hand;'></td></tr></table></TD></TR>";
						else
							FileListString = FileListString +"<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'><a href='"+ AccessReader["filepath"].ToString()+AccessReader["filename"].ToString() +"' target='_blank'>"+AccessReader["filename"].ToString()+"</a></font></td><td width='20%' align='center'><font class='font_12px'>"+File_Zu+"类文件组</font></td><td width='20%' align='center'><font class='font_12px'>"+ FileType +"</font></td><td width='20%' align='center'><font class='font_12px'>"+ AccessReader["addtime"].ToString() +"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='删 除' onclick=window.document.location.href='FileList_m.aspx?fileid="+AccessReader["id"].ToString()+"&zu="+ Request.QueryString["zu"].ToString() +"' style='Cursor:hand;'></td></tr></table></TD></TR>";

						Rownum++;
						if(Rownum==2) Rownum=0;

					}
					if(FileListString =="")
					{
						FileListString ="<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='center' width='100%' height='7'>此文件组暂无文件</TD></TR>";
					}
					FileList_Builder.Append(FileListString);
					fileliststr.Text =FileList_Builder.ToString(); 

					AccessReader.Close();
					AccessCommand.Dispose();
					AccessConnection.Close();
				}
			}
			// 在此处放置用户代码以初始化页面
		}

		#region Web 窗体设计器生成的代码
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: 该调用是 ASP.NET Web 窗体设计器所必需的。
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// 设计器支持所需的方法 - 不要使用代码编辑器修改
		/// 此方法的内容。
		/// </summary>
		private void InitializeComponent()
		{    

		}
		#endregion
	}
}
