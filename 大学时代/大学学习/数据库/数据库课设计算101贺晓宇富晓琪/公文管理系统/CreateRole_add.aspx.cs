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
using System.Data.OleDb;

namespace FileManage_Sys
{
	/// <summary>
	/// WebForm1 的摘要说明。
	/// </summary>
	public partial class WebForm1 : System.Web.UI.Page
	{
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(!(Request.QueryString["rolename"]==null|Request.QueryString["role"]==null))
			{
				string SqlStr="",Flag;
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//打开数据库
				Flag = Request.QueryString["flag"].ToString();
				OleDbCommand AccessCommand;
				OleDbCommand AccessCommand2;
				


				switch(Flag)
				{
					case "add":

						SqlStr="Select * From role Where rolename='"+ Request.QueryString["rolename"].ToString().Trim() +"'";
						AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
						OleDbDataReader AccessReader = AccessCommand2.ExecuteReader();
						if(AccessReader.Read())
						{
							AccessReader.Close();
							AccessCommand2.Dispose();
							Response.Write("<SCRIPT language='JavaScript'>alert('角色名称已经存在');window.location.href='CreateRole.aspx'; </SCRIPT>");

						}
						else
						{
							AccessReader.Close();
							AccessCommand2.Dispose();
							SqlStr="Insert Into role(rolename,role) values('"+ Request.QueryString["rolename"].ToString().Trim()+"','"+ Request.QueryString["role"].ToString().Trim() +"') ";
							AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
							AccessCommand.ExecuteNonQuery();
							AccessCommand.Dispose();
							AccessConnection.Close();
							Response.Write("<SCRIPT language='JavaScript'>alert('角色创建成功！');window.location.href='CreateRole.aspx'; </SCRIPT>");

						}
						break;
					case "edit":
						SqlStr="Update role set rolename='"+ Request.QueryString["rolename"].ToString().Trim() +"',role='"+Request.QueryString["role"].ToString().Trim()+"' Where id="+Request.QueryString["roleid"].ToString();
						AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
						AccessCommand.ExecuteNonQuery();
						AccessCommand.Dispose();
						AccessConnection.Close();
						Response.Write("<SCRIPT language='JavaScript'>alert('角色修改成功！');window.location.href='RoleList.aspx'; </SCRIPT>");
						break;
					default:break;
				}
			}
			else
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('非法参数！');window.location.href='CreateRole.aspx'; </SCRIPT>");

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
