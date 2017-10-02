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
	/// CreatUser 的摘要说明。
	/// </summary>
	public partial class CreatUser : System.Web.UI.Page
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
			if(username.Text=="")
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('请填写用户名');window.location.href='CreateUser.aspx'; </SCRIPT>");

			}
			else
			{
				string SqlStr;
				string[] Selrole_Array;
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
				OleDbConnection AccessConnection1 = new OleDbConnection(ConnectionStr);
				AccessConnection1.Open();//打开数据库

				SqlStr = "Select * From Users Where username='"+ username.Text +"'";
				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection1);;
				
				OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
				if(AccessReader.Read())
				{
					AccessReader.Close();
					AccessCommand.Dispose();
					Response.Write("<SCRIPT language='JavaScript'>alert('用户名称已经存在');window.location.href='CreateRole.aspx'; </SCRIPT>");

				}
				else
				{
					if(password.Text!=password2.Text)
					{
						Response.Write("<SCRIPT language='JavaScript'>alert('两次输入的密码不一致');window.location.href='CreateUser.aspx'; </SCRIPT>");
					}
					else
					{
						
						OleDbCommand AccessCommand1;
						Selrole_Array = selrole.SelectedValue.ToString().Split('|');
			
						SqlStr = "Insert Into users(username,pwd,rolename,role,addtime) values('"+username.Text.ToString()+"','"+password.Text.ToString()+"','"+Selrole_Array[1].ToString()+"','"+Selrole_Array[0].ToString()+"','"+System.DateTime.Now.ToString()+"')";
			
						AccessCommand1 = new OleDbCommand(SqlStr,AccessConnection1);
						AccessCommand1.ExecuteNonQuery();
			
						AccessCommand1.Dispose();
						AccessConnection1.Close();
						Response.Write("<SCRIPT language='JavaScript'>alert('帐户创建成功！');window.location.href='CreateUser.aspx'; </SCRIPT>");
					}
				}
			}
		}
	}
}
