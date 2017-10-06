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
	/// FileList_v ��ժҪ˵����
	/// </summary>
	public partial class FileList_v : System.Web.UI.Page
	{
	
		protected void Page_Load(object sender, System.EventArgs e)
		{
			if(Request.QueryString["zu"]!=null)
			{
				string SqlStr="";
				string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
				OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
				AccessConnection.Open();//�����ݿ�
					
				zu_file.Text = Request.QueryString["zu"].ToString();
				string File_Zu;
				File_Zu = Request.QueryString["zu"].ToString();//�ļ���

				StringBuilder FileList_Builder= new StringBuilder();//��¼��ѯ���
				string FileListString = "",RoleStrList="";

				string[] RoleArray;
				string RoleCookieStr = Request.Cookies["UserCookie"]["role"].ToString();
				
				RoleArray = RoleCookieStr.Split(',');

				for(int i=0;i<RoleArray.Length;i++)
				{
					if(i!=(RoleArray.Length-1))
						RoleStrList = RoleStrList + "'"+RoleArray[i].ToString()+"',";
					else
						RoleStrList = RoleStrList + "'"+RoleArray[i].ToString()+"'";
				}


				SqlStr="Select * From files Where filearea='"+ File_Zu +"' And filetype In ("+ RoleStrList.ToLower() +")  Order By Id DESC";

				OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);

				OleDbDataReader AccessReader = AccessCommand.ExecuteReader();
			
				int Rownum=0,Rowid=1;

				string FileType="";//�ļ�����
				while(AccessReader.Read())
				{//��ȡ��Ϣ
					
					switch(AccessReader["fileexe"].ToString())
					{
						case ".pdf":
							FileType = "PDF�ļ�";
							break;
						case ".doc":
							FileType = "WORD�ļ�";
							break;
						case ".xls":
							FileType = "EXCEL�ļ�";
							break;
						case ".jpg":
							FileType = "JPG�ļ�";
							break;
						case ".dwg":
							FileType = "DWG�ļ�";
							break;
						case ".PDF":
							FileType = "PDF�ļ�";
							break;
						case ".DOC":
							FileType = "WORD�ļ�";
							break;
						case ".XLS":
							FileType = "EXCEL�ļ�";
							break;
						case ".JPG":
							FileType = "JPG�ļ�";
							break;
						case ".DWG":
							FileType = "DWG�ļ�";
							break;
						default:break;
					}


					if(Rownum==0)
						FileListString = FileListString +"<TR bgcolor='#E4E4E4' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+ Rowid.ToString() +"</font></td><td width='20%' align='center'><font class='font_12px'><a href='"+ AccessReader["filepath"].ToString()+AccessReader["filename"].ToString() +"' target='_blank'>"+AccessReader["filename"].ToString()+"</a></font></td><td width='20%' align='center'><font class='font_12px'>"+File_Zu+"���ļ���</font></td><td width='20%' align='center'><font class='font_12px'>"+ FileType +"</font></td><td width='20%' align='center'><font class='font_12px'>"+ AccessReader["addtime"].ToString() +"</font></td></tr></table></TD></TR>";
					else
						FileListString = FileListString +"<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='left' width='100%' height='7'><table width='100%'><tr><td width='20%' align='center'><font class='font_12px'>"+ Rowid.ToString() +"</font></td><td width='20%' align='center'><font class='font_12px'><a href='"+ AccessReader["filepath"].ToString()+AccessReader["filename"].ToString() +"' target='_blank'>"+AccessReader["filename"].ToString()+"</a></font></td><td width='20%' align='center'><font class='font_12px'>"+File_Zu+"���ļ���</font></td><td width='20%' align='center'><font class='font_12px'>"+ FileType +"</font></td><td width='20%' align='center'><font class='font_12px'>"+ AccessReader["addtime"].ToString() +"</font></td></tr></table></TD></TR>";

					Rownum++;
					Rowid++;
					if(Rownum==2) Rownum=0;

				}
				if(FileListString =="")
				{
					FileListString ="<TR bgcolor='#FFFFFF' height=30><TD style='FONT-SIZE: 12px' align='center' width='100%' height='7'>���ļ��������ļ�</TD></TR>";
				}
				FileList_Builder.Append(FileListString);
				fileliststr.Text =FileList_Builder.ToString(); 

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
	}
}
