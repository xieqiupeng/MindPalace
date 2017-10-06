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

namespace FileManage_Sys
{
	/// <summary>
	/// Index 的摘要说明。
	/// </summary>
	public partial class Index : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.Cookies["UserCookie"]!=null)
			{
				username.Text=Request.Cookies["UserCookie"]["username"].ToString();
				role.Text=Request.Cookies["UserCookie"]["rolename"].ToString();
			}
			else
			{
				Response.Write("<SCRIPT language='JavaScript'>window.parent.location.href='login.aspx';</SCRIPT>");
				//Response.Redirect("Login.aspx");
			}

			string[] Rolearray;
			string RoledetailStr = "  您可以查看：";
			Rolearray = Request.Cookies["UserCookie"]["role"].ToString().Split(',');
			for(int i=0;i<Rolearray.Length;i++)
			{
				switch(Rolearray[i].ToString())
				{
					case "P":
						RoledetailStr = RoledetailStr + "PDF文件 ";
						break;
					case "W":
						RoledetailStr = RoledetailStr + "WORD文件 ";
						break;
					case "E":
						RoledetailStr = RoledetailStr + "EXCEL文件 ";
						break;
					case "J":
						RoledetailStr = RoledetailStr + "JPG文件 ";
						break;
					case "D":
						RoledetailStr = RoledetailStr + "DWG文件 ";
						break;
					default:break;
				}
			}
			role.Text = role.Text + RoledetailStr;
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
