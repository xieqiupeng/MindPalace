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
using System.IO;
using System.Data.OleDb;

namespace FileManage_Sys
{
	/// <summary>
	/// Uploadfile ��ժҪ˵����
	/// </summary>
	public partial class Uploadfile : System.Web.UI.Page
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

		protected void bt_upfile_Click(object sender, System.EventArgs e)
		{
			if(UpFile.Value=="")
			{
				Response.Write("<SCRIPT language='JavaScript'>alert('��ѡ���ϴ��ļ�����·��');window.location.href='Uploadfile.aspx'; </SCRIPT>");

			}
			else
			{
				string FileName,FilePath,FileArea,FileType,FileExe;
				if(re_filename.Text.Trim()!="")
				{
					FileName = re_filename.Text.Trim().ToString();//������
				}
				else
				{
					string[] FileArray;
					FileArray = UpFile.PostedFile.FileName.ToString().Split('\\');
					FileName = FileArray[FileArray.Length-1] ;//�ļ���
				}
				FilePath = "upload/"+filearea.SelectedValue.ToString()+"/";//�ϴ�·��
				FileArea = filearea.SelectedValue.ToString();//�ļ���������

				FileExe = UpFile.PostedFile.FileName.Substring(UpFile.PostedFile.FileName.LastIndexOf("."));//��չ��

				if(FileExe==".doc"|FileExe==".jpg"|FileExe==".xls"|FileExe==".pdf"|FileExe==".dwg"|FileExe==".DOC"|FileExe==".JPG"|FileExe==".XLS"|FileExe==".PDF"|FileExe==".DWG")
				{

					FileType = FileExe.Substring(1,1);//�ļ�����

					switch(FileExe)
					{
						case ".pdf":
							FileType = "P";	
							break;
						case ".doc":
							FileType = "W";	
							break;
						case ".xls":
							FileType = "E";	
							break;
						case ".jpg":
							FileType = "J";	
							break;
						case ".dwg":
							FileType = "D";	
							break;
						case ".PDF":
							FileType = "P";	
							break;
						case ".DOC":
							FileType = "W";	
							break;
						case ".XLS":
							FileType = "E";	
							break;
						case ".JPG":
							FileType = "J";	
							break;
						case ".DWG":
							FileType = "D";	
							break;
						default:break;
					}



					string SqlStr="";
					string ConnectionStr = "PROVIDER=Microsoft.Jet.OLEDB.4.0;DATA Source="+Server.MapPath(System.Configuration.ConfigurationSettings.AppSettings["ConnectionStr"].ToString());//��Web.config�ļ��л�ȡ���ݿ������ַ���
					OleDbConnection AccessConnection = new OleDbConnection(ConnectionStr);
					AccessConnection.Open();//�����ݿ�
					
					SqlStr = "Select * From files Where filename='"+ FileName +"' And filearea='"+ FileArea +"' And fileexe='"+ FileExe +"' ";
					OleDbCommand AccessCommand2 = new OleDbCommand(SqlStr,AccessConnection);
					OleDbDataReader AccessReader = AccessCommand2.ExecuteReader();
					if(AccessReader.Read())
					{//��Ŀ¼����ͬ��ͬ�����ļ�
						AccessReader.Close();
						AccessCommand2.Dispose();

						Response.Write("<SCRIPT language='JavaScript'>alert('Ŀ¼"+ FilePath  +"���Ѿ������ļ���"+ FileName +"');window.location.href='Uploadfile.aspx'; </SCRIPT>");
					}
					else
					{
						AccessReader.Close();
						AccessCommand2.Dispose();
						if(re_filename.Text.Trim()!="")
						{
							UpFile.PostedFile.SaveAs(Server.MapPath(FilePath+FileName+FileExe));//�ϴ��ļ�
							FileName = FileName +FileExe;
						}
						else
						{
							UpFile.PostedFile.SaveAs(Server.MapPath(FilePath+FileName));//�ϴ��ļ�
						}

						//д�����ݿ�
						SqlStr="Insert Into files(filename,filepath,filearea,fileexe,filetype,addtime) values('"+ FileName +"','"+ FilePath +"','"+ FileArea +"','"+ FileExe +"','"+ FileType +"','"+ System.DateTime.Now.ToString() +"') ";
						OleDbCommand AccessCommand = new OleDbCommand(SqlStr,AccessConnection);
						AccessCommand.ExecuteNonQuery();
						AccessCommand.Dispose();
						AccessConnection.Close();

						Response.Write("<SCRIPT language='JavaScript'>alert('�ɹ��ϴ���"+ FilePath  +"���ļ���Ϊ��"+ FileName +"');window.location.href='Uploadfile.aspx'; </SCRIPT>");
					}
				}
				else
				{
					Response.Write("<SCRIPT language='JavaScript'>alert('�������ϴ�"+ FileExe +"���͵��ļ�');window.location.href='Uploadfile.aspx'; </SCRIPT>");

				}
			}


			
		
		}
	}
}
