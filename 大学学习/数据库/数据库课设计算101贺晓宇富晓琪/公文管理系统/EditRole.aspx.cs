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
	/// EditRole ��ժҪ˵����
	/// </summary>
	public partial class EditRole : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			delrole.Attributes.Add("onclick","javascript :return confirm('��ȷ��ɾ����')");
			if(!Page.IsPostBack)
			{
				string SqlStr="",Roleid;
				Roleid = Request.QueryString["roleid"].ToString();
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�

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

		protected void delrole_Click(object sender, System.EventArgs e)
		{
			if( Request.QueryString["roleid"]==null)
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('�Ƿ�����');window.location.href='RoleList.aspx';</SCRIPT>");
			}
			else
			{
				string SqlStr="",Roleid;
				Roleid = Request.QueryString["roleid"].ToString();
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�
			
				SqlStr="DELETE * From Role Where id="+Roleid;

				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

				AccessCommand.ExecuteNonQuery();
			
				AccessCommand.Dispose();
				AccessConnection.Close();

				Response.Write("<SCRIPT language='JavaScript'>alert('ɾ���ɹ�');window.location.href='RoleList.aspx';</SCRIPT>");
			}
		
		}
	}
}
