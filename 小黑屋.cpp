#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
using namespace std;
struct thing
{
    string type;
    string name;
    int attack;
    int defense;
    int health;
    int num;
    bool disposable;
    int sharp;
    int durability;
};
struct w
{
    string name;
    string b[100];
    int bnum;
};
int health = 1000, maxhealth = 1000, defense = 10, attack = 100;
int capacity = 0;
string name;
int nowway = 0, water = 0, maxwater = 10;
int bagi = 1, protectlevel;
string protect;
string canmakething[1000] = { "�˳�","ľ��","ľ��","ľ��","����̨" };
int canmakethingi = 5;
string f[100] = {
    {"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"},
    {"+..................................................................................................+"},
    {"+..................................................................................................+"},
    {"+.........+............................................K...........................................+"},
    {"+.......FV+........................................................................................+"},
    {"+...................F..........T...................................................................+"},
    {"+........+................+.............+.............V.......................CF...................+"},
    {"+.......+..........................................................................................+"},
    {"+.............................................................+.H.+..............B.................+"},
    {"+......F.......+.......+............V............................+.................................+"},
    {"+...............V....+...............................................................Y.............+"},
    {"+....................F+.......+++............++....................................................+"},
    {"+.............................+C+.......o....I+.....o...................S..........F...............+"},
    {"+..........................................+++.....................................................+"},
    {"+.............................+.........................V..........................................+"},
    {"+.........Y...........H......+..........o.......+..A...........+...................................+"},
    {"+...........................+..................o+............++....G..............YV...............+"},
    {"+.....................................................+......+.I...................................+"},
    {"+......................+++.......................+++..........+....................................+"},
    {"+.....................+..U+......................V........+....+.............Y.....................+"},
    {"+.......H...........++...++........................................................................+"},
    {"+.......................+Y................++...................M...................................+"},
    {"+......................................+...G+...........T..........................................+"},
    {"+...H..............W............................................................Y..................+"},
    {"+..................................................................................................+"},
    {"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"},
};
bool isf[100][100];
int movex[4] = { 0,-1,0,1 };
int movey[4] = { -1,0,1,0 };

