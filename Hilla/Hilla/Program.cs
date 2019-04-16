using System;

namespace Hilla
{
    class Program
    {
        static string alp = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
        static int len = alp.Length;

        static int Mod(int a, int n) // Остаток от деления
        {
            return a > 0 ? a % n : ((a % n) + n) % n;
        }

        static int NOD(int n, int m) // НОД
        {
            return n == m ? n : n > m ? NOD(n - m, m) : NOD(m - n, n);
        }

        static int Invert(int a, int n) // Обратное число по модулю
        {
            if (NOD(Mod(a, len), n) != 1) return 1;

            int result = 0;

            for (int i = 0; ; i++)
            {
                result = i * n + 1;
                if ((result % a) == 0) break;
            }
            return result / a;
        }

        static int Minor(int[,] matrix, int iEx, int jEx) // Вычисление минора
        {
            int res = 0;
            int[,] minor = new int[2, 2];
            int iI = 0;
            int jI = 0;

            for (int i = 0; i < 3; i++)
            {
                if (i == iEx) continue;
                for (int j = 0; j < 3; j++)
                {
                    if (j == jEx) continue;
                    minor[iI, jI++] = matrix[i, j];
                }
                iI++;
                jI = 0;
            }

            res = minor[0, 0] * minor[1, 1] - minor[0, 1] * minor[1, 0];
            res = ((iEx + jEx) % 2) == 0 ? res : (-1) * res;
            return res;
        }

        static int[,] ShowMinors(int[,] matrix)
        {
            if (matrix.Length != 9)
            {
                Console.WriteLine("[!] Матрица не 3х3!");
                return null;
            }
            int res = 0;
            int[,] minor = new int[2, 2];
            int[,] resultM = new int[3, 3];
            int iI = 0;
            int jI = 0;

            for (int iEx = 0; iEx < 3; iEx++)
            {
                for (int jEx = 0; jEx < 3; jEx++)
                {
                    iI = jI = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        if (i == iEx) continue;
                        for (int j = 0; j < 3; j++)
                        {
                            if (j == jEx) continue;
                            minor[iI, jI++] = matrix[i, j];
                        }
                        iI++;
                        jI = 0;
                    }
                    Console.WriteLine("\n---------\nМинор {0},{1}:", iEx+1, jEx+1);
                    ShowM(minor, 2);
                    res = minor[0, 0] * minor[1, 1] - minor[0, 1] * minor[1, 0];
                    res = ((iEx + jEx) % 2) == 0 ? res : (-1) * res;
                    resultM[jEx, iEx] = res;
                    Console.Write("Расчет: ");
                    if (((iEx + jEx) % 2) != 0)
                        Console.Write("-1*");
                    Console.WriteLine("{0}*{1}-{2}*{3}={4}, {4}mod{5}={6}", minor[0, 0], minor[1, 1], minor[0, 1], minor[1, 0], res, len, Mod(res, len));
                }
            }
            return resultM;
        }

        static int DMatrix(int[,] mx) // Вычисление определителя матрицы
        {
            if (mx.Length != 9)
            {
                Console.WriteLine("[!] Размер матрицы не 3х3, определитель установлен на 0.");
                return 0;
            }
            return mx[0, 0] * mx[1, 1] * mx[2, 2] 
                 + mx[0, 1] * mx[1, 2] * mx[2, 0] 
                 + mx[0, 2] * mx[1, 0] * mx[2, 1] 
                 - mx[0, 2] * mx[1, 1] * mx[2, 0] 
                 - mx[0, 0] * mx[1, 2] * mx[2, 1] 
                 - mx[2, 2] * mx[0, 1] * mx[1, 0];
        }

        static int[,] Transp(int[,] matrix) // Транспонирование матрицы
        {
            int[,] res = new int[3, 3];

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    res[i, j] = matrix[j, i];

            return res;
        }

        static int[,] Reverse(int[,] matrix) // Обратная матрица
        {
            int det = DMatrix(matrix);
            if (det == 0)
                return null;

            det = Invert(det, len);

            int[,] revMatr = new int[3, 3];

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    revMatr[j, i] = Mod(det*Minor(matrix, i, j), len);

            return revMatr;
        }

        static void ShowM(int[,] matrix, int diment = 3, int tr = 3) // Отобразить матрицу в консоль
        {
            for (int i = 0; i < diment; i++)
            {
                Console.Write("|");
                for (int j = 0; j < matrix.Length / diment; j++)
                    Console.Write(matrix[i, j].ToString().PadLeft(tr, ' '));
                Console.WriteLine("|");
            }
        }

