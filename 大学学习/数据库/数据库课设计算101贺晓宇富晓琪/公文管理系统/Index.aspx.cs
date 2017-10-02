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
	/// Index ��ժҪ˵����
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
			string RoledetailStr = "  �����Բ鿴��";
			Rolearray = Request.Cookies["UserCookie"]["role"].ToString().Split(',');
			for(int i=0;i<Rolearray.Length;i++)
			{
				switch(Rolearray[i].ToString())
				{
					case "P":
						RoledetailStr = RoledetailStr + "PDF�ļ� ";
						break;
					case "W":
						RoledetailStr = RoledetailStr + "WORD�ļ� ";
						break;
					case "E":
						RoledetailStr = RoledetailStr + "EXCEL�ļ� ";
						break;
					case "J":
						RoledetailStr = RoledetailStr + "JPG�ļ� ";
						break;
					case "D":
						RoledetailStr = RoledetailStr + "DWG�ļ� ";
						break;
					default:break;
				}
			}
			role.Text = role.Text + RoledetailStr;
			// �ڴ˴������û������Գ�ʼ��ҳ��

		}

		#region Web ������������ɵĴ���
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: �õ����� ASP.NET Web ���������������ġ�
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// �����֧������ķ��� - ��Ҫʹ�ô���༭���޸�
		/// �˷��������ݡ�
		/// </summary>
		private void InitializeComponent()
		{    

		}
		#endregion
	}
}
