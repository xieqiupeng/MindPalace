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
	public partial class Login : System.Web.UI.Page
	{
		public string ConnectionStr;
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.QueryString["flag"]!=null)
			{
				HttpCookie UserCookie = new HttpCookie("UserCookie");
				UserCookie.Values["username"] = "";//用户名
				UserCookie.Values["rolename"] = "";//角色名称
				UserCookie.Values["role"] = "";//角色类型
				Response.Cookies.Add(UserCookie);

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

		protected void loginin_Click(object sender, System.EventArgs e)
		{

			ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
			string Username,Password,SqlStr;
			Username = username.Text.Trim();
			Password = password.Text.Trim();
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//打开数据库

			SqlStr="Select * From Users Where username='"+Username+"' And pwd='"+Password+"'";

			OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

			OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
			if(AccessReader.Read())
			{//验证通过，提取信息,发送Cookie,转入操作页面

				HttpCookie UserCookie = new HttpCookie("UserCookie");
				UserCookie.Values["username"] = AccessReader["username"].ToString();//用户名
				UserCookie.Values["rolename"] = AccessReader["rolename"].ToString();//角色名称
				UserCookie.Values["role"] = AccessReader["role"].ToString();//角色类型
				Response.Cookies.Add(UserCookie);
				AccessReader.Close();
				AccessCommand.Dispose();
				AccessConnection.Close();
				Response.Redirect("Default.htm");

			}
			else
			{//验证失败
				Response.Write("<SCRIPT language='JavaScript'>alert('用户名或密码错误！');</SCRIPT>");
				AccessReader.Close();
				AccessCommand.Dispose();
				AccessConnection.Close();
			}

		}
	}
}
