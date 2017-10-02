using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

public partial class NGO登录 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String ConString = "Server=localhost;database=DBTestConnectionString;Data Source=jzb-PC;Initial Catalog=DBTest;Integrated Security =True;"; //***改为你自己的 
        SqlConnection con = new SqlConnection(ConString);
        con.Open();

        string user = this.TextBox1.Text.Trim();
        string pw = this.TextBox2.Text.Trim();
        string sql = "select * from ngo where nname='" + user + "' and Npassword='" + pw + "'";



        SqlCommand cmd = new SqlCommand(sql, con);
        SqlDataReader reader = cmd.ExecuteReader();

        //如果读取成功就打开新窗口,并关闭当前窗口,否则显示错误信息 
        if (reader.Read() == true)
        {
            Server.Transfer("NGO信息.aspx");
            //frmMain Main = new frmMain();
            //Main.Show();
            // this.Visible = false;
        }
        else
        {
        }
    }
}
