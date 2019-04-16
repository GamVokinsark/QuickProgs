using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Symbols
{
    public partial class Form1 : Form
    {
        static string result = "";
        static string[] dictionRu;
        static string[] dictionEng;
        static string input = "";
        private Point mouseOffset;
        private bool isMouseDown = false;

        static void runRu()
        {
            bool correct;
            bool has;
            int flag;

            for (int i = 0; i < dictionRu.Length; i++)
            {
                correct = true;
                flag = 0;
                for (int j = 0; j < dictionRu[i].Length; j++)
                {
                    has = false;
                    for (int k = 0; k < input.Length; k++)
                    {
                        if ((dictionRu[i][j] == input[k]) && (flag & (int)Math.Pow(2, k)) == 0)
                        {
                            has = true;
                            flag += (int)Math.Pow(2, k);
                            break;
                        }
                    }
                    if (!has)
                    {
                        correct = false;
                        break;
                    }
                }
                if (correct)
                {
                    if(!result.Contains(" " + dictionRu[i] + " "))
                        result += (dictionRu[i] + "    ");
                }
            }
        }

        static void runEng()
        {
            bool correct;
            bool has;
            int flag;

            for (int i = 0; i < dictionEng.Length; i++)
            {
                correct = true;
                flag = 0;
                for (int j = 0; j < dictionEng[i].Length; j++)
                {
                    has = false;
                    for (int k = 0; k < input.Length; k++)
                    {
                        if ((dictionEng[i][j] == input[k]) && (flag & (int)Math.Pow(2, k)) == 0)
                        {
                            has = true;
                            flag += (int)Math.Pow(2, k);
                            break;
                        }
                    }
                    if (!has)
                    {
                        correct = false;
                        break;
                    }
                }
                if (correct)
                {
                    if(!result.Contains(" " + dictionEng[i] + " "))
                        result += (dictionEng[i] + "    ");
                }
            }
        }

        public Form1()
        {
            char[] separat = {'\n', '\r'};
            InitializeComponent();
            System.IO.StreamReader fileRu = new System.IO.StreamReader("ru.dic", Encoding.GetEncoding(1251));
            dictionRu = fileRu.ReadToEnd().Split(separat, System.StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < dictionRu.Length; i++)
                dictionRu[i] = dictionRu[i].ToLower();
            System.IO.StreamReader fileEng = new System.IO.StreamReader("en.dic", Encoding.GetEncoding(1251));
            dictionEng = fileEng.ReadToEnd().Split(separat, System.StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < dictionEng.Length; i++)
                dictionEng[i] = dictionEng[i].ToLower();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool engFlag = false;
            bool ruFlag = false;
            bool nonFlag = false;
            string ruAlp = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
            string engAlp = "abcdefghijklmnopqrstuvwxyz";
            this.tb2.Text = "";
            result = "";
            input = this.tb1.Text.ToLower();

            if(this.tb1.Text != "")
            {
                for (int i = 0; i < input.Length; i++)
                {
                    if(ruAlp.Contains(input[i].ToString()))
                        ruFlag = true;
                    else if(engAlp.Contains(input[i].ToString()))
                        engFlag = true;
                    else 
                    {
                        nonFlag = true;
                        break;
                    }
                }

                if(ruFlag && !engFlag && !nonFlag)
                    runRu();
                else if (!ruFlag && engFlag && !nonFlag)
                    runEng();
                this.tb2.Text = result;
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            int xOffset;
            int yOffset;
            Opacity = 0.7;

            if (e.Button == MouseButtons.Left)
            {
                xOffset = -e.X;
                yOffset = -e.Y;
                mouseOffset = new Point(xOffset, yOffset);
                isMouseDown = true;
            }
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (isMouseDown)
            {
                Point mousePos = Control.MousePosition;
                mousePos.Offset(mouseOffset.X, mouseOffset.Y);
                Location = mousePos;
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                isMouseDown = false;
                Opacity = 1;
            }
        }
    }
}
