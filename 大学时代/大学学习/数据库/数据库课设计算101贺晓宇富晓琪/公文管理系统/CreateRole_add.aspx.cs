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
	public partial class WebForm1 : System.Web.UI.Page
	{
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(!(Request.QueryString["rolename"]==null|Request.QueryString["role"]==null))
			{
				string SqlStr="",Flag;
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�
				Flag = Request.QueryString["flag"].ToString();
				OleDbCommand AccessCommand;
				OleDbCommand AccessCommand2;
				


				switch(Flag)
				{
					case "add":

						SqlStr="Select * From role Where rolename='"+ Request.QueryString["rolename"].ToString().Trim() +"'";
						AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
						OleDbDataReader AccessReader = AccessCommand2.ExecuteReader();
						if(AccessReader.Read())
						{
							AccessReader.Close();
							AccessCommand2.Dispose();
							Response.Write("<SCRIPT language='JavaScript'>alert('��ɫ�����Ѿ�����');window.location.href='CreateRole.aspx'; </SCRIPT>");

						}
						else
						{
							AccessReader.Close();
							AccessCommand2.Dispose();
							SqlStr="Insert Into role(rolename,role) values('"+ Request.QueryString["rolename"].ToString().Trim()+"','"+ Request.QueryString["role"].ToString().Trim() +"') ";
							AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
							AccessCommand.ExecuteNonQuery();
							AccessCommand.Dispose();
							AccessConnection.Close();
							Response.Write("<SCRIPT language='JavaScript'>alert('��ɫ�����ɹ���');window.location.href='CreateRole.aspx'; </SCRIPT>");

						}
						break;
					case "edit":
						SqlStr="Update role set rolename='"+ Request.QueryString["rolename"].ToString().Trim() +"',role='"+Request.QueryString["role"].ToString().Trim()+"' Where id="+Request.QueryString["roleid"].ToString();
						AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
						AccessCommand.ExecuteNonQuery();
						AccessCommand.Dispose();
						AccessConnection.Close();
						Response.Write("<SCRIPT language='JavaScript'>alert('��ɫ�޸ĳɹ���');window.location.href='RoleList.aspx'; </SCRIPT>");
						break;
					default:break;
				}
			}
			else
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('�Ƿ�������');window.location.href='CreateRole.aspx'; </SCRIPT>");

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
	}
}
