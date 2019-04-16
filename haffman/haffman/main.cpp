#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
FILE *p;
struct LtCode
{
    unsigned long long frequency;
    unsigned char letter;
    string code;
};
 
void zeroset(LtCode *c)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        c[i].frequency = 0;
        c[i].letter = i;
		c[i].code="";
    }
}
 
bool fSort(LtCode x, LtCode y)
{
	return x.frequency != y.frequency? x.frequency > y.frequency: x.letter > y.letter;
}
 
struct B
{
    string list;
    int i;
    int left;
    int right;
    string code;
    B()
    {
        list="";
		code="";
        i = 0;
		left=-1;
		right=-1;
    }
};
 
void huffmanEncodingIn(int num, string code, vector <B> &tree, LtCode *letter_codes)
{
    tree[num].code = code;
    if (tree[num].list.size() > 1)
    {
		huffmanEncodingIn(tree[num].right, code+"1", tree, letter_codes);
        huffmanEncodingIn(tree[num].left, code+"0", tree, letter_codes);
    }
    else
    {
        for (int j = 0; ; ++j)
        {
            if (letter_codes[j].letter == tree[num].list[0])
            {
                letter_codes[j].code = code;
                break;
            }
        }
    }
}
 
void huffmanEncoding(vector <B> &sorted_tree, LtCode *letter_codes)
{
    huffmanEncodingIn(sorted_tree.size()-1, "", sorted_tree, letter_codes);
}

char translateHuffman(string in, string &out, vector<B> tree, int &i, int j)
{
	int cur=j;
	while(true)
	{
		if(in[i]=='0') {if(tree[cur].left==-1) return tree[cur].list[0]; else cur=tree[cur].left;}
		else if(in[i]=='1') {if(tree[cur].right==-1) return tree[cur].list[0]; else cur=tree[cur].right;}
		i++;
		if(i==in.size()) return tree[cur].list[0];
	}
}

int main() 
{
	setlocale(LC_CTYPE, "rus");
    unsigned char c;
    string S, sHC, sOD;
    LtCode count[256], stringlinks[256];
    zeroset(count);
	cout << "Введите строку:\n";
    while (scanf("%c", &c))
    {
        if(c=='\n') break;
        S+=c;
        count[c].frequency++;
    }
	/*p=fopen("text.txt", "r");
	while(c=fgetc(p), c!='\n')
	{
		S+=c;
        count[c].frequency++;
	}
	cout << S;
	*/
    sort(count, count+256, fSort);
    
    vector <B> tree;
    B tmp;
    tmp.list = "0";
    int j, letter_amount;
    for (j = 0; (count[j].frequency); j++)
    {
        tmp.i = count[j].frequency;
        tmp.list[0] = count[j].letter;
        tree.push_back(tmp);
    }
    int maxsize=j, size=0, head;
    
    sort(tree.begin(), tree.end(), [] (B a, B b) {return a.i != b.i? a.i<b.i: a.list.size()<b.list.size();});
    j=0;
	if(maxsize==1) 
	{
		tmp.list=tree[j].list+"!";
		tmp.left=0;
		tmp.right=0;
		tmp.i=tree[j].i;
		tree.push_back(tmp);
	}
    while(size<maxsize)
    {
        tmp.list=tree[j].list+tree[j+1].list;
        tmp.i=tree[j].i+tree[j+1].i;
        tmp.left=j;
        tmp.right=j+1;
        size=tmp.list.size();
        tree.push_back(tmp);
        j+=2;
        sort(tree.begin()+j, tree.end(), [] (B a, B b) {return a.i != b.i? a.i<b.i: a.list.size()<b.list.size();});
    }
	head=j;
    huffmanEncoding(tree, count);
    cout << "\n\nКоды символов:\n";
    for (j = 0; (count[j].frequency); j++)
    {
        cout << '\'' << count[j].letter << "\'(" << count[j].code << ")  ";
        stringlinks[count[j].letter].code = count[j].code;
    }
    cout << "\n\nСтрока в кодах Хаффмана:\n";
    for(unsigned int i = 0; i < S.size(); ++i)
		sHC+=stringlinks[S[i]].code;
	cout << sHC << '\n';
	for(int i=0; i<sHC.size();)
		sOD+=translateHuffman(sHC, sOD, tree, i, head);
	cout << "\n\nСтрока, считанная с кодов Хаффмана:\n";
	cout << sOD << '\n';
	system("pause");
    return 0;
}