using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Suanfa
{

    public partial class main : Form
    {


        public main()
        {
            InitializeComponent();
        }

        private void shortline_Click(object sender, EventArgs e)
        {
            switch(textBox1.Text)
            {
                case "A":  pictureBox2.Load("0.jpg");
                    break;
                case "B": pictureBox2.Load("1.jpg");
                    break;
                case "C": pictureBox2.Load("2.jpg");
                    break;
                case "D": pictureBox2.Load("3.jpg");
                    break;
                case "E": pictureBox2.Load("4.jpg");
                    break;
                case "F": pictureBox2.Load("5.jpg");
                    break;
                case "G": pictureBox2.Load("6.jpg");
                    break;
                case "H": pictureBox2.Load("7.jpg");
                    break;
                case "I": pictureBox2.Load("8.jpg");
                    break;
                case "J": pictureBox2.Load("9.jpg");
                    break;
                default: MessageBox.Show("输入错误，请重新输入"); return;
            }
            
        }

        private void search_Click(object sender, EventArgs e)
        {
            switch (textBox3.Text)
            {
                case "A": sushe ss = new sushe(); 
                    ss.Show();
                    break;
                case "B": shitang st = new shitang();
                    st.Show();
                    break;
                case "C": xuehuo xh = new xuehuo();
                    xh.Show();
                    break;
                case "D": wenshi ws = new wenshi();
                    ws.Show();
                    break;
                case "E": xingzheng xz = new xingzheng();
                    xz.Show();
                    break;
                case "F": wenti wt = new wenti();
                    wt.Show();
                    break;
                case "G": zhonglou zl = new zhonglou();
                    zl.Show();
                    break;
                case "H": library l = new library();
                    l.Show();
                    break;
                case "I": caochang cc = new caochang();
                    cc.Show();
                    break;
                case "J": guangchang gc = new guangchang();
                    gc.Show();
                    break;
                default: MessageBox.Show("输入错误，请重新输入"); return;
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
