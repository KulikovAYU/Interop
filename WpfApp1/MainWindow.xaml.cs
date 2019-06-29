﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using ManagedClass;
using ManagedEmp = ManagedClass.ManagedEmp;

namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        void Create()
        {
            
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            ManagedClass.ManagedEmp me = new ManagedClass.ManagedEmp();
            me.name = EmpName.Text;
            me.adress = EmpAdress.Text;
            me.zipCode = Int32.Parse(EmpZipCode.Text);
            me.ConvertToNative();

            EmpNameRes.Text = me.name;
            EmpAdressRes.Text = me.adress;
            EmpZipCodeRes.Text = me.zipCode.ToString();
        }

        private void Button_Click1(object sender, RoutedEventArgs e)
        {

            ManagedClass.ITestManagedInterface me = new ExtendedManagedEmp();
            me.Name = EmpName.Text;
            me.Adress = EmpAdress.Text;
            me.ZipCode = Int32.Parse(EmpZipCode.Text);
            me.ConvertToNative();

            EmpNameRes.Text = me.Name;
            EmpAdressRes.Text = me.Adress;
            EmpZipCodeRes.Text = me.ZipCode.ToString();
        }
    }
}
