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
	/// WebForm1 ��ժҪ˵����
	/// </summary>
	public partial class Login : System.Web.UI.Page
	{
		public string ConnectionStr;
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.QueryString["flag"]!=null)
			{
				HttpCookie UserCookie = new HttpCookie("UserCookie");
				UserCookie.Values["username"] = "";//�û���
				UserCookie.Values["rolename"] = "";//��ɫ����
				UserCookie.Values["role"] = "";//��ɫ����
				Response.Cookies.Add(UserCookie);

			}
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

		protected void loginin_Click(object sender, System.EventArgs e)
		{

			ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
			string Username,Password,SqlStr;
			Username = username.Text.Trim();
			Password = password.Text.Trim();
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//�����ݿ�

			SqlStr="Select * From Users Where username='"+Username+"' And pwd='"+Password+"'";

			OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

			OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
			if(AccessReader.Read())
			{//��֤ͨ������ȡ��Ϣ,����Cookie,ת�����ҳ��

				HttpCookie UserCookie = new HttpCookie("UserCookie");
				UserCookie.Values["username"] = AccessReader["username"].ToString();//�û���
				UserCookie.Values["rolename"] = AccessReader["rolename"].ToString();//��ɫ����
				UserCookie.Values["role"] = AccessReader["role"].ToString();//��ɫ����
				Response.Cookies.Add(UserCookie);
				AccessReader.Close();
				AccessCommand.Dispose();
				AccessConnection.Close();
				Response.Redirect("Default.htm");

			}
			else
			{//��֤ʧ��
				Response.Write("<SCRIPT language='JavaScript'>alert('�û������������');</SCRIPT>");
				AccessReader.Close();
				AccessCommand.Dispose();
				AccessConnection.Close();
			}

		}
	}
}
