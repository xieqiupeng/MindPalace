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
	/// UserList ��ժҪ˵����
	/// </summary>
	public partial class UserList : System.Web.UI.Page
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

			StringBuilder UserList_Builder= new StringBuilder();//��¼��ѯ���
			string UserListString = "";

			string SqlStr="";
			string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
			OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
			AccessConnection.Open();//�����ݿ�

			SqlStr="Select * From Users Where id>0";

			OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

			OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
			int Rownum=0;
	
			while(AccessReader.Read())
			{//��ȡ��Ϣ
				
				if(Rownum==0)
					UserListString = UserListString +"<TR bgcolor='#E4E4E4' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+AccessReader["username"].ToString()+"</font></td><td width='50%' align='center'><font class='font_12px'>"+AccessReader["rolename"].ToString()+"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='�� ��' onclick=window.document.location.href='EditUser.aspx?userid="+AccessReader["id"].ToString()+"'  style='Cursor:hand;'></td></tr></table></TD></TR>";
				else
					UserListString = UserListString +"<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+AccessReader["username"].ToString()+"</font></td><td width='50%' align='center'><font class='font_12px'>"+AccessReader["rolename"].ToString()+"</font></td><td width='20%' align='center' valign='bottom'><input type='button' class='textinput' style='FONT-SIZE:12px' value='�� ��' onclick=window.document.location.href='EditUser.aspx?userid="+AccessReader["id"].ToString()+"'  style='Cursor:hand;'></td></tr></table></TD></TR>";

				Rownum++;
				if(Rownum==2) Rownum=0;
				

			}
			UserList_Builder.Append(UserListString);
			userliststr.Text = UserList_Builder.ToString(); 

			AccessReader.Close();
			AccessCommand.Dispose();
			AccessConnection.Close();
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
