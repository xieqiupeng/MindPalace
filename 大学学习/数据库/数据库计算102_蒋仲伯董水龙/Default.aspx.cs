using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

public partial class _Default : System.Web.UI.Page
{


    protected void Page_Load(object sender, EventArgs e)
    {
        

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default2.aspx");
    }

    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {

    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        if (DropDownList1.SelectedItem.Value=="志愿者")
        {
            Server.Transfer("志愿者登录.aspx");
        }
        else if (DropDownList1.SelectedItem.Value == "NGO")
        {
            Server.Transfer("NGO登录.aspx");
        }
        else if (DropDownList1.SelectedItem.Value == "支援地区")
        {
            Server.Transfer("支援地区登录.aspx");
        }
    }
}
