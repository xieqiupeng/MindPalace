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

public partial class 注册支援地区 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String cs = "Server=localhost;database=DBTestConnectionString;Data Source=jzb-PC;Initial Catalog=DBTest;Integrated Security =True;";
        SqlConnection DBTest = new SqlConnection(cs);
        DBTest.Open();



        string hname = TextBox1.Text;
        //char[] vname = vname1.ToCharArray();



        string hpassword = TextBox2.Text;
        // char[] Vpassword = Vpassword1.ToCharArray();

        string hnumber = TextBox3.Text;
        //char[] vbirth = vbirth1.ToCharArray();

        string haddress = TextBox4.Text;
        //char[] vnumber = vnumber1.ToCharArray();

        string hdetail = TextBox5.Text;
        //char[] vaddress = vaddress1.ToCharArray();

        //string strSql = "select * from volunteer";
        string strSql = "insert into help values('" + hname + "','" + hpassword + "','" + hnumber + "','" + haddress + "','" + hdetail + "')";
        //OperateDataBase odb = new OperateDataBase();

        SqlCommand dbcmd = new SqlCommand(strSql, DBTest);

        try
        {
            dbcmd.ExecuteNonQuery();
            Server.Transfer("注册成功.aspx");

        }
        catch
        {

           // Response.Write("<script language=javascript> alert('添加失败');location='javascript:history.go(-1)'</script>");

        }
        finally
        {
            DBTest.Close();
        }
    }
}
