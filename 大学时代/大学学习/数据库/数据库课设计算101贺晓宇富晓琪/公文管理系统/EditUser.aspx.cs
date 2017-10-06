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
	/// EditUser ��ժҪ˵����
	/// </summary>
	public partial class EditUser : System.Web.UI.Page
	{
		protected string UserPwd;
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			deluser.Attributes.Add("onclick","javascript :return confirm('��ȷ��ɾ����')");

			if(!Page.IsPostBack)
			{
				string SqlStr="";
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�
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
					AddItem = new ListItem("��δ������ɫ","0");
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

		protected void adduser_Click(object sender, System.EventArgs e)
		{
			string SqlStr="";
			string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//�����ݿ�
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
			{//����ԭ������ȷ
				string[] RoleArray;
				RoleArray = selrole.SelectedValue.ToString().Split('|');
				SqlStr="Update users Set username='"+ username.Text.Trim().ToString() +"',pwd='"+password2.Text.Trim().ToString()+"',rolename='"+ RoleArray[1].ToString() +"',role='"+ RoleArray[0].ToString() +"' Where id="+Request.QueryString["userid"].ToString();
				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
				AccessCommand.ExecuteNonQuery();
				AccessCommand.Dispose();
				AccessConnection.Close();
				Response.Write("<SCRIPT language='JavaScript'>alert('�ʻ��޸ĳɹ�');</SCRIPT>");
			}
			else
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('ԭ�����������');</SCRIPT>");
			}
		
		}

		protected void deluser_Click(object sender, System.EventArgs e)
		{
			
				string SqlStr="";
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�

				SqlStr = "Delete * From users Where id="+Request.QueryString["userid"].ToString();
				OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
				AccessCommand2.ExecuteNonQuery();
				AccessCommand2.Dispose();
				AccessConnection.Close();
				Response.Write("<SCRIPT language='JavaScript'>alert('ɾ���ɹ�');window.location.href='UserList.aspx';</SCRIPT>");
		}
	}
}
