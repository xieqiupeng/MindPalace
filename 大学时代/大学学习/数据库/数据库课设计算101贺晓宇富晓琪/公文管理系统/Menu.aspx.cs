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
	/// Menu ��ժҪ˵����
	/// </summary>
	public partial class Menu : System.Web.UI.Page
	{

		
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			// �ڴ˴������û������Գ�ʼ��ҳ��
			if(Request.Cookies["UserCookie"]==null)
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('�Ƿ������������µ�½');window.parent.location.href='login.aspx';</SCRIPT>");
			}
			else
			{
				string Username;
				string[] Role;
				Username = Request.Cookies["UserCookie"]["username"].ToString();

				Role = Request.Cookies["UserCookie"]["role"].ToString().Split(',');

				if(Role[0].ToString()=="1")
				{
					
				}

			}
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