        static int[,] MultM(int[,] mx1, int[,] mx2) // Умножение матриц
        {
            int n = mx1.Length / 3;
            int m = mx2.Length / 3;
            int[,] res = new int[n, m];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    res[i, j] = Mod(mx1[i, 0]*mx2[0, j] + mx1[i, 1]*mx2[1, j] + mx1[i, 2]*mx2[2, j], len);

            return res;
        }

        static int[,] ShowMultM(int[,] mx1, int[,] mx2) // Умножение матриц
        {
            int n = mx1.Length / 3;
            int m = mx2.Length / 3;
            int[,] res = new int[n, m];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    res[i, j] = Mod(mx1[i, 0] * mx2[0, j] + mx1[i, 1] * mx2[1, j] + mx1[i, 2] * mx2[2, j], len);
                    Console.WriteLine("\n{0},{1}) {2}*{3}+{4}*{5}+{6}*{7}={8}, {8}mod{9}={10}", i + 1, j + 1, mx1[i, 0], mx2[0, j], mx1[i, 1], mx2[1, j], mx1[i, 2], mx2[2, j], mx1[i, 0]*mx2[0, j]+mx1[i, 1]*mx2[1, j]+mx1[i, 2]*mx2[2, j], len, res[i,j]);
                }

            return res;
        }

        static int[,] StrToMatrix(string inp) // Из строки в матрицу
        {
            bool undef = false;
            if (inp.Length % 3 != 0)
                while (inp.Length % 3 != 0)
                    inp += alp[0];

            int[,] res = new int[3, inp.Length / 3];
            for (int j = 0; j < inp.Length / 3; j++)
                for (int i = 0; i < 3; i++)
                {
                    res[i, j] = alp.IndexOf(char.ToLower(inp[i + 3 * j]));
                    if (res[i, j] == -1) 
                        undef = true;
                }

            if (undef)
                Console.WriteLine("[!] При переводе в матрицу обнаружены неизвестные символы!\n[!] Символы, которых нет в алфавите записаны как -1.");
            return res;
        }

        static string MatrixToStr(int[,] matrix) // Из матрицы в строку
        {
            int mLen = matrix.Length / 3;
            string res = "";

            for (int j = 0; j < mLen; j++)
                for (int i = 0; i < 3; i++)
                    res += alp[matrix[i, j]];

            return res;
        }

        static void Main(string[] args) // Главная функция
        {
            string alp1 = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
            string alp2 = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
            string alp3 = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
            string alp4 = "abcdefghijklmnopqrstuvwxyz";

            while (true)
            {
                Console.Write("Шифр Хилла.\n1-Зашифровать.\n2-Расшифровать.\n3-Соответствия.\n4-Все для матрицы.\n5-Обратное по модулю.\n6-Расчет миноров.\n7-Расчет обратной матрицы\n8-Изменение алфавита.\n9-Остаток по модулю.\n10-Из матрицы в текст.\n11-Умножение матриц.\nВвод: ");
                string inp = Console.ReadLine();
                if (inp == "1")
                {
                    Console.WriteLine("\bЗашифровать.");
                    Console.Write("Введите текст: ");
                    string text = Console.ReadLine();
                    int[,] textM = StrToMatrix(text);
                x2:
                    Console.Write("Введите ключ: ");
                    string keyE = Console.ReadLine();
                    int[,] keyEM = StrToMatrix(keyE);
                    if (DMatrix(keyEM) == 0)
                    {
                        Console.WriteLine("[!] Определитель матрицы равен 0!");
                        goto x2;
                    }
                    if (NOD(Mod(DMatrix(keyEM), len), len) != 1)
                    {
                        Console.WriteLine("[!] Определитель матрицы не взаимопростой с длиной алфавита!");
                        goto x2;
                    }
                    Console.WriteLine("\n\n[1 STEP]: Начало зашифровки.");
                    int[,] resultM = MultM(keyEM, textM);
                    Console.WriteLine("<text>: {0}", text);
                    Console.WriteLine("Text: ");
                    ShowM(textM);
                    Console.WriteLine("<key>: {0}", keyE);
                    Console.WriteLine("Key: ");
                    ShowM(keyEM);
                    Console.WriteLine("<result>: {0}", MatrixToStr(resultM));
                    Console.WriteLine("Result: ");
                    ShowM(resultM);
                    Console.WriteLine("\nПолученый результат шифрования: {0}\n", MatrixToStr(resultM));
                    Console.WriteLine("\n\n[2 STEP]: Начало расшифровки.");
                    int[,] rKeyEM = Reverse(keyEM);
                    Console.WriteLine("<reverse key>: {0}", MatrixToStr(rKeyEM));
                    Console.WriteLine("Reverse key: ");
                    ShowM(rKeyEM);
                    int[,] text2 = MultM(rKeyEM, resultM);
                    Console.WriteLine("<text2>: {0}", MatrixToStr(text2));
                    Console.WriteLine("Text2: ");
                    ShowM(rKeyEM);
                    Console.WriteLine("\nПолученый результат расшифрования: {0}\n", MatrixToStr(text2));
                }
                else if (inp == "2")
                {
                    Console.WriteLine("\bРасшифровать.");
                    Console.Write("Введите 3 триграммы шифротекста: ");
                    string y = Console.ReadLine();
                    int[,] yM = StrToMatrix(y);
                    Console.Write("Введите 3 триграммы текста: ");
                    string x = Console.ReadLine();
                    int[,] xM = StrToMatrix(x);
                    Console.WriteLine("\n\n[1 STEP]: Нахождение ключа.");
                    Console.WriteLine("<y>: {0}", y);
                    Console.WriteLine("Y: ");
                    ShowM(yM);
                    Console.WriteLine("<x>: {0}", x);
                    Console.WriteLine("X: ");
                    ShowM(xM);
                    int[,] keyM = MultM(yM, Reverse(xM));
                    Console.WriteLine("<key>: {0}", MatrixToStr(keyM));
                    Console.WriteLine("Key: ");
                    ShowM(keyM);
                    Console.WriteLine("\nПолученый ключ: {0}\n", MatrixToStr(keyM));
                    Console.WriteLine("\n\n[2 STEP]: Расшифровка заданного текста.");
                    Console.Write("Введите шифротекст: ");
                    string code = Console.ReadLine();
                    int[,] codeM = StrToMatrix(code);
                    Console.WriteLine("<code>: {0}", code);
                    Console.WriteLine("Code: ");
                    ShowM(codeM);
                    int[,] rKeyM = Reverse(keyM);
                    Console.WriteLine("<reverse key>: {0}", MatrixToStr(rKeyM));
                    Console.WriteLine("Reverse key: ");
                    ShowM(rKeyM);
                    int[,] finalM = MultM(rKeyM, codeM);
                    Console.WriteLine("<final>: {0}", MatrixToStr(finalM));
                    Console.WriteLine("Final: ");
                    ShowM(finalM);
                    Console.WriteLine("\nПолученый результат расшифрования: {0}\n", MatrixToStr(finalM));
                }
                else if (inp == "3")
                {
                    for (int i = 0; i < len; i++)
                        Console.WriteLine(i + " - " + alp[i]);
                }
                else if (inp == "4")
                {
                    Console.Write("Введите текст: ");
                    string text = Console.ReadLine();
                    int[,] textM = StrToMatrix(text);
                    ShowM(textM);
                    int determ = DMatrix(textM);
                    Console.WriteLine("Определитель матрицы: {0}", determ);
                    Console.WriteLine("Обратная матрица:");
                    if (determ == 0)
                        Console.WriteLine("[!] Определитель матрицы равен 0!");
                    else if (NOD(Mod(determ, len), len) != 1)
                        Console.WriteLine("[!] Определитель матрицы не взаимопростой с длиной алфавита!");
                    else
                        ShowM(Reverse(textM));

                }
                else if (inp == "5")
                {
                    int numb;
                    Console.Write("Введите число: ");
                    if (int.TryParse(Console.ReadLine(), out numb))
                    {
                        if(NOD(Mod(numb, len), len) == 1)
                            Console.WriteLine("Обратное по модулю ({1}): {0}", Invert(Mod(numb, len), len), len);
                        else
                            Console.WriteLine("[!] Число ({0}) не взаимнопростое с модулем ({1})!", numb, len);
                    }
                    else
                        Console.WriteLine("[!] Нужно вводить число!");
                }
                else if (inp == "6")
                {
                    Console.Write("Введите текст: ");
                    string text = Console.ReadLine();
                    int[,] textM = StrToMatrix(text);
                    ShowM(textM);
                    int determ = DMatrix(textM);
                    Console.WriteLine("\nОпределитель матрицы: {0}", determ);
                    Console.WriteLine("\nМиноры:");
                    ShowMinors(textM);
                }
                else if (inp == "7")
                {
                    Console.Write("Введите текст: ");
                    string text = Console.ReadLine();
                    int[,] textM = StrToMatrix(text);
                    ShowM(textM);
                    int determ = DMatrix(textM);
                    Console.WriteLine("\nОпределитель матрицы: {0}, {0}mod{1}={2}", determ, len, Mod(determ, len));
                    Console.WriteLine("\nМиноры:");
                    int[,] minsM = ShowMinors(textM);
                    Console.WriteLine("\nМатрица:");
                    ShowM(minsM, 3, 6);
                    if (determ == 0)
                        Console.WriteLine("[!] Определитель матрицы равен 0!");
                    else if (NOD(Mod(determ, len), len) != 1)
                        Console.WriteLine("[!] Определитель матрицы не взаимопростой с длиной алфавита!");
                    else
                    {
                        int invDet = Invert(determ, len);
                        Console.WriteLine("\nОпределитель: {0}, {0}mod{1}={2} {2}^-1={3}", determ, len, Mod(determ, len),  invDet);
                        Console.WriteLine("Размер алфавита: {0}", len);
                        Console.WriteLine("\nРасчет:");
                        int temp;
                        
                        for (int i = 0; i < 3; i++)
                            for (int j = 0; j < 3; j++)
                            {
                                temp = minsM[i,j]*invDet;
                                Console.WriteLine("\n{0},{1}) {2}*{3}={4}, {4}mod{5}={6}", i+1, j+1, minsM[i,j], invDet, temp, len, Mod(temp, len));
                            }
                        Console.WriteLine("\nФинальная матрица:");
                        ShowM(Reverse(textM));
                    }
                }
                else if (inp == "8")
                {
                    Console.WriteLine("\nВыбор алфавита:\n");
                    Console.WriteLine("1-{0}\nДлина: {1}\n", alp1, alp1.Length);
                    Console.WriteLine("2-{0}\nДлина: {1}\n", alp2, alp2.Length);
                    Console.WriteLine("3-{0}\nДлина: {1}\n", alp3, alp3.Length);
                    Console.WriteLine("4-{0}\nДлина: {1}\n", alp4, alp4.Length);
                    Console.WriteLine("Ввод: ");
                    string answ = Console.ReadLine();
                    switch (answ)
                    {
                        case "1":
                            alp = alp1;
                            len = alp.Length;
                            Console.WriteLine("Успешно изменено.");
                            break;
                        case "2":
                            alp = alp2;
                            len = alp.Length;
                            Console.WriteLine("Успешно изменено.");
                            break;
                        case "3":
                            alp = alp3;
                            len = alp.Length;
                            Console.WriteLine("Успешно изменено.");
                            break;
                        case "4":
                            alp = alp4;
                            len = alp.Length;
                            Console.WriteLine("Успешно изменено.");
                            break;
                        default:
                            Console.WriteLine("[!] Индекс не найден!");
                            break;
                    }
                }
                else if (inp == "9")
                {
                    int a;
                    int n;
                    Console.Write("Введите число: ");
                    if (int.TryParse(Console.ReadLine(), out a))
                    {
                        Console.Write("Введите модуль: ");
                        if (int.TryParse(Console.ReadLine(), out n))
                        {
                            Console.WriteLine("\n{0}mod{1}={2}\n", a, n, Mod(a, n));
                        }
                        else
                            Console.WriteLine("[!] Нужно вводить число!");
                    }
                    else
                        Console.WriteLine("[!] Нужно вводить число!");
                }
                else if (inp == "10")
                {
                    int[,] matx = new int[3, 3];
                    Console.WriteLine("Введите матрицу:");
                    for(int i = 0; i < 3; i++)
                        for(int j = 0; j < 3; j++)
                        {
                            Console.Write("{0},{1}) ", i+1, j+1);
                            matx[i,j] = int.Parse(Console.ReadLine());
                        }
                    Console.WriteLine("\nТекст из матрицы: {0}", MatrixToStr(matx));
                }
                else if (inp == "11")
                {
                    Console.WriteLine("Умножение матриц.");
                    Console.Write("Введите текст матрицы1: ");
                    string text1 = Console.ReadLine();
                    Console.Write("Введите текст матрицы2: ");
                    string text2 = Console.ReadLine();
                    int[,] mtrx1 = StrToMatrix(text1);
                    int[,] mtrx2 = StrToMatrix(text2);
                    Console.WriteLine("Матрица1: ");
                    ShowM(mtrx1);
                    Console.WriteLine("Матрица2: ");
                    ShowM(mtrx2);
                    Console.WriteLine("Действия: ");
                    int[,] resM = ShowMultM(mtrx1, mtrx2);
                    Console.WriteLine("Финальная матрица: ");
                    ShowM(resM);
                }
                else
                    Console.WriteLine("[!] Неизвестная команда!");

                Console.WriteLine("Нажмите enter для продолжения...");
                Console.ReadLine();
                Console.Clear();
            }
        }
    }
}