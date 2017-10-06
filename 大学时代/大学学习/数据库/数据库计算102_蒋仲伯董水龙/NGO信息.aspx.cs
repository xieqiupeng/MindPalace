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

public partial class NGO信息 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String cs = "Server=localhost;database=DBTestConnectionString;Data Source=jzb-PC;Initial Catalog=DBTest;Integrated Security =True;";
        SqlConnection DBTest = new SqlConnection(cs);
        DBTest.Open();






        string nname = TextBox1.Text;
        // char[] Vpassword = Vpassword1.ToCharArray();

        string vname = TextBox2.Text;
        //char[] vbirth = vbirth1.ToCharArray();


        string access = TextBox3.Text;
        //char[] vaddress = vaddress1.ToCharArray();

        //string strSql = "select * from volunteer";
        string strSql = "insert into nvassess values('" + nname + "','" + vname + "','" + access + "')";
        //OperateDataBase odb = new OperateDataBase();

        SqlCommand dbcmd = new SqlCommand(strSql, DBTest);

        try
        {
            dbcmd.ExecuteNonQuery();
            Response.Write("<script language=javascript> alert('评论添加成功');location='javascript:history.go(-1)'</script>");
            Server.Transfer("Default.aspx");

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
