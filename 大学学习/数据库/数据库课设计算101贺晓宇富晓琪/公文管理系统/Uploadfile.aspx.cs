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
using System.IO;
using System.Data.OleDb;

namespace FileManage_Sys
{
	/// <summary>
	/// Uploadfile 的摘要说明。
	/// </summary>
	public partial class Uploadfile : System.Web.UI.Page
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

		protected void bt_upfile_Click(object sender, System.EventArgs e)
		{
			if(UpFile.Value=="")
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('请选择上传文件本地路径');window.location.href='Uploadfile.aspx'; </SCRIPT>");

			}
			else
			{
				string FileName,FilePath,FileArea,FileType,FileExe;
				if(re_filename.Text.Trim()!="")
				{
					FileName = re_filename.Text.Trim().ToString();//重命名
				}
				else
				{
					string[] FileArray;
					FileArray = UpFile.PostedFile.FileName.ToString().Split('\\');
					FileName = FileArray[FileArray.Length-1] ;//文件名
				}
				FilePath = "upload/"+filearea.SelectedValue.ToString()+"/";//上传路径
				FileArea = filearea.SelectedValue.ToString();//文件所属分类

				FileExe = UpFile.PostedFile.FileName.Substring(UpFile.PostedFile.FileName.LastIndexOf("."));//扩展名

				if(FileExe==".doc"|FileExe==".jpg"|FileExe==".xls"|FileExe==".pdf"|FileExe==".dwg"|FileExe==".DOC"|FileExe==".JPG"|FileExe==".XLS"|FileExe==".PDF"|FileExe==".DWG")
				{

					FileType = FileExe.Substring(1,1);//文件类型

					switch(FileExe)
					{
						case ".pdf":
							FileType = "P";	
							break;
						case ".doc":
							FileType = "W";	
							break;
						case ".xls":
							FileType = "E";	
							break;
						case ".jpg":
							FileType = "J";	
							break;
						case ".dwg":
							FileType = "D";	
							break;
						case ".PDF":
							FileType = "P";	
							break;
						case ".DOC":
							FileType = "W";	
							break;
						case ".XLS":
							FileType = "E";	
							break;
						case ".JPG":
							FileType = "J";	
							break;
						case ".DWG":
							FileType = "D";	
							break;
						default:break;
					}



					string SqlStr="";
					string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
					OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
					AccessConnection.Open();//打开数据库
					
					SqlStr = "Select * From files Where filename='"+ FileName +"' And filearea='"+ FileArea +"' And fileexe='"+ FileExe +"' ";
					OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
					OleDbDataReader AccessReader = AccessCommand2.ExecuteReader();
					if(AccessReader.Read())
					{//本目录下有同名同类型文件
						AccessReader.Close();
						AccessCommand2.Dispose();

						Response.Write("<SCRIPT language='JavaScript'>alert('目录"+ FilePath  +"下已经存在文件："+ FileName +"');window.location.href='Uploadfile.aspx'; </SCRIPT>");
					}
					else
					{
						AccessReader.Close();
						AccessCommand2.Dispose();
						if(re_filename.Text.Trim()!="")
						{
							UpFile.PostedFile.SaveAs(Server.MapPath(FilePath+FileName+FileExe));//上传文件
							FileName = FileName +FileExe;
						}
						else
						{
							UpFile.PostedFile.SaveAs(Server.MapPath(FilePath+FileName));//上传文件
						}

						//写入数据库
						SqlStr="Insert Into files(filename,filepath,filearea,fileexe,filetype,addtime) values('"+ FileName +"','"+ FilePath +"','"+ FileArea +"','"+ FileExe +"','"+ FileType +"','"+ System.DateTime.Now.ToString() +"') ";
						OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
						AccessCommand.ExecuteNonQuery();
						AccessCommand.Dispose();
						AccessConnection.Close();

						Response.Write("<SCRIPT language='JavaScript'>alert('成功上传到"+ FilePath  +"，文件名为："+ FileName +"');window.location.href='Uploadfile.aspx'; </SCRIPT>");
					}
				}
				else
				{
					Response.Write("<SCRIPT language='JavaScript'>alert('不允许上传"+ FileExe +"类型的文件');window.location.href='Uploadfile.aspx'; </SCRIPT>");

				}
			}


			
		
		}
	}
}
