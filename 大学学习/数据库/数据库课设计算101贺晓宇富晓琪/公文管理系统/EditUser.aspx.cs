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
	/// EditUser 的摘要说明。
	/// </summary>
	public partial class EditUser : System.Web.UI.Page
	{
		protected string UserPwd;
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			deluser.Attributes.Add("onclick","javascript :return confirm('你确定删除吗？')");

			if(!Page.IsPostBack)
			{
				string SqlStr="";
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//打开数据库
				SqlStr="Select * From Role  Order By Id DESC";
				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

				OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
				int i=0;
				ListItem AddItem ;
				while(AccessReader.Read())
				{
					AddItem = new ListItem(AccessReader["rolename"].ToString(),AccessReader["role"].ToString()+"|"+AccessReader["rolename"].ToString());
					selrole.Items.Add(AddItem);
					i++;

				}
				if(i==0)
				{
					AddItem = new ListItem("尚未创建角色","0");
					selrole.Items.Add(AddItem);
				}
				AccessReader.Close();

				AccessCommand.Dispose();
				SqlStr = "Select * From users Where id="+Request.QueryString["userid"].ToString();
				OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
				AccessReader = AccessCommand2.ExecuteReader();
				if(AccessReader.Read())
				{
					username.Text = AccessReader["username"].ToString();
					//UserPwd = AccessReader["pwd"].ToString();

				}
				AccessReader.Close();
				AccessCommand2.Dispose();

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

		protected void adduser_Click(object sender, System.EventArgs e)
		{
			string SqlStr="";
			string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//打开数据库
			SqlStr = "Select * From users Where id="+Request.QueryString["userid"].ToString();
			OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
			OleDbDataReader AccessReader = AccessCommand2.ExecuteReader();
			if(AccessReader.Read())
			{
				//username.Text = AccessReader["username"].ToString();
				UserPwd = AccessReader["pwd"].ToString();

			}
			AccessReader.Close();
			AccessCommand2.Dispose();



			if(password.Text.Trim().ToString()==UserPwd)
			{//输入原密码正确
				string[] RoleArray;
				RoleArray = selrole.SelectedValue.ToString().Split('|');
				SqlStr="Update users Set username='"+ username.Text.Trim().ToString() +"',pwd='"+password2.Text.Trim().ToString()+"',rolename='"+ RoleArray[1].ToString() +"',role='"+ RoleArray[0].ToString() +"' Where id="+Request.QueryString["userid"].ToString();
				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
				AccessCommand.ExecuteNonQuery();
				AccessCommand.Dispose();
				AccessConnection.Close();
				Response.Write("<SCRIPT language='JavaScript'>alert('帐户修改成功');</SCRIPT>");
			}
			else
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('原密码输入错误');</SCRIPT>");
			}
		
		}

		protected void deluser_Click(object sender, System.EventArgs e)
		{
			
				string SqlStr="";
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//打开数据库

				SqlStr = "Delete * From users Where id="+Request.QueryString["userid"].ToString();
				OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
				AccessCommand2.ExecuteNonQuery();
				AccessCommand2.Dispose();
				AccessConnection.Close();
				Response.Write("<SCRIPT language='JavaScript'>alert('删除成功');window.location.href='UserList.aspx';</SCRIPT>");
		}
	}
}
