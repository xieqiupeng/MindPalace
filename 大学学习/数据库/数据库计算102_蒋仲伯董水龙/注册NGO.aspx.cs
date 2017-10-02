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
public partial class 注册NGO : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String cs = "Server=localhost;database=DBTestConnectionString;Data Source=jzb-PC;Initial Catalog=DBTest;Integrated Security =True;";
        SqlConnection DBTest = new SqlConnection(cs);
        DBTest.Open();



        string Nname = TextBox1.Text;
        //char[] vname = vname1.ToCharArray();



        string Npassword = TextBox2.Text;
        // char[] Vpassword = Vpassword1.ToCharArray();

        string Nnumber = TextBox3.Text;
        //char[] vbirth = vbirth1.ToCharArray();


        string Naddress1 = TextBox4.Text;
        //char[] vaddress = vaddress1.ToCharArray();

        //string strSql = "select * from volunteer";
        string strSql = "insert into ngo values('" + Nname + "','" + Npassword + "','" + Nnumber + "','" + Naddress1 + "')";
        //OperateDataBase odb = new OperateDataBase();

        SqlCommand dbcmd = new SqlCommand(strSql, DBTest);

        try
        {
            dbcmd.ExecuteNonQuery();
            Server.Transfer("注册成功.aspx");

        }
        catch
        {

            //Response.Write("<script language=javascript> alert('添加失败');location='javascript:history.go(-1)'</script>");

        }
        finally
        {
            DBTest.Close();
        }
    }
}
