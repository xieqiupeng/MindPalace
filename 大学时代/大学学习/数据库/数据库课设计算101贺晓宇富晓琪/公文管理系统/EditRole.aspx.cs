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
	/// EditRole 的摘要说明。
	/// </summary>
	public partial class EditRole : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			delrole.Attributes.Add("onclick","javascript :return confirm('你确定删除吗？')");
			if(!Page.IsPostBack)
			{
				string SqlStr="",Roleid;
				Roleid = Request.QueryString["roleid"].ToString();
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//打开数据库

				SqlStr="Select * From Role Where id="+Roleid;

				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

				OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
				if(AccessReader.Read())
				{
					role_name.Text = AccessReader["rolename"].ToString();

				}
				AccessReader.Close();
				AccessCommand.Dispose();
				AccessConnection.Close();
			
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

		protected void delrole_Click(object sender, System.EventArgs e)
		{
			if( Request.QueryString["roleid"]==null)
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('非法参数');window.location.href='RoleList.aspx';</SCRIPT>");
			}
			else
			{
				string SqlStr="",Roleid;
				Roleid = Request.QueryString["roleid"].ToString();
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//打开数据库
			
				SqlStr="DELETE * From Role Where id="+Roleid;

				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

				AccessCommand.ExecuteNonQuery();
			
				AccessCommand.Dispose();
				AccessConnection.Close();

				Response.Write("<SCRIPT language='JavaScript'>alert('删除成功');window.location.href='RoleList.aspx';</SCRIPT>");
			}
		
		}
	}
}
