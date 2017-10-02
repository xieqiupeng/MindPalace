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

public partial class Default2 : System.Web.UI.Page
{

    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void 志愿者_CheckedChanged(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        if (志愿者.Checked)
            Response.Redirect("注册志愿者.aspx");
        else if (NGO.Checked)
            Server.Transfer("注册NGO.aspx");
        else if (支援地区.Checked)
            Server.Transfer("注册支援地区.aspx");
    }
    protected void NGO_CheckedChanged(object sender, EventArgs e)
    {

    }
}