//H�޿� I���� Cú�� G��� oС�� Y���� V��Ѩ S�ɴ� Fս�� M���� T�ѿ� Pǰ�� B��ǿ� K���»���
int Outpostx[100], opxi = 0;
int Outposty[100], opyi = 0;
w way[100] = {
    {"����",{"����ɭ��","����","״̬","װ��","����"}, 5},
    {"����&����",{"�����䷽"},1}
};
int waynum = 2;
bool isw[100] = { true, false, false };
bool isb[100] = { true, false, false };
thing nowaxe, nowpickaxe, nowweapon, nowhoe;
thing bag[1000] = {
    {"�˳�","�˳�",0,0,0,0,false},
};
string outbutton()
{
    char c;
    int now = 0;
    for (int i = 0; i < 100; i++)
    {
        if (isb[i] == true)
        {
            now = i;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; way[i].name != ""; i++)
        {
            if (isw[i] == true)
            {
                cout << "*" << way[i].name << "*";
            }
            else
            {
                cout << " " << way[i].name << " ";
            }
        }
        cout << endl;
        for (int i = 0; way[nowway].b[i] != ""; i++)
        {
            if (isb[i] == true)
            {
                cout << ">" << way[nowway].b[i] << "<" << endl;
            }
            else
            {
                cout << " " << way[nowway].b[i] << " " << endl;
            }
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isb[now] = false;
            isb[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && way[nowway].b[now + 1] != "")
        {
            isb[now] = false;
            isb[now + 1] = true;
            now += 1;
        }
        if (c == 'a' && nowway > 0)
        {
            isw[nowway] = false;
            isw[nowway - 1] = true;
            nowway -= 1;
            isb[now] = false;
            isb[0] = true;
        }
        if (c == 'd' && way[nowway + 1].name != "")
        {
            isw[nowway] = false;
            isw[nowway + 1] = true;
            nowway += 1;
            isb[now] = false;
            isb[0] = true;
        }
        if (c == 32)
        {
            return way[nowway].b[now];
        }
    }
    return "";
}
string outbag()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    while (1)
    {
        system("cls");
        for (int i = 0; bag[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag[i].name << "<";
            }
            else
            {
                cout << " " << bag[i].name << " ";
            }
            for (int j = 0; j < 20 - bag[i].name.size() - to_string(bag[i].num).size(); j++)
            {
                cout << " ";
            }
            cout << bag[i].num << "    " << bag[i].durability << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            return bag[now].name;
        }
    }
    return 0;
}
bool skills[10];//������ ��ʳ�� �� �ռ��� Ұ���� սʿ ������ ҽ�� ����   ԭ������������һ�������ݵ����� 
int fight(string hn, int hmh, int ha, int hd, int hh)
{
    while (1)
    {
        if (nowweapon.type == "��") cout << "1,����";
        else if (nowweapon.type == "��") cout << "1,����";
        else if (nowweapon.type == "��ǹ") cout << "1,ɨ��";
        else if (nowweapon.type == "��ǹ") cout << "1,���";
        else if (nowweapon.type == "") cout << "1,ȭ��";
        bool is1 = false, is2 = false, is3 = false;
        int i1, i2, i3;
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "����" && bag[i].num != 0)
            {
                cout << " 2,����[" << bag[i].num << "]";
                is1 = true;
                i1 = i;
                break;
            }
        }
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "��ì" && bag[i].num != 0)
            {
                cout << " 3,Ͷ��[" << bag[i].num << "]";
                is2 = true;
                i2 = i;
                break;
            }
        }
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "Ѭ��" && bag[i].num != 0)
            {
                cout << " 4,����[" << bag[i].num << "]";
                is3 = true;
                i3 = i;
                break;
            }
        }
        if (skills[7])
        {
            cout << "5,ҽ��";
        }
        string which;
        cin >> which;
        int bullet = 0, missile = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (bag[i].name == "�ӵ�")
            {
                bullet = bag[i].num;
            }
            if (bag[i].name == "����")
            {
                missile = bag[i].num;
            }
            else if (bag[i].name == "")
            {
                break;
            }
        }
        if (which == "1")
        {
            if (nowweapon.type == "��" || nowweapon.type == "��" || nowweapon.type == "")
            {
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "] @       E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]  @      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]   @     E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]    @    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]     @   E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]      @  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]       @ E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]        @E[" << hh << "/" << hmh << "]";
                if (skills[5]) hh -= (attack + nowweapon.attack) * 2 - hd;
                else hh -= attack + nowweapon.attack - hd;
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]      @  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]    @    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]  @      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            }
            else if (nowweapon.name == "���ⲽǹ" || bullet > 0 || (nowweapon.name == "���Ͳ" && missile > 0))
            {
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@o       E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@ o      E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@  o     E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@   o    E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@    o   E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@     o  E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@      o E[" << hh << "/" << hmh << "]";
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@       oE[" << hh << "/" << hmh << "]";
                if (skills[5]) hh -= (attack + nowweapon.attack) * 2 - hd;
                else hh -= attack + nowweapon.attack - hd;
                Sleep(10);
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            }
            else if (bullet <= 0 || (nowweapon.name == "���Ͳ" && missile <= 0))
            {
                MessageBox(0, TEXT("û��ҩ��..."), TEXT("��Ҫ��ʾ"), MB_OK);
            }
        }
        else if (which == "2" && is1)
        {
            hh -= 500;
            system("cls");
            cout << "�飡";
            Sleep(1000);
            system("cls");
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            bag[i1].num--;
        }
        else if (which == "3" && is2)
        {
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@>       E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@->      E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@ ->     E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@  ->    E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@   ->   E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@    ->  E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@     -> E[" << hh << "/" << hmh << "]";
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@      ->E[" << hh << "/" << hmh << "]";
            hh -= 200 - hd;
            Sleep(10);
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
            bag[i2].num--;
        }
        else if (which == "4" && is3)
        {
            if (skills[2])
            {
                cout << "����+1000";
                health += 1000;
                if (health > maxhealth)
                {
                    health = maxhealth;
                }
            }
            else
            {
                cout << "����+500";
                health += 500;
                if (health > maxhealth)
                {
                    health = maxhealth;
                }
            }
            bag[is3].num--;
        }
        else if (which == "5" && skills[7])
        {
            cout << "����+1500";
            health += 1500;
            if (health > maxhealth)
            {
                health = maxhealth;
            }
        }
        if (hh <= 0)
        {
            cout << "�Է�����";
            Sleep(1000);
            return 1;
        }
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@       E [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@      E  [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@     E   [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@    E    [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@   E     [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@  E      [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@ E       [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@E        [" << hh << "/" << hmh << "]";
        if (skills[8])
        {
            if (rand() % 3 == 2) health -= ha + -defense;
        }
        else if (rand() % 2) health -= ha + -defense;
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@  E      [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@    E    [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@      E  [" << hh << "/" << hmh << "]";
        Sleep(10);
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "[" << health << "/" << maxhealth << "]@        E[" << hh << "/" << hmh << "]";
        Sleep(1000);
        cout << endl;
        if (health <= 0)
        {
            cout << "������";
            Sleep(1000);
            return 0;
        }
    }
    return 0;
}
void slowly(const char* p)
{
    while (1)
    {
        if (*p != 0)
        {
            printf("%c", *p++);
        }
        else
        {
            break;
        }
        Sleep(30);
    }
}
int welcome()
{
    cout << "Ұ������1.1.0 (��֧�ִ浵)" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "         ��ҳ����������...   " << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    _getch();
    return 0;
}
int start()
{
    system("cls");
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    slowly("һ�죬�����ŷɻ���������ȥ����...");
    Sleep(1000);
    system("cls");
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    slowly("һ�߿��ŵ�Ӱ��һ�ߺ�������");
    Sleep(1000);
    system("cls");
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    slowly("ͻȻ���ɻ���ʼ����������������ˤ���˵��ϣ�����һ��");
    Sleep(1000);
    system("cls");
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    slowly("һ���Ӻ󣬷ɻ���ʼ����׹��");
    Sleep(1000);
    system("cls");
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    cout << "��������������������������������������������������������" << endl;
    slowly("������ϵ���������������������㣬����ǰһ�ڣ����˹�ȥ...");
    Sleep(1000);
    system("cls");
    Sleep(3000);
    slowly("�������㷢��������һ�������ߣ�����ʯͷ��");
    _getch();
    return 0;
}
bool isinto = false;
int town(int y, int x)
{
    system("cls");
    cout << " ___С��_______" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)         |" << endl;
    cout << "|______________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "һ���������ô󵶣���������ڴ�" << endl;
        _getch();
        if (!fight("����", 1000, 100, 10, 1000))
        {
            system("cls");
            slowly("��ǰ������������ɢ...");
            Sleep(1000);
            return 0;
        }
        system("cls");
        int xunrou = rand() % 3, changmao = rand() % 2, rou = rand() % 5;
        cout << "���䣺" << endl;
        cout << "1,Ѭ��*" << xunrou << endl;
        cout << "2,��*" << rou << endl;
        cout << "3,��ì*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "Ѭ��")
            {
                bag[j].num += xunrou;
                break;
            }
            if (bag[j].name == "" && xunrou != 0)
            {
                bag[j] = { "ʳ��","Ѭ��",0,0,0,xunrou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "" && rou != 0)
            {
                bag[j] = { "ʳ��","��",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��ì")
            {
                bag[j].num += changmao;
                break;
            }
            if (bag[j].name == "" && changmao != 0)
            {
                bag[j] = { "����","��ì",0,0,0,changmao,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        cout << "��һ�����������ų�ì�����˹���" << endl;
        _getch();
        if (!fight("����", 1000, 100, 10, 1000))
        {
            system("cls");
            slowly("��ǰ������������ɢ...");
            Sleep(1000);
            return 0;
        }
        int pimao = rand() % 3, buliao = rand() % 5;
        rou = rand() % 5;
        cout << "���䣺" << endl;
        cout << "1,Ƥë*" << pimao << endl;
        cout << "2,��*" << rou << endl;
        cout << "3,����*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "Ƥë")
            {
                bag[j].num += pimao;
                break;
            }
            if (bag[j].name == "" && pimao != 0)
            {
                bag[j] = { "��Ʒ","Ƥë",0,0,0,pimao,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "" && rou != 0)
            {
                bag[j] = { "ʳ��","��",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "����")
            {
                bag[j].num += buliao;
                break;
            }
            if (bag[j].name == "" && buliao != 0)
            {
                bag[j] = { "��Ʒ","����",0,0,0,buliao,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        cout << "����������" << endl;
        _getch();
        pimao = rand() % 3; buliao = rand() % 5; rou = rand() % 5;
        cout << "��ã�" << endl;
        cout << "1,Ƥë*" << pimao << endl;
        cout << "2,��*" << rou << endl;
        cout << "3,����*" << changmao << endl;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "Ƥë")
            {
                bag[j].num += pimao;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "��Ʒ","Ƥë",0,0,0,pimao,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��")
            {
                bag[j].num += rou;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "ʳ��","��",0,0,0,rou,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "����")
            {
                bag[j].num += buliao;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = { "��Ʒ","����",0,0,0,buliao,false,0 };
                break;
            }
        }
        _getch();
        slowly("���뿪��С��...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
        return 1;
    }
    else if (c != 'n')
    {
        town(y, x);
    }
    return 1;
}
int hole(int y, int x)
{
    system("cls");
    cout << " __�޿�_______" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)         |" << endl;
    cout << "|______________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "�����˾�����ǹ..." << endl;
        _getch();
        fight("������", 10000, 1000, 100, 10000);
        int waixinghejin = rand() % 3 + 1, taihejin = rand() % 5 + 1, jiguangbuqiang = rand() % 3 + 1;
        cout << "���䣺" << endl;
        cout << "1,���ǺϽ�*" << waixinghejin << endl;
        cout << "2,�ѺϽ�*" << taihejin << endl;
        cout << "3,���ⲽǹ*" << jiguangbuqiang << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "���ǺϽ�")
            {
                isfind = true;
                bag[j].num += waixinghejin;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","���ǺϽ�",0,0,0,waixinghejin,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "�ѺϽ�")
            {
                isfind = true;
                bag[j].num += taihejin;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","�ѺϽ�",0,0,0,taihejin,false,0 };
                break;
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "���ⲽǹ")
            {
                isfind = true;
                bag[j].num += jiguangbuqiang;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","���ⲽǹ",0,0,0,jiguangbuqiang,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        slowly("���뿪�˾޿�...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        hole(y, x);
    }
    return 0;
}
int iron(int y, int x)
{
    system("cls");
    cout << " ___����_______" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "Ұ����Ϯ..." << endl;
        _getch();
        fight("Ұ��", 5000, 500, 50, 5000);
        int tie = rand() % 3 + 1;
        cout << "���䣺" << endl;
        cout << "1,��*" << tie << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��")
            {
                isfind = true;
                bag[j].num += tie;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","��",0,0,0,tie,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "�ڿ�֮·")
            {
                way[i].b[way[i].bnum++] = "������";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "�ڿ�֮·",{"������"},1 };
                break;
            }
        }
        slowly("���뿪������...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        iron(y, x);
    }
    return 0;
}
int coal(int y, int x)
{
    system("cls");
    cout << " ___ú��_______" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "Ұ����Ϯ..." << endl;
        _getch();
        fight("Ұ��", 7000, 300, 100, 7000);
        int mei = rand() % 3 + 1;
        cout << "���䣺" << endl;
        cout << "1,ú*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "ú")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","ú",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "�ڿ�֮·")
            {
                way[i].b[way[i].bnum++] = "��ú��";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "�ڿ�֮·",{"��ú��"},1 };
                break;
            }
        }
        slowly("���뿪��ú��...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int gold(int y, int x)
{
    system("cls");
    cout << " ___���_______" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "Ұ����Ϯ..." << endl;
        _getch();
        fight("Ұ��", 10000, 500, 70, 10000);
        int mei = rand() % 3 + 1;
        cout << "���䣺" << endl;
        cout << "1,��*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "��")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","��",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "�ڿ�֮·")
            {
                way[i].b[way[i].bnum++] = "�ڽ��";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "�ڿ�֮·",{"�ڽ��"},1 };
                break;
            }
        }
        slowly("���뿪�˽��...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int brenstone(int y, int x)
{
    system("cls");
    cout << " ___��ǿ�_____" << endl;
    cout << "|�Ƿ����      |" << endl;
    cout << "|(y/n)        |" << endl;
    cout << "|_____________|" << endl;
    char c;
    cin >> c;
    if (c == 'y')
    {
        system("cls");
        cout << "Ұ����Ϯ..." << endl;
        _getch();
        fight("Ұ��", 10000, 800, 10, 10000);
        int mei = rand() % 3 + 1;
        cout << "���䣺" << endl;
        cout << "1,���*" << mei << endl;
        bool isfind = false;
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == "���")
            {
                isfind = true;
                bag[j].num += mei;
                break;
            }
            if (bag[j].name == "" && !isfind)
            {
                bag[j] = { "����","���",0,0,0,mei,false,0 };
                break;
            }
        }
        _getch();
        system("cls");
        for (int i = 0; i < 100; i++)
        {
            if (way[i].name == "�ڿ�֮·")
            {
                way[i].b[way[i].bnum++] = "����ǿ�";
                break;
            }
            if (way[i].name == "")
            {
                way[waynum++] = { "�ڿ�֮·",{"����ǿ�"},1 };
                break;
            }
        }
        slowly("���뿪�˽��...");
        f[y][x] = 'P';
        Outpostx[opxi++] = x;
        Outposty[opyi++] = y;
    }
    else if (c != 'n')
    {
        coal(y, x);
    }
    return 0;
}
int forest()
{
    int x = 51, y = 14;
    char c;
    for (int i = 0; i < opxi; i++) f[Outposty[i]][Outpostx[i]] = 'P';
    while (1)
    {
        system("cls");
        cout << "ˮ:" << water << "/" << maxwater << endl;
        f[y][x] = '@';
        if (skills[0])
        {
            isf[y + 3][x] = true;
            isf[y + 2][x + 1] = true; isf[y + 2][x] = true;     isf[y + 2][x - 1] = true;
            isf[y + 1][x + 2] = true; isf[y + 1][x + 1] = true; isf[y + 1][x] = true;     isf[y + 1][x - 1] = true; isf[y + 1][x - 2] = true;
            isf[y][x + 3] = true;     isf[y][x + 2] = true;     isf[y][x + 1] = true; isf[y][x] = true;     isf[y][x - 1] = true; isf[y][x - 2] = true; isf[y][x - 3] = true;
            isf[y - 1][x + 2] = true; isf[y - 1][x + 1] = true; isf[y - 1][x] = true;     isf[y - 1][x - 1] = true; isf[y - 1][x - 2] = true;
            isf[y - 2][x + 1] = true; isf[y - 2][x] = true;     isf[y - 2][x - 1] = true;
            isf[y - 3][x] = true;
        }
        else
        {
            isf[y + 2][x] = true;
            isf[y + 1][x + 1] = true; isf[y + 1][x] = true; isf[y + 1][x - 1] = true;
            isf[y][x + 2] = true;     isf[y][x + 1] = true; isf[y][x]; isf[y][x] = true; isf[y][x - 1] = true; isf[y][x - 2] = true;
            isf[y - 1][x + 1] = true; isf[y - 1][x] = true; isf[y - 1][x - 1] = true;
            isf[y - 2][x] = true;
        }
        for (int i = y - 20; i < y + 20; i++)
        {
            if (i < 0 || i > 25)
            {
                continue;
            }
            for (int j = x - 20; j < x + 20; j++)
            {
                if (j >= 0 && j <= 100)
                {
                    if (isf[i][j])
                    {
                        cout << f[i][j];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        c = _getch();
        water--;
        if (water == 0) MessageBox(0, TEXT("ˮ������"), TEXT("��Ҫ��ʾ"), MB_OK);
        if (water == -1) MessageBox(0, TEXT("��о��ڸ�����"), TEXT("��Ҫ��ʾ"), MB_OK);
        if (water == -2)
        {
            MessageBox(0, TEXT("�㵹��ɭ����..."), TEXT("��Ҫ��ʾ"), MB_OK);
            system("cls");
            slowly("��ǰ������������ɢ...");
            Sleep(1000);
            f[y][x] = '.';
            return 0;
        }
        int move = 4;
        if (c == 'w')move = 0;
        if (c == 'a')move = 1;
        if (c == 's')move = 2;
        if (c == 'd')move = 3;
        if (move == 4)
        {
            continue;
        }
        if (f[y + movey[move]][x + movex[move]] == 'o')
        {
            if (!town(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'H')
        {
            if (!hole(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'I')
        {
            if (!iron(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'C')
        {
            if (!coal(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'G')
        {
            if (!gold(y + movey[move], x + movex[move]))
            {
                f[y][x] = '.';
                return 0;
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'P')
        {
            f[y + movey[move]][x + movex[move]] = '@';
            f[y][x] = '.';
            y += movey[move];
            x += movex[move];
            MessageBox(0, TEXT("ˮ�������"), TEXT("ǰ������"), MB_OK);
            water = maxwater;
            MessageBox(0, TEXT("Ѭ��+7"), TEXT("ǰ������"), MB_OK);
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "Ѭ��")
                {
                    bag[j].num += 7;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "ʳ��","Ѭ��",0,0,0,7,false,0 };
                    break;
                }
            }
        }
        else if (f[y + movey[move]][x + movex[move]] == 'U')
        {
            slowly("��������һ����ׯ����ʱ��������Щ�����µĳɼ���...");
            int jiguangbuqiang, shoulai, daodan, zidan, buqiang, gang, tie, mei, waixinghejin, taihejin, huojiantong;
            jiguangbuqiang = rand() % 2 + 1; shoulai = rand() % 3 + 2; daodan = rand() % 3 + 1;
            zidan = rand() % 50 + 50; buqiang = rand() % 5 + 1; waixinghejin = rand() % 5 + 5;
            tie = rand() % 10 + 10; mei = rand() % 10 + 10; gang = rand() % 10 + 10;
            taihejin = rand() % 10 + 10, huojiantong = rand() % 2 + 1;
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "���ⲽǹ")
                {
                    bag[j].num += jiguangbuqiang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "��ǹ","���ⲽǹ",1000,0,0,jiguangbuqiang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "����")
                {
                    bag[j].num += shoulai;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","����",0,0,0,shoulai,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "����")
                {
                    bag[j].num += daodan;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","����",0,0,0,daodan,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "�ӵ�")
                {
                    bag[j].num += zidan;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","�ӵ�",0,0,0,zidan,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "���Ͳ")
                {
                    bag[j].num += huojiantong;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "��ǹ","���Ͳ",700,0,0,huojiantong,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "��ǹ")
                {
                    bag[j].num += buqiang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "��ǹ","��ǹ",300,0,0,buqiang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "��")
                {
                    bag[j].num += gang;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","��",0,0,0,gang,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "��")
                {
                    bag[j].num += tie;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","��",0,0,0,tie,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "ú")
                {
                    bag[j].num += mei;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","ú",0,0,0,mei,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "���ǺϽ�")
                {
                    bag[j].num += waixinghejin;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","���ǺϽ�",0,0,0,waixinghejin,false,0 };
                    break;
                }
            }
            for (int j = 0; j < 1000; j++)
            {
                if (bag[j].name == "�ѺϽ�")
                {
                    bag[j].num += taihejin;
                    break;
                }
                if (bag[j].name == "")
                {
                    bag[j] = { "����","�ѺϽ�",0,0,0,taihejin,false,0 };
                    break;
                }
            }
            MessageBox(0, TEXT("�㿴����Щ������ͻȻ����"), TEXT("��"), MB_OK);
            MessageBox(0, TEXT("����������ණ����"), TEXT("��"), MB_OK);
            canmakething[canmakethingi++] = "��";
            canmakething[canmakethingi++] = "����";
            canmakething[canmakethingi++] = "�ֵ�";
            canmakething[canmakethingi++] = "�ֽ�";
            canmakething[canmakethingi++] = "�ָ�";
            canmakething[canmakethingi++] = "�ָ�";
            canmakething[canmakethingi++] = "����";
            canmakething[canmakethingi++] = "������";
            canmakething[canmakethingi++] = "������";
            canmakething[canmakethingi++] = "������";
            canmakething[canmakethingi++] = "ǿ��ʯ��";
            canmakething[canmakethingi++] = "ǿ��ʯ��";
            canmakething[canmakethingi++] = "ǿ��ʯ��";
            canmakething[canmakethingi++] = "ľ��";
            canmakething[canmakethingi++] = "ʯ��";
            canmakething[canmakethingi++] = "����";
            canmakething[canmakethingi++] = "������";
            _getch();
        }
        if (f[y + movey[move]][x + movex[move]] == 'A')
        {
            f[y][x] = '.';
            return 0;
        }
        if (f[y + movey[move]][x + movex[move]] == '.')
        {
            f[y][x] = '.';
            f[y + movey[move]][x + movex[move]] = '@';
            y += movey[move];
            x += movex[move];
        }
    }
    return 0;
}
int weapon()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "��" || bag[i].type == "��" || bag[i].type == "��ǹ" || bag[i].type == "��ǹ")
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowweapon = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_axe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "��ͷ" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowaxe = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_pickaxe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "��" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowpickaxe = bag2[now];
            return 0;
        }
    }
    return 0;
}
int tool_hoe()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    thing bag2[1000];
    int bag2i = 0;
    for (int i = 0; bag[i].name != ""; i++)
    {
        if (bag[i].type == "��" && bag[i].num > 0)
        {
            bag2[bag2i] = bag[i];
            bag2i++;
        }
    }
    while (1)
    {
        system("cls");
        for (int i = 0; bag2[i].name != ""; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << bag2[i].name << "<";
            }
            else
            {
                cout << " " << bag2[i].name << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && bag2[now + 1].name != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            nowhoe = bag2[now];
            return 0;
        }
    }
    return 0;
}
string make()
{
    char c;
    int now = 0;
    bool isbag[1000] = { true, false };
    while (1)
    {
        system("cls");
        for (int i = 0; i < canmakethingi; i++)
        {
            if (isbag[i] == true)
            {
                cout << ">" << canmakething[i] << "<";
            }
            else
            {
                cout << " " << canmakething[i] << " ";
            }
            cout << endl;
        }
        c = _getch();
        if (c == 'w' && now > 0)
        {
            isbag[now] = false;
            isbag[now - 1] = true;
            now -= 1;
        }
        if (c == 's' && canmakething[now + 1] != "")
        {
            isbag[now] = false;
            isbag[now + 1] = true;
            now += 1;
        }
        if (c == 32)
        {
            return canmakething[now];
        }
    }
    return 0;
}
int make(string thi[100], int num[100], thing makething)
{
    bool all = true;
    for (int i = 0; thi[i] != ""; i++)
    {
        for (int j = 0; bag[j].name != ""; j++)
        {
            if (bag[j].name == thi[i])
            {
                all &= bag[j].num >= num[i];
            }
        }
    }
    if (all)
    {
        for (int i = 0; thi[i] != ""; i++)
        {
            for (int j = 0; bag[j].name != ""; j++)
            {
                if (bag[j].name == thi[i])
                {
                    bag[j].num -= num[i];
                }
            }
        }
        for (int j = 0; j < 1000; j++)
        {
            if (bag[j].name == makething.name)
            {
                bag[j].num++;
                break;
            }
            if (bag[j].name == "")
            {
                bag[j] = makething;
                break;
            }
        }
        cout << "�����ɹ�" << endl;
        return 1;
    }
    else
    {
        cout << "���ϲ���..." << endl;
        return 0;
    }
    return 0;
}
int main()
{
    srand((unsigned)time(NULL));
    welcome();
    start();
    while (1)
    {
        string a = outbutton();
        if (a == "����ɭ��")
        {
            system("cls");
            water = maxwater;
            if (isinto == false)
            {
                isinto = true;
                slowly("�����ɭ�֣��������ţ���������һ����õĸ�ͷ������һ�������");
                cout << endl;
                slowly("������ͷ����ϸ����һ���������⸫ͷ����ո�µģ�");
                cout << endl;
                cout << "\t������һ��ľ��";
                bag[bagi++] = { "��ͷ","ľ��",10,1,0,1,false,10,20 };
                _getch();
                cout << endl;
                slowly("��Ѹ�ͷ������...");
                Sleep(1000);
                way[0].b[way[0].bnum++] = "��ľ";
            }
            else
            {
                slowly("�����ɭ��");
                forest();
            }
        }
        else if (a == "����")
        {
            system("cls");
            outbag();
        }
        else if (a == "״̬")
        {
            system("cls");
            cout << "����:" << health << "/" << maxhealth << endl;
            cout << "������" << defense;
            cout << "����" << attack << "+" << nowweapon.attack << "(" << attack + nowweapon.attack << ")" << endl;
            cout << "װ��������";
            if (nowweapon.name != "") cout << nowweapon.name;
            else cout << "δװ��";
            cout << "     ʣ���;ã�" << nowweapon.durability << endl;
            cout << "װ����ͷ��";
            if (nowaxe.name != "") cout << nowaxe.name;
            else cout << "δװ��";
            cout << "     ʣ���;ã�" << nowaxe.durability << endl;
            cout << "װ���䣺";
            if (nowpickaxe.name != "") cout << nowpickaxe.name;
            else cout << "δװ��";
            cout << "     ʣ���;ã�" << nowpickaxe.durability << endl;
            cout << "װ������";
            if (nowhoe.name != "") cout << nowhoe.name;
            else cout << "δװ��";
            cout << "     ʣ���;ã�" << nowhoe.durability << endl;
            _getch();
        }
        else if (a == "��ľ")
        {
            if (nowaxe.name == "")
            {
                cout << "��δװ���Ÿ�ͷ...";
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 100;
                if (ran < 9)
                {
                    cout << "��������Ұ��" << endl;
                    _getch();
                    fight("Ұ��", 3000, 50, 5, 3000);

                }
                else
                {
                    ran = rand() % 7 + 3;
                    cout << "�ֵ���ɢ���ſ�֦��Ҷ" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "���ϵ������˼�����֦" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "ɭ��������һ�ô���" << endl;
                    Sleep((rand() % 10000 + 10000) / nowaxe.sharp);
                    cout << "\t������" << ran << "��ľͷ��" << endl;
                    _getch();
                    nowaxe.durability -= 1;
                    if (nowaxe.durability <= 0)
                    {
                        cout << "���ܲ��ң����ľ������..." << endl;
                        cout << "\t������һ�Ѹ�ͷ" << endl;
                        for (int i = 0; i < 1000; i++)
                        {
                            if (bag[i].name == nowaxe.name)
                            {
                                bag[i].num--;
                                break;
                            }
                        }
                        nowaxe = {};
                        _getch();
                    }
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == "ľͷ")
                        {
                            bag[i].num += ran;
                            break;
                        }
                        if (bag[i].name == "")
                        {
                            bag[i] = { "����","ľͷ",0,0,0,ran,false };
                            break;
                        }
                    }
                }
            }
        }
        else if (a == "װ��")
        {
            system("cls");
            cout << " _��ѡ��____________________________________________" << endl;
            cout << "|0���˳� 1������ 2����ľ���� 3���ڿ󹤾� 4���ֵع���|" << endl;
            cout << "|___________________________________________________|" << endl;
            string x;
            cin >> x;
            if (x == "1")weapon();
            if (x == "2")tool_axe();
            if (x == "3")tool_pickaxe();
            if (x == "4")tool_hoe();
        }
        else if (a == "����")
        {
            string t = make();
            if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 50,0 };
                thing makething = { "��","ľ��",50,0,0,1,false,10,20 };
                make(thi, num, makething);
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 50,0 };
                thing makething = { "��ͷ","ľ��",0,0,0,1,false,10,20 };
                make(thi, num, makething);
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 50,0 };
                thing makething = { "��","ľ��",0,0,0,1,false,10,20 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                            break;
                        }
                    }
                }
            }
            else if (t == "����̨")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 100,0 };
                thing makething = { "��Ʒ","����̨",0,0,0,1,false,0,100 };
                if (make(thi, num, makething))
                {
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "��ì";
                    canmakething[canmakethingi++] = "ľ��";
                    canmakething[canmakethingi++] = "ˮ��[����20]";
                    canmakething[canmakethingi++] = "ʯ��";
                    canmakething[canmakethingi++] = "ʯ��";
                    canmakething[canmakethingi++] = "ʯ��";
                    canmakething[canmakethingi++] = "ľ��";
                    canmakething[canmakethingi++] = "С��";
                    canmakething[canmakethingi++] = "Ƥ����";
                }
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 100,0 };
                thing makething = { "��Ʒ","����",0,0,0,1,false,0,100 };
                if (make(thi, num, makething))
                {
                    way[waynum++] = { "ɭ��",{"�鿴����"},1 };
                }
            }
            else if (t == "ʯ��")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 30,50 };
                thing makething = { "��","ʯ��",100,0,0,1,false,0,50 };
                make(thi, num, makething);
            }
            else if (t == "ʯ��")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 30,50 };
                thing makething = { "��ͷ","ʯ��",0,0,0,1,false,20,50 };
                make(thi, num, makething);
            }
            else if (t == "ʯ��")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 30,50 };
                thing makething = { "��","ʯ��",0,0,0,1,false,20,50 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "��ì")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 10,20 };
                thing makething = { "����","��ì",0,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "ˮ��[����20]")
            {
                string thi[100] = { "ľͷ","Ƥë" };
                int num[100] = { 5,50 };
                thing makething = { "ˮ��","ˮ��",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 20)
                    {
                        maxwater = 20;
                    }
                }
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 60,0 };
                thing makething = { "��","ľ��",75,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","Ƥ��" };
                int num[100] = { 60,45 };
                thing makething = { "��","ľ��",0,20,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ" };
                int num[100] = { 10 };
                thing makething = { "����","ľ��",0,0,0,5,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "Ƥ����")
            {
                string thi[100] = { "ľͷ","ľ��","ʯͷ","" };
                int num[100] = { 200,100,100,0,0 };
                thing makething = { "����","Ƥ����",0,0,0,1,false,0,0 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("��Ƥ����..."), TEXT("��"), MB_OK);
                    way[waynum++] = { "Ƥ����",{"����Ƥ��",},1 };
                }
            }
            else if (t == "С��")
            {
                string thi[100] = { "ľͷ","ľ��","ʯͷ","Ƥ��","" };
                int num[100] = { 200,100,100,75,0 };
                thing makething = { "����","С��",0,0,0,1,false,0,0 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("�����и�������Ϣ�ĵط���..."), TEXT("��"), MB_OK);
                    MessageBox(0, TEXT("�ҿ�����һЩ���õĶ�����..."), TEXT("��"), MB_OK);
                    way[waynum++] = { "С��",{"���",},1 };
                    canmakething[canmakethingi++] = "��ʯ";
                    canmakething[canmakethingi++] = "ʯ��";
                    canmakething[canmakethingi++] = "����ʯ��";
                    canmakething[canmakethingi++] = "����ʯ��";
                    canmakething[canmakethingi++] = "����ʯ��";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "ˮͰ[����30]";
                    canmakething[canmakethingi++] = "Ѭ�ⷿ";
                }
            }
            else if (t == "��ʯ")
            {
                string thi[100] = { "ʯͷ" };
                int num[100] = { 15,0 };
                thing makething = { "����","��ʯ",0,0,0,5,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "����ʯ��")
            {
                string thi[100] = { "ľͷ","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��","����ʯ��",160,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "����ʯ��")
            {
                string thi[100] = { "ľͷ","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��ͷ","����ʯ��",0,0,0,1,false,30,100 };
                make(thi, num, makething);
            }
            else if (t == "����ʯ��")
            {
                string thi[100] = { "ľͷ","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��","����ʯ��",0,0,0,1,false,30,100 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "������ì")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 5,10 };
                thing makething = { "����","��ì",0,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 200,50 };
                thing makething = { "��","����",200,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 200,50 };
                thing makething = { "��ͷ","����",0,0,0,1,false,50,150 };
                make(thi, num, makething);
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 200,50 };
                thing makething = { "��","����",0,0,0,1,false,50,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "ʯ��")
            {
                string thi[100] = { "ľͷ","��ʯ" };
                int num[100] = { 30,30 };
                thing makething = { "��","ʯ��",130,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 100,50 };
                thing makething = { "��","����",180,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "�ֵ�")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 100,50 };
                thing makething = { "��","�ֵ�",230,0,0,1,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "ˮͰ[����30]")
            {
                string thi[100] = { "ľ��","Ƥë","��ʯ" };
                int num[100] = { 50,50,100 };
                thing makething = { "ˮ��","ˮͰ",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 30)
                    {
                        maxwater = 30;
                    }
                }
            }
            else if (t == "Ѭ�ⷿ")
            {
                string thi[100] = { "ľ��","Ƥë","��ʯ" };
                int num[100] = { 100,50,100 };
                thing makething = { "����","Ѭ�ⷿ",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("�óԵ�Ѭ�⣬����������"), TEXT("��"), MB_OK);
                    way[nowway++] = { "Ѭ�ⷿ",{"��Ѭ��"},1 };
                }
            }
            else if (t == "ǿ��ʯ��")
            {
                string thi[100] = { "ľ��","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��","ǿ��ʯ��",250,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "ǿ��ʯ��")
            {
                string thi[100] = { "ľ��","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��ͷ","ǿ��ʯ��",0,0,0,1,false,40,120 };
                make(thi, num, makething);
            }
            else if (t == "ǿ��ʯ��")
            {
                string thi[100] = { "ľ��","��ʯ" };
                int num[100] = { 100,50 };
                thing makething = { "��","ǿ��ʯ��",0,0,0,1,false,40,120 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�ֽ�")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 100,50 };
                thing makething = { "��","�ֽ�",300,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "�ָ�")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 100,50 };
                thing makething = { "��ͷ","�ָ�",0,0,0,1,false,60,160 };
                make(thi, num, makething);
            }
            else if (t == "�ָ�")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 100,50 };
                thing makething = { "��","�ָ�",0,0,0,1,false,60,160 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "��")
            {
                string thi[100] = { "��","ú" };
                int num[100] = { 10,10 };
                thing makething = { "����","��",0,0,0,5,false,20,100 };
                make(thi, num, makething);
            }
            else if (t == "������")
            {
                string thi[100] = { "ľͷ","����" };
                int num[100] = { 200,50 };
                thing makething = { "��","������",250,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "������")
            {
                string thi[100] = { "ľͷ","����" };
                int num[100] = { 200,50 };
                thing makething = { "��ͷ","������",0,0,0,1,false,60,150 };
                make(thi, num, makething);
            }
            else if (t == "������")
            {
                string thi[100] = { "ľͷ","����" };
                int num[100] = { 200,50 };
                thing makething = { "��","������",0,0,0,1,false,60,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "ľ��")
            {
                string thi[100] = { "ľͷ","" };
                int num[100] = { 50,0 };
                thing makething = { "��","ľ��",0,0,0,1,false,10,20 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "�ֲ�")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "�ֲ�";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "ʯ��")
            {
                string thi[100] = { "ľͷ","ʯͷ" };
                int num[100] = { 20,50 };
                thing makething = { "��","ʯ��",0,0,0,1,false,20,50 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "�ֲ�")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "�ֲ�";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "����")
            {
                string thi[100] = { "ľͷ","��" };
                int num[100] = { 20,50 };
                thing makething = { "��","����",0,0,0,1,false,30,100 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "�ֲ�")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "�ֲ�";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "����")
            {
                string thi[100] = { "��","" };
                int num[100] = { 10 };
                thing makething = { "����","����",0,0,0,4,false,30,100 };
            }
            else if (t == "��ˮͰ[����40]")
            {
                string thi[100] = { "ľ��","Ƥë","��ʯ" };
                int num[100] = { 100,100,100 };
                thing makething = { "ˮ��","��ˮͰ",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 40)
                    {
                        maxwater = 40;
                    }
                }
            }
            else if (t == "������")
            {
                string thi[100] = { "ľ��","Ƥ��","��ʯ" };
                int num[100] = { 300,300,300 };
                thing makething = { "��Ʒ","������",0,0,0,1,false,0,200 };
                if (make(thi, num, makething))
                {
                    MessageBox(0, TEXT("�����ܺú���һЩ������..."), TEXT("��"), MB_OK);
                    canmakething[canmakethingi++] = "�ӵ�";
                    canmakething[canmakethingi++] = "��ǹ";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "ˮ��[����50]";
                    canmakething[canmakethingi++] = "����������";
                    canmakething[canmakethingi++] = "����������";
                    canmakething[canmakethingi++] = "����������";
                    canmakething[canmakethingi++] = "�;á�����";
                    canmakething[canmakethingi++] = "�;á�����";
                    canmakething[canmakethingi++] = "�������;á�����";
                    canmakething[canmakethingi++] = "�������;á�����";
                    canmakething[canmakethingi++] = "�������ֽ�";
                    canmakething[canmakethingi++] = "�������ָ�";
                    canmakething[canmakethingi++] = "�������ָ�";
                    canmakething[canmakethingi++] = "�;á��ָ�";
                    canmakething[canmakethingi++] = "�;á��ָ�";
                    canmakething[canmakethingi++] = "�������;á��ָ�";
                    canmakething[canmakethingi++] = "�������;á��ָ�";
                    canmakething[canmakethingi++] = "������";
                    canmakething[canmakethingi++] = "����";
                    canmakething[canmakethingi++] = "�ֺϽ�";
                }
            }
            else if (t == "����")
            {
                string thi[100] = { "��" };
                int num[100] = { 1 };
                thing makething = { "����","����",0,0,0,2,false,0,0 };
                make(thi, num, makething);
            }
            else if (t == "�ӵ�")
            {
                string thi[100] = { "��","���" };
                int num[100] = { 10,10 };
                thing makething = { "��ҩ","�ӵ�",0,0,0,10,true,0,1 };
                make(thi, num, makething);
            }
            else if (t == "��ǹ")
            {
                string thi[100] = { "��","��" };
                int num[100] = { 100,100 };
                thing makething = { "��ǹ","��ǹ",500,0,0,1,false,0,1 };
                make(thi, num, makething);
            }
            else if (t == "����")
            {
                string thi[100] = { "��","" };
                int num[100] = { 1 };
                thing makething = { "Ǯ","����",0,0,0,10,false,0,1 };
                make(thi, num, makething);
            }
            else if (t == "ˮ��[����50]")
            {
                string thi[100] = { "ľ��","Ƥë","��ʯ","����" };
                int num[100] = { 100,100,100,50 };
                thing makething = { "ˮ��","ˮ��",0,0,0,1,false,20,100 };
                if (make(thi, num, makething))
                {
                    if (maxwater < 50)
                    {
                        maxwater = 50;
                    }
                }
            }
            else if (t == "����������")
            {
                string thi[100] = { "����","����" };
                int num[100] = { 1,50 };
                thing makething = { "��","����������",350,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "����������")
            {
                string thi[100] = { "����","����" };
                int num[100] = { 1,50 };
                thing makething = { "��ͷ","����������",0,0,0,1,false,70,150 };
                make(thi, num, makething);
            }
            else if (t == "����������")
            {
                string thi[100] = { "����","����" };
                int num[100] = { 1,50 };
                thing makething = { "��","����������",0,0,0,1,false,70,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�;á�����")
            {
                string thi[100] = { "����","��" };
                int num[100] = { 1,100 };
                thing makething = { "��ͷ","�;á�����",0,0,0,1,false,60,200 };
                make(thi, num, makething);
            }
            else if (t == "�;á�����")
            {
                string thi[100] = { "����","��" };
                int num[100] = { 1,100 };
                thing makething = { "��","�;á�����",0,0,0,1,false,60,200 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�������;á�����")
            {
                string thi[100] = { "�;á�����","����" };
                int num[100] = { 1,50 };
                thing makething = { "��ͷ","�������;á�����",0,0,0,1,false,70,200 };
                make(thi, num, makething);
            }
            else if (t == "�������;á�����")
            {
                string thi[100] = { "�;á�����","����" };
                int num[100] = { 1,50 };
                thing makething = { "��","�������;á�����",0,0,0,1,false,70,200 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�������ֽ�")
            {
                string thi[100] = { "�ֽ�","�ֺϽ�" };
                int num[100] = { 1,50 };
                thing makething = { "��","�������ֽ�",400,0,0,1,false,0,100 };
                make(thi, num, makething);
            }
            else if (t == "�������ָ�")
            {
                string thi[100] = { "�ָ�","�ֺϽ�" };
                int num[100] = { 1,50 };
                thing makething = { "��ͷ","�������ָ�",0,0,0,1,false,80,150 };
                make(thi, num, makething);
            }
            else if (t == "�������ָ�")
            {
                string thi[100] = { "�ָ�","�ֺϽ�" };
                int num[100] = { 1,50 };
                thing makething = { "��","�������ָ�",0,0,0,1,false,80,150 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�;á��ָ�")
            {
                string thi[100] = { "�ָ�","��" };
                int num[100] = { 1,100 };
                thing makething = { "��ͷ","�;á��ָ�",0,0,0,1,false,70,230 };
                make(thi, num, makething);
            }
            else if (t == "�;á��ָ�")
            {
                string thi[100] = { "�ָ�","��" };
                int num[100] = { 1,100 };
                thing makething = { "��","�;á��ָ�",0,0,0,1,false,70,230 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�������;á��ָ�")
            {
                string thi[100] = { "�;á��ָ�","�ֺϽ�" };
                int num[100] = { 1,50 };
                thing makething = { "��ͷ","�������;á��ָ�",0,0,0,1,false,80,230 };
                make(thi, num, makething);
            }
            else if (t == "�������;á��ָ�")
            {
                string thi[100] = { "�;á��ָ�","�ֺϽ�" };
                int num[100] = { 1,50 };
                thing makething = { "��","�������;á��ָ�",0,0,0,1,false,80,230 };
                if (make(thi, num, makething))
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (way[0].b[i] == "��")
                        {
                            break;
                        }
                        if (way[0].b[i] == "")
                        {
                            way[0].b[i] = "��";
                            way[0].bnum++;
                        }
                    }
                }
            }
            else if (t == "�ֺϽ�")
            {
                string thi[100] = { "��","��" };
                int num[100] = { 5,5 };
                thing makething = { "����","�ֺϽ�",0,0,0,1,false,0,1 };
                make(thi, num, makething);
            }
        }
        else if (a == "�鿴����")
        {
            cout << "�ݴ�һ�㶯��" << endl;
            Sleep(rand() % 10000 + 1000);
            cout << "�����ж�������������" << endl;
            Sleep(rand() % 10000 + 1000);
            cout << "��������" << endl;
            Sleep(rand() % 10000 + 1000);
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "���⣡" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "��")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "ʳ��","��",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "Ƭ��Ƭ��" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "��Ƭ")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "��Ʒ","��Ƭ",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "ƬƤë��" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "Ƥë")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "����","Ƥë",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "Ƭ���ϣ�" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "����")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "����","����",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "�����ݣ�" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "����")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "����","����",0,0,0,ran,false };
                        break;
                    }
                }
            }
            if (rand() % 2)
            {
                int ran = rand() % 5;
                cout << "\t������" << ran << "��������" << endl;
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "����")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "����","����",0,0,0,ran,false };
                        break;
                    }
                }
            }
            _getch();
        }
        else if (a == "��")
        {
            if (nowpickaxe.name == "")
            {
                cout << "��δװ���Ÿ䰡..." << endl;
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 7 + 3;
                cout << "�飬����������ô���ʯ������" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "������ʯ��������" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "һ�����ʯ���ڵ���" << endl;
                Sleep((rand() % 10000 + 10000) / nowpickaxe.sharp);
                cout << "\t������" << ran << "����ʯ��" << endl;
                _getch();
                nowpickaxe.durability -= 1;
                if (nowpickaxe.durability <= 0)
                {
                    cout << "���ܲ��ң���ĸ����..." << endl;
                    cout << "\t������һ�Ѹ�" << endl;
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == nowpickaxe.name)
                        {
                            bag[i].num--;
                            break;
                        }
                    }
                    nowpickaxe = {};
                    _getch();
                }
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "ʯͷ")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "����","ʯͷ",0,0,0,ran,false };
                        break;
                    }
                }
            }
        }
        else if (a == "��Ѭ��")
        {
            string thi[100] = { "��","ľͷ" };
            int num[100] = { 5,5 };
            thing makething = { "ʳ��","Ѭ��",0,0,0,1,false,0,10 };
            make(thi, num, makething);
        }
        else if (a == "����Ƥ��")
        {
            string thi[100] = { "Ƥë","" };
            int num[100] = { 5,0 };
            thing makething = { "����","Ƥ��",0,0,0,1,false,0,10 };
            make(thi, num, makething);
        }
        else if (a == "���")
        {
            for (int i = 0; i < 1000; i++)
            {
                if (bag[i].name == "ľͷ")
                {
                    bag[i].num--;
                }
            }
            cout << "����ů��...";
        }
        else if (a == "�ֲ�")
        {
            if (nowhoe.name == "")
            {
                cout << "��δװ���ų���..." << endl;
                Sleep(1000);
            }
            else
            {
                int ran = rand() % 20 + 10;
                cout << "�ֲ���...    ���Ե�" << endl;
                Sleep((rand() % 30000 + 30000) / nowhoe.sharp);
                cout << "\t������" << ran << "��Ұ�ˣ�" << endl;
                _getch();
                nowhoe.durability -= 1;
                if (nowhoe.durability <= 0)
                {
                    cout << "���ܲ��ң���ĳ�����..." << endl;
                    cout << "\t������һ�ѳ�" << endl;
                    for (int i = 0; i < 1000; i++)
                    {
                        if (bag[i].name == nowhoe.name)
                        {
                            bag[i].num--;
                            break;
                        }
                    }
                    nowhoe = {};
                    _getch();
                }
                for (int i = 0; i < 1000; i++)
                {
                    if (bag[i].name == "Ұ��")
                    {
                        bag[i].num += ran;
                        break;
                    }
                    if (bag[i].name == "")
                    {
                        bag[i] = { "ʳ��","Ұ��",0,0,0,ran,false };
                        break;
                    }
                }
            }
        }
        else if (a == "�����䷽")
        {
            system("start https://paste.ubuntu.com/p/sm2MWhTXqh/");
        }
        health = maxhealth;
    }
    return 0;
}


//�����߸��¼ƻ���
/*
���ְҵ���ֵ�����;+ 


*/
