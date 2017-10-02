using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Popups;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;


namespace SqliteforMetro
{

    public sealed partial class LoginPage : Page
    {

        #region 构造函数
        public LoginPage()
        {
            this.InitializeComponent();
        }
        #endregion

        #region 界面相关
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            DBHelper.Initilaze();
        }

        async void AlertUser(string info)
        {
            MessageDialog msg = new MessageDialog("警告", info);

            await msg.ShowAsync();
        }
        #endregion

        #region Event
        private void DoLogin(object sender, RoutedEventArgs e)
        {

            if (UserNameTextBox.Text == string.Empty || PasswordTextBox.Password == string.Empty)
            {
                AlertUser("请填写完整的登录信息");
                return;
            }

            //Start Login
            (sender as Button).Visibility = Visibility.Collapsed;
            LoginProgressRing.IsActive = true;
            Auth(UserNameTextBox.Text, PasswordTextBox.Password);
            (sender as Button).Visibility = Visibility.Visible;

        }

        #endregion

        void Auth(string userId, string password)
        {
            try
            {
                var currentUserLoginInfo = DBHelper.GetLoginInfo().Single(a => a.UserId.Equals(userId) && a.Password.Equals(password));

                App.currentUser = DBHelper.GetUsers().Single(a => a.Id.Equals(userId));

                switch (currentUserLoginInfo.Level)
                {
                    case 0:
                        Frame.Navigate(typeof(Employee.EmployeePage), "EMPLOYEE");
                        break;
                    case 10:
                        Frame.Navigate(typeof(Employee.EmployeePage), "BOSS");
                        break;
                    default:
                        Frame.Navigate(typeof(Employee.EmployeePage), "EMPLOYEE");
                        break;
                }
            }
            catch (Exception ex)
            {
                AlertUser("用户名密码错误");
            }

        }

        private void CreateAccount(object sender, RoutedEventArgs e)
        {

        }
    }
}
