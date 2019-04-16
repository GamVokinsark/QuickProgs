using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Biometric_Pin_Code
{
    public partial class Form1 : Form
    {
        private int[] bits = new int[16];
        private int[, ,] mass = { {/*k1*/ { 2,  3,  5,  4,  6,  7,  8},
                                         {10, 11, 13, 12, 14, 15, 16} },
                                 {/*k2*/ { 2,  3,  9,  4, 10, 11, 12}, 
                                         { 6,  7, 13,  8, 14, 15, 16} },
                                 {/*k3*/ { 2,  5,  9,  6, 10, 13, 14}, 
                                         { 4,  7, 11,  8, 12, 15, 16} },
                                 {/*k4*/ { 3,  5,  9,  7, 11, 13, 15},
                                         { 4,  6, 10,  8, 12, 14, 16} }};
        private int[] kMass = { 0, 0, 0, 0, 0 };
        private string tempRunStr = "";

        private void relK(int curKi)
        {
            if (curKi >= 4)
            {
                int temK0 = 0;
                int temK1 = 0;
                int[] tempMass = { 2, 3, 5, 9 };

                tempRunStr += "Для k5 значения: ";
                for (int i = 0; i < 4; i++)
                {
                    if ((bits[tempMass[i] - 1] ^ kMass[3 - i]) == 1)
                    {
                        tempRunStr += "1";
                        temK1++;
                    }
                    else
                    {
                        tempRunStr += "0";
                        temK0++;
                    }
                }
                kMass[4] = temK1 > temK0 ? 1 : 0;
                tempRunStr += " -> " + kMass[4];
                return;
            }

            int tempK0 = 0;
            int tempK1 = 0;

            tempRunStr += "\nДля k" + (curKi + 1) + " значения: ";
            for (int i = 0; i < 7; i++)
            {
                if ((bits[mass[curKi, 0, i] - 1] ^ bits[mass[curKi, 1, i] - 1]) == 1)
                {
                    tempRunStr += "1";
                    tempK1++;
                }
                else
                {
                    tempRunStr += "0";
                    tempK0++;
                }
            }

            kMass[curKi] = tempK1 > tempK0 ? 1 : 0;
            tempRunStr += " -> " + kMass[curKi] + Environment.NewLine;
            return;
        }

        private void calc(int k)
        {
            for (int i = 0; i < 16; i++)
            {
                bits[i] = (((i & 0x8) / 0x8) & ((k & 0x10) / 0x10))
                          ^ (((i & 0x4) / 0x4) & ((k & 0x8) / 0x8))
                          ^ (((i & 0x2) / 0x2) & ((k & 0x4) / 0x4))
                          ^ (((i & 0x1) / 0x1) & ((k & 0x2) / 0x2))
                          ^ ((k & 0x1) / 0x1);
            }
        }

        private int[] parse(string inp)
        {
            if (inp.Length < 16)
                inp = "0000000000000000";
            int[] result = new int[16];
            for (int i = 0; i < 16; i++)
                result[i] = char.IsDigit(inp[i]) ? int.Parse(inp[i].ToString()) : 0;
            return result;
        }

        private int[] sumMod2(int[] a, int[] b)
        {
            int[] result = new int[16];

            for (int i = 0; i < 16; i++)
                result[i] = a[i] ^ b[i];

            return result;
        }

        private string massToString(int[] a)
        {
            string result = "";

            for (int i = 0; i < a.Length; i++)
                result += a[i];

            return result;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            tempRunStr = "";

            int[] c = parse(inpC.Text);
            int[] b = parse(inpB.Text);
            bits = sumMod2(c, b);
            inpS.Text = massToString(bits);

            for (int i = 0; i < 5; i++)
                relK(i);

            inpK.Text = massToString(kMass);
            tempTxt.Text = tempRunStr;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            inpB.Text = "";
            inpC.Text = "";
            inpK.Text = "";
            inpS.Text = "";
            tempTxt.Text = "";
        }
    }
}
