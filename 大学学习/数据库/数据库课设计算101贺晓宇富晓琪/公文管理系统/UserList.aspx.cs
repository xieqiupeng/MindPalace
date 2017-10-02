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
	/// UserList 的摘要说明。
	/// </summary>
	public partial class UserList : System.Web.UI.Page
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

			StringBuilder UserList_Builder= new StringBuilder();//记录查询结果
			string UserListString = "";

			string SqlStr="";
			string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//从Web.config文件中获取数据库连接字符串
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//打开数据库

			SqlStr="Select * From Users Where id>0";

			OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

			OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
			int Rownum=0;
	
			while(AccessReader.Read())
			{//提取信息
				
				if(Rownum==0)
					UserListString = UserListString +"<TR bgcolor='#E4E4E4' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+AccessReader["username"].ToString()+"</font></td><td width='50%' align='center'><font class='font_12px'>"+AccessReader["rolename"].ToString()+"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='编 辑' onclick=window.document.location.href='EditUser.aspx?userid="+AccessReader["id"].ToString()+"'  style='Cursor:hand;'></td></tr></table></TD></TR>";
				else
					UserListString = UserListString +"<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+AccessReader["username"].ToString()+"</font></td><td width='50%' align='center'><font class='font_12px'>"+AccessReader["rolename"].ToString()+"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='编 辑' onclick=window.document.location.href='EditUser.aspx?userid="+AccessReader["id"].ToString()+"'  style='Cursor:hand;'></td></tr></table></TD></TR>";

				Rownum++;
				if(Rownum==2) Rownum=0;
				

			}
			UserList_Builder.Append(UserListString);
			userliststr.Text = UserList_Builder.ToString(); 

			AccessReader.Close();
			AccessCommand.Dispose();
			AccessConnection.Close();
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
