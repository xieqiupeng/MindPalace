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
	/// CreateRole ��ժҪ˵����
	/// </summary>
	public partial class CreateRole : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.Cookies["UserCookie"]["role"]!=null)
			{
				if(Request.Cookies["UserCookie"]["role"].ToString().Length!=9)
				{
					Response.Write("<SCRIPT language='JavaScript'>alert('�����ǹ���Ա��');window.parent.location.href='Login.aspx'; </SCRIPT>");
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

		private void addrole_Click(object sender, System.EventArgs e)
		{
			/*string SelectItemStr="";
			string SqlStr;
			for(int i=0;i<selectItems.Items.Count;i++)
			{
				if((selectItems.Items.Count-1)==i)
					SelectItemStr = SelectItemStr+selectItems.Items[i].Value.ToString();
				else
					SelectItemStr = SelectItemStr+selectItems.Items[i].Value.ToString()+",";

			}
			
			//string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
			//OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			//AccessConnection.Open();//�����ݿ�
			//SqlStr="Insert Into role(rolename,role) values('"+ role_name.Text.ToString().Trim()+"','"+ SelectItemStr +"') ";
			//OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
			//AccessCommand.ExecuteNonQuery();
			//AccessCommand.Dispose();
			//AccessConnection.Close();
			//Response.Write("<SCRIPT language='JavaScript'>alert('��ɫ�����ɹ���1 "+selectItems.Items.Count.ToString()+" 1');</SCRIPT>");
			//Response.Redirect("CreateRole_add.aspx?rolename="+role_name.Text.Trim()+"&role="+SelectItemStr);
			*/
		
		}
	}
}
